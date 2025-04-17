class Solution
{
		int solveSO(int *nums,int  n)
		{

			int prev_2 = 0;
			int prev_1 = nums[0];

			for(int i = 1; i < n; i++)
			{
				int include = prev_2 + nums[i];
				int exclude = prev_1 + 0;

				int ans = max(include, exclude);
				prev_2 = prev_1;
				prev_1 = ans;
			}

			return prev_1;

		}
	public:
		// calculate the maximum sum with out adjacent
		int houseRobberyProblem(int* arr, int n)
		{	
			if(n == 0)
				return 0;
			
			if(n == 1)
				return arr[0];
				
			return max(solveSO(arr+1, n-1), solve(arr, n-1));
		}
};

class Solution
{
		int solveSO(vector<int> &nums,int  n)
		{

			int prev_2 = 0;
			int prev_1 = nums[0];

			for(int i = 1; i < n; i++)
			{
				int include = prev_2 + nums[i];
				int exclude = prev_1 + 0;

				int ans = max(include, exclude);
				prev_2 = prev_1;
				prev_1 = ans;
			}

			return prev_1;

		}
	public:
		// calculate the maximum sum with out adjacent
		int houseRobberyProblem(int* arr, int n)
		{	
			if(n == 0)
				return 0;
			
			if(n == 1)
				return arr[0];
			
			
			vector<int> first(n-1);
			vector<int> second(n-1);
			
			for(int i = 0; i < n; i++){
				if(i != n-1)
					first.push_back(arr[i]);
				if(i != 0)
					second.push_back(arr[i]);
			}
			
			return max(solveSO(first, n-1), solve(second, n-1));
		}
};
