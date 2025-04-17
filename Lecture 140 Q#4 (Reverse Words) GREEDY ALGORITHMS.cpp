/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' 


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1 <= |S| <= 105
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution // https://www.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        
        string ans = "", temp = "";
        
        for(int i = S.size()-1; i >= 0; i--){
            if(S.at(i) == '.'){
               reverse(temp.begin(), temp.end());
               ans += temp+'.';
               
               temp = "";
                
            }else{
               temp.push_back(S[i]); 
            }
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
