#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include <algorithm>

using namespace std;


int largestAreaInHistogram(int height[], int n)
{
	stack<int> s;
	int maxArea = 0;

	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() &&  height[i] < height[s.top()])
		{
			int h = height[s.top()];
			s.pop();
			int w = s.empty() ? i : i - s.top() - 1;
			maxArea = max(maxArea, h * w);
		}
		s.push(i);
	}

	while (!s.empty())
	{
		int h = height[s.top()];
		s.pop();
		int w = s.empty() ? n : n - s.top() - 1;
		maxArea = max(maxArea, h * w);
	}

	return maxArea;
}

int main()
{
	
	int heights[6] = {2, 1, 5, 6, 2, 3};
	cout<<largestAreaInHistogram(heights, 6);
	
	return 0;
}
