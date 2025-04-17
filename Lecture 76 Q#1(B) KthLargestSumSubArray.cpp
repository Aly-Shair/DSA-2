//Approach # 2
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        
        priority_queue<int, vector<int>, greater<int> > minHeap;
        
        for(int i = 0; i < N; i++){
            int sum = 0;
            for(int j = i; j < N; j++){
                sum += Arr[j];
                
                if(minHeap.size() < K){
                    minHeap.push(sum);
                }
                else if(sum > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
        
        return minHeap.top();
    }
};

//{ Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends
