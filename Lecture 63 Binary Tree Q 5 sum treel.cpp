class Solution
{
    public:
    pair<bool, int> isSumTreeFast(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        if(root->left == NULL and root->right == NULL){
             pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        pair<bool, int> left = isSumTreeFast(root->left);
        pair<bool, int> right = isSumTreeFast(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        int condtion = root->data == left.second + right.second;
        pair<bool, int> ans;
        if(leftAns and rightAns and condtion){
            ans.first = true;
            ans.second = 2*root->data;
        }else{
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
         return isSumTreeFast(root).first;
    }
};
