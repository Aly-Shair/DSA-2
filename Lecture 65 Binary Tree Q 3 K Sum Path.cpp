#include<iostream>
using namespace std;
 // https://www.geeksforgeeks.org/problems/k-sum-paths/1
 
 class Solution{
  public:
    void solve(Node* root, int &count, int k, vector<int> path){
        if(root == NULL){
            return;
        }
        path.push_back(root->data);
        solve(root->left, count, k, path);
        solve(root->right, count, k, path);
        int sum = 0;
        for(int i = path.size()-1; i >= 0; i--){
            sum += path[i];
            if(sum == k){
                count++;
            }
        }
        path.pop_back();
    }
    int sumK(Node *root,int k)
    {   
        vector<int> path;
        int count = 0;
        solve(root, count, k, path);
        return count;
    }
};
 
int main(){
	cout<<"https://www.geeksforgeeks.org/problems/k-sum-paths/1";
	return 0;
}
