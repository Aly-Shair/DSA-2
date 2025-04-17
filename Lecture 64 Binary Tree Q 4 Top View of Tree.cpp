// https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
   
    vector<int> topView(Node* root)
    {
        vector<int> ans;
        map<int, int> m;
        queue<pair<Node*, int> > q;
        if(!root)
            return ans;
       
        q.push(make_pair(root, 0));
        
        while(!q.empty()){
            pair<Node*, int> temp = q.front();
            q.pop();
            
            Node* curr = temp.first;
            int hd = temp.second;
            
            if(!m[hd]){
                m[hd] = curr->data;
            }
            /*
            // alternative to above condition
            if(m.find(hd) == m.end()){
            	m[hd] = curr->data;
			}
			*/
            if(curr->left)
                q.push(make_pair(curr->left, hd-1));
            if(curr->right)
                q.push(make_pair(curr->right, hd+1));
        }
        
        for(auto i : m){
                ans.push_back(i.second);
        }
        return ans;
    }

};
