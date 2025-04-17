//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{   
    bool matches(char top, char braces){
        if(top == '(' && braces == ')' || top == '[' && braces == ']' || top == '{' && braces == '}')
            return true;
        else
            return false;
    }
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        s.push(x[0]);
        
        for(int i = 1; i < x.size(); i++){
            if(!s.empty() && matches(s.top(), x[i])){ 
                s.pop();
            }else{
                s.push(x[i]);
            }
        } 
        
        if(s.empty())
            return true;
        else
            return false;
    }

};

class Solution_2{
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
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
