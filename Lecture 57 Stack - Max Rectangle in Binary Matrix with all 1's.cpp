#include<iostream>
#include<stack>
#include<climits>
using namespace std;

int* previousPoint(int arr[], int n){
	stack<int> s;
	s.push(-1);
	int* ans = new int[n];
	for(int i = 0; i < n; i++){
		int curr = arr[i];
		while(s.top() != -1 && arr[s.top()] >= curr){
			s.pop();
		}
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

int* nextPoint(int arr[], int n){
	stack<int> s;
	s.push(-1);
	int* ans = new int[n];
	for(int i = n-1; i >= 0; i--){
		int curr = arr[i];
		while(s.top() != -1 && arr[s.top()] >= curr){
			s.pop();
		}
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

int largestAreaInHistogram(int* arr, int n){
	int* pre = previousPoint(arr, n);
	int* next = nextPoint(arr, n);	
	int area = INT_MIN;
	for(int i = 0; i < n; i++){
		int l = arr[i];
		if(next[i] == -1){
			next[i] = n;
		}
		int b = next[i] - pre[i] - 1;
		int newArea = l*b;
		area = max(area, newArea);
	}
	return area;
}

int maxArea(int M[][4], int n, int m){
	int area = largestAreaInHistogram(M[0], m);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < m; j++){
			if(M[i][j] != 0){
				M[i][j] = M[i][j] + M[i-1][j];	
			} else{
				M[i][j] = 0;
			}
		}
		area = max(area, largestAreaInHistogram(M[i], m));
	}
	return area;
}

int main(){

	int n = 4, m = 4;
	int M[n][4] = {
					{0,1,1,0},
					{1,1,1,1},
					{1,1,1,1},
					{1,1,0,0}
				  };
				  
	cout<<maxArea(M, n, m);
	
	return 0;
}
