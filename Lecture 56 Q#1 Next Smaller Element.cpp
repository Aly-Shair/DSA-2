#include<iostream>
#include<stack>
#include<vector>
using namespace std;


void nextSmallerElement(int arr[], int n)
{
	stack<int> s;
	s.push(-1);
	int ans[n];
	for(int i = n-1; i >= 0; i--)
	{
		int curr = arr[i];
		while(s.top() >= curr)
		{
			s.pop();
		}
		ans[i] = s.top();
		s.push(curr);
	}
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	while(!s.empty())
	{
		cout<<s.top()<<endl;;
		s.pop();
	}
}

void previousSmallerElement(int arr[], int n)
{
	stack<int> s;
	s.push(-1);
	int ans[n];
	for(int i = 0; i < n; i++)
	{
		int curr = arr[i];
		while(s.top() >= curr)
		{
			s.pop();
		}
		ans[i] = s.top();
		s.push(curr);
	}
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	while(!s.empty())
	{
		cout<<s.top()<<endl;;
		s.pop();
	}
}

vector<long long> previousPoint(long long heights[], int n){
	stack<long long> s;
	vector<long long> ans(n);
	s.push(-1);
	for(long long i = 0; i < n; i++){
		long long curr = heights[i];
		while(s.top() != -1 && heights[s.top()] >= curr){
			s.pop();
		}
		ans[i] = s.top();
		s.push(i);
	}
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return ans;
}
vector<long long> nextPoint(long long heights[], long long n){
	stack<long long> s;
	vector<long long> ans(n);
	s.push(-1);
	for(long long i = n-1; i >= 0; i--){
		long long curr = heights[i];
		while(s.top() != -1 && heights[s.top()] >= curr){
			s.pop();
		}
		ans[i] = s.top();
		s.push(i);
	}
	for(int i = 0; i < n; i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return ans;
}

int main()
{

//	int arr[4] = {2, 1, 4, 3};
//	int arr[6] = {2, 1, 5, 6, 3, 2};
//	nextSmallerElement(arr, 6);
//	previousSmallerElement(arr, 6);
	
	
	long long arr[6] = {2, 1, 5, 6, 3, 2};
	nextPoint(arr, 6);
	previousPoint(arr, 6);

	return 0;
}
