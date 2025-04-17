//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		char str[10000];
		cin>>str;
		long long int len=strlen(str);
		char *ch=reverse(str,len);
		for(int i=0; i<len; i++)
		{
			cout<<ch[i];
		}
		cout<<endl;
	}
	return 0;
}


// } Driver Code Ends


//return the address of the string
char* reverse_1(char *S, int len)
{
	stack<char> s;

	char* ptr = S;

	for(int i = 0; i < len; i++)
	{
		s.push(*ptr);
		ptr++;
	}

	string ans = "";
	ptr = S;

	while(!s.empty())
	{
		*ptr = (s.top());
		ptr++;
		s.pop();
	}
	return S;
}

char* reverseFaulted(char *S, int len)
{

	/*
	The main issue is that str is a local variable inside the reverse function. When you return a pointer to this local variable (char* ans = &str[0];), it points to memory that is no longer valid once the function ends, leading to undefined behavior.
	*/
	stack<char> s;

	char* ptr = S;

	for(int i = 0; i < len; i++)
	{
		s.push(*ptr);
		ptr++;
	}

	string str = "";

	while(!s.empty())
	{
		str.push_back(s.top());
		s.pop();
	}

	char* ans = &str[0];

	return ans;
}

string str; // declare str globally
char* reverseCorrectionFaulted(char *S, int len)
{

	stack<char> s;

	char* ptr = S;

	for(int i = 0; i < len; i++)
	{
		s.push(*ptr);
		ptr++;
	}

	str = "";

	while(!s.empty())
	{
		str.push_back(s.top());
		s.pop();
	}

	char* ans = &str[0];

	return ans;
}

char* reverse3(char *S, int len)
{
	stack<char> s;

	for(int i = 0; i < len; i++)
	{
		s.push(S[i]);
	}

	string str = "";

	for(int i = 0; i < len; i++)
	{
		S[i] = s.top();
		s.pop();
	}

	char* ans = &str[0];

	return S;
}
