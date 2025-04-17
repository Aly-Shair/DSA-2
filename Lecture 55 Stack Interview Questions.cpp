#include<iostream>
#include<string>
#include<stack>
using namespace std;

void removerMidElementInStack(stack<int>& s, int count, int size)
{
	if(count == (size/2))
	{
		s.pop();
		return;
	}
	int num = s.top();
	s.pop();
	removerMidElementInStack(s, count+1, size);
	s.push(num);
}
void deleteMid(stack<int>& s)
{
	int count = 0;
	int size = s.size();
	removerMidElementInStack(s, count, size);
}


bool matches(char top, char c)
{
	if(top == '(' && c == ')')
		return true;
	else if(top == '{' && c == '}')
		return true;
	else if(top == '[' && c == ']')
		return true;
	return false;
}

bool validParentesis(string str)
{
	stack<char> s;
	for(int i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if(c == '(' || c == '{' || c == '[')
		{
			s.push(c);
		}
		else
		{
			if(!s.empty())
			{
				char top = s.top();
				if(matches(top, c))
				{
					s.pop();
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	if(s.empty())
		return true;
}

void pushBottom(stack<int>& s, int x)
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
void reverseStack(stack<int>& s)
{
	if(s.empty())
	{
		return;
	}
	int top = s.top();
	s.pop();
	reverseStack(s);
	pushBottom(s, top);
}

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

bool validExpression(string str)
{
	int count = 5;
	stack<char>s;
	for(int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		if(ch != ')')
		{
			s.push(ch);
			if(ch == '(')
				count = 0;
		}
		else if(ch == ')')
		{
			count = 0;
			if(!s.empty())
			{
				char top = s.top();
				while(top != '(' and !s.empty())
				{
					s.pop();
					if(!s.empty())
					{
						top = s.top();
					}
					else
					{
						return false;
					}
					count++;
				}
				if(matches(top, ch))
				{
					s.pop();
					count++;
				}
				if(count < 2)
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
	}
	if(s.empty() or count >= 2)
		return true;
	return false;
}
bool isRedundBracket(string str)
{
//	Time complexity O(n)
	stack<char>s;
	for(int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			s.push(ch);
		}
		else
		{
			if(ch == ')')
			{
				bool isRedundant = true;
				while(s.top() != '(')
				{
					char top = s.top();
					if(top == '+' || top == '-' || top == '*' || top == '/')
					{
						isRedundant = false;
					}
					s.pop();
				}
				if(isRedundant)
				{
					return true;
				}
				s.pop();
			}
		}
	}
}

//	valid parenthsis string
/*
	--> {{{{{{
	--> }}}}}}
	--> }}}{{{
	ans = ((a+1)/2) + ((b+1)/2)
*/
int stringValid(string str)
{
	if(str.length()%2 != 0)
	{
		return -1;
	}
	stack<char>s;
	for(int i = 0; i < str.length(); i++)
	{
		char ch = str[i];
		if(ch == '{')
		{
			s.push(ch);
		}
		else
		{
			if(!s.empty() && s.top() == '{')
			{
				s.pop();
			}
			else
			{
				s.push(ch);
			}
		}
	}
	int open = 0, close = 0;
	while(!s.empty())
	{
		if(s.top() == '{')
		{
			open++;
		}
		else
		{
			close++;
		}
		s.pop();
	}
	int ans = (open+1)/2 + (close + 1)/2;
	return ans;
}
int main()
{
	/*
	//	Q: reverse string
	stack<char>s;
	string str = "Ali Shair";
	for(int i = 0; i < str.length(); i++){
		char c = str[i];
		s.push(c);
	}
	string ans = "";
	while(!s.empty()){
		char c = s.top();
		ans.push_back(c);
		s.pop();
	}
	cout<<"Answer is: "<<ans<<endl;
	*/
	/*
	//	Q: remove middle element in stack
	stack<int>s;
	int arr[5] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; i++){
		s.push(arr[i]);
	}

	//	for(int i = 0; i < 5; i++){
	//		cout<<s.top()<<endl;
	//		s.pop();
	//	}

	deleteMid(s);

	cout<<"After removing middle element"<<endl;

	for(int i = 0; i < 4; i++){
		cout<<s.top()<<endl;
		s.pop();
	}
	*/
	/*
	Q: 3 valid parenthesis? Time complexity O(n) Space complexity O(n)
	cout<<boolalpha<<validParentesis("({[]}){}");
	*/
	/*
	//	Q: push at bottom
	stack<int>s;
	int arr[5] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; i++){
		s.push(arr[i]);
	}
	pushBottom(s, 0);
	for(int i = 0; i < 6; i++){
		cout<<s.top()<<endl;
		s.pop();
	}
	*/
	/*
	//	Q: reverse stack using recursion Time complexity O(n^2)
	stack<int>s;
	int arr[5] = {1, 2, 3, 4, 5};
	for(int i = 0; i < 5; i++) {
		s.push(arr[i]);
	}
	reverseStack(s);
	for(int i = 0; i < 5; i++) {
		cout<<s.top()<<endl;
		s.pop();
	}
	*/
	/*
	//	Q: sort a stack Time complexity O(n^2)
	stack<int>s;
	int arr[5] = {6, -2, 5, -3, 9};
	for(int i = 0; i < 5; i++) {
		s.push(arr[i]);
	}
	sortStack(s);
	for(int i = 0; i < 5; i++) {
		cout<<s.top()<<endl;
		s.pop();
	}
	*/
//	cout<<boolalpha<<validExpression("((aa)*(aa))");
	cout<<stringValid("{{{{}}}}{}");
	return 0;
}
