void insertAtBottom_1(stack<int>& s, int x)
{
	if(s.empty())
	{
		s.push(x);
		return;
	}
	int top = s.top();
	s.pop();
	pushBottom(s, x);
	s.push(top);
}

stack<int> insertAtBottom_2(stack<int> &s,int x)
{
	if(s.empty())
	{
		s.push(x);
		return s;
	}

	int top = s.top();
	s.pop();
	insertAtBottom(s, x);
	s.push(top);

	return s;
}
