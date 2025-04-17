class Solution // https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
{
    void inorder(Node* root, vector<int> &bst){
        if(!root)
            return;
            
        inorder(root->left, bst);
        bst.push_back(root->data);
        inorder(root->right, bst);
    }
    
   vector<int> mergeBST(vector<int> bst1, vector<int> bst2){
        vector<int> ans(bst1.size() + bst2.size());
        int i = 0, j = 0, k = 0;
        while(i < bst1.size() and j < bst2.size()){
            if(bst1[i] < bst2[j]){
               ans[k++] = bst1[i];
               i++;
            }else{
                ans[k++] = bst2[j];
                j++;
            }
        }
        
        while(i < bst1.size()){
           ans[k++] = bst1[i];
            i++;
        }
        
        while(j < bst2.size()){
            ans[k++] = bst2[j];
            j++;
        }
        
        return ans;
    }
    
    Node* inorderToBST(vector<int> &inorder, int s, int e){
    	if(s > e){
    		return nullptr;
		}
		
		int min = (s+e)/2;
		Node* root = new Node*(inorder[mid]);
		root->left = inorderToBST(inorder, s, mid-1);
		root->left = inorderToBST(inorder, mid+1, e);
		return root;
	}
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    Node* merge(Node *root1, Node *root2)
    {
       vector<int> bst1;
       vector<int> bst2;
       inorder(root1, bst1);
       inorder(root2, bst2);
       
       vector<int> mergedBST = mergeBST(bst1, bst2);
       
       int s = 0, e = mergedBST.size()-1;
       
       Node* root = inorderToBST(s, e, mergedBST);
       
       return root;
    }
};
