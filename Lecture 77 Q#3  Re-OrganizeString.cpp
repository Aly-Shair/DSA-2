#include<bits/stdc++.h>
using namespace std;



int main(){
	/*arrange characters based on their ascii code*/
	/*
	priority_queue<char> maxHeap;
	maxHeap.push('D');
	maxHeap.push('C');
	maxHeap.push('B');
	maxHeap.push('A');
	
	cout<<maxHeap.top();
	maxHeap.pop();
	
	cout<<maxHeap.top();
	maxHeap.pop();
	
	cout<<maxHeap.top();
	maxHeap.pop();
	
	cout<<maxHeap.top();
	maxHeap.pop();
	*/
	
	/*
	priority_queue<char, vector<char>, greater<char> > minHeap;
	minHeap.push('D');
	minHeap.push('C');
	minHeap.push('B');
	minHeap.push('A');
	minHeap.push('A');
	
	cout<<minHeap.top();
	minHeap.pop();
	
	cout<<minHeap.top();
	minHeap.pop();
	
	cout<<minHeap.top();
	minHeap.pop();
	
	cout<<minHeap.top();
	minHeap.pop();
	
	cout<<minHeap.top();
	minHeap.pop();
	*/
	
//	string s = "abc";
//	int sum = 5;
//	char c = 'z';
//	s.push_back(c);
//	cout<<s;
//	int e = '5' - '0';
//	cout<<e;
//	return 0;
//}

/*
Given a string containing uppercase alphabets and integer digits (from 0 to 9), the task is to print the alphabets in the lexicographical order followed by the sum of digits.

Example 1:

Input: S = "AC2BEW3"
Output: "ABCEW5"
Explanation: 2 + 3 = 5 and we print all
alphabets in the lexicographical order. 
Example 2:

Input: S = "ACCBA10D2EW30"
Output: "AABCCDEW6"
Explanation: 0+1+2+3 = 6 and we print all
alphabets in the lexicographical order. 

Your Task:  
You don't need to read input or print anything. Your task is to complete the function arrangeString() which takes the string S as inputs and returns the modified string.

Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(26)

Constraints:
1 = |S| = 105
S contains only upper case alphabets and digits.
*/

class Solution // https://www.geeksforgeeks.org/problems/rearrange-a-string4100/1 
{
  public:
    string arrangeString(string str)
    {
        priority_queue<char, vector<int>, greater<int> > minHeap;
        int sum = 0;
        
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3'|| str[i] == '4'|| str[i] == '5'|| str[i] == '6'|| str[i] == '7' || str[i] == '8' || str[i] == '9'){
                int element = str[i] - '0';
                sum += element;
            }else{
                minHeap.push(str[i]);
            }
        }
        
        string ans = "";
        
        while(!minHeap.empty()){
            ans.push_back(minHeap.top());
            minHeap.pop();
        }
        
        if(sum){
            string num = to_string(sum);
        	ans += num;
//        for(int i = 0; i < num.size(); i++){
//            
//            char c = num[i];
//                ans.push_back(c);
//            
//        }   
        }
        
        
        
        return ans;
        
    }
};
