#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> previousPoint(vector<int> heights, int n){
	stack<int> s;
	vector<int> ans(n);
	s.push(-1);
	for(int i = 0; i < n; i++){
		int curr = heights[i];
		while(s.top() != -1 && heights[s.top()] >= curr){
			s.pop();
		}
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}
vector<int> nextPoint(vector<int> heights, int n){
	stack<int> s;
	vector<int> ans(n);
	s.push(-1);
	for(int i = n-1; i >= 0; i--){
		int curr = heights[i];
		while(s.top() != -1 && heights[s.top()] >= curr){
			s.pop();
		}
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}
int largestAreaInHistogram(vector<int> heights, int n){
	vector<int> pre, next;
	pre = previousPoint(heights, n);
	next = nextPoint(heights, n);
	int area;
	for(int i = 0; i < n; i++){
		int h = heights[i];
		if(next[i] == -1){
			next[i] = n;
		}
		int w = next[i] - pre[i] - 1;
		int newArea = h*w;
		area = max(newArea, area);
	}
	return area;
}

int main(){
	
	int element, size;
	cin>>size;
	vector<int> v;
	for(int i = 0; i < size; i++){
		cin>>element;
		v.push_back(element);
	}
	cout<<largestAreaInHistogram(v, size);
	
	return 0;
}
