
//Approach # 1 // using bubble sort
void SortedStack :: sort()
{
	vector<int> vec;

	while(!s.empty())
	{
		int top = s.top();
		s.pop();
		vec.push_back(top);
	}

	int n = vec.size();
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (vec[j] > vec[j + 1])
			{
				// Swap vec[j] and vec[j+1]
				int temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}

	for(int i = 0; i < vec.size(); i++)
	{
		s.push(vec[i]);
	}
}

//Approach # 2 // Sort using temp stack
stack<int> sortStack(stack<int> &input)
{
	stack<int> tmpStack;

	while (!input.empty())
	{
		// pop out the first element
		int tmp = input.top();
		input.pop();

		// while temporary stack is not empty and top
		// of stack is lesser than temp
		while (!tmpStack.empty() && tmpStack.top() < tmp)
		{
			// pop from temporary stack and push
			// it to the input stack
			input.push(tmpStack.top());
			tmpStack.pop();
		}

		// push temp in temporary of stack
		tmpStack.push(tmp);
	}

	return tmpStack;
}

//Approach # 3 // using recursion
void pushSortedly(stack<int>& s, int x)
{
	if(s.empty() || s.top() < x)
	{
		s.push(x);
		return;
	}
	int top = s.top();
	s.pop();
	pushSortedly(s, x);
	s.push(top);
}
void sortStack(stack<int>& s)
{
	if(s.empty())
	{
		return;
	}
	int top = s.top();
	s.pop();
	sortStack(s);
	pushSortedly(s, top);
}
