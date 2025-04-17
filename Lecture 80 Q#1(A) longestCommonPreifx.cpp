//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{ // https://www.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        string ans = "";
        bool match;
        
        for(int i = 0; i < arr[0].size(); i++){
            char ch = arr[0][i];
            
            match = true;
            
            for(int j = 1; j < N; j++){
                if(arr[j].size() < i or arr[j][i] != ch){
                    match = false;
                    break;
                }
            }
            
            if(match == false){
                break;
            }else{
                ans.push_back(ch);
            }
        }
        if(ans != "")
            return ans;
        else
            return "-1";
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
