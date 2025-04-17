// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, map<int,vector<int> > > nodes;
        queue< pair<Node*, pair<int,int> > > q;
        vector<int> ans;
        
        if(root == NULL)
            return ans;
            
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()) {
            pair<Node*, pair<int,int> > temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }
        
        for(auto i: nodes) {
            
            
            for(auto j:i.second) {
                
                for(auto k:j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};




vector<int> verticalOrder(Node *root)
    {
        map<int,vector<int>> mp;
        queue<pair<Node*,int>> q;
        vector<int> ans;
        if(!root)
        return ans;

        q.push(make_pair(root,0));
        while(!q.empty())
        {                                                                             
            pair<Node*,int> front = q.front();
            q.pop();
            
            Node *curr = front.first;
            int hd = front.second;
            
            mp[hd].push_back(curr->data); //  map will store data in sorted order according to key;
            
            if(curr->left)
            q.push(make_pair(curr->left,hd-1));
            if(curr->right)
            q.push(make_pair(curr->right,hd+1));
        }
         for(auto it: mp)
        {
            for(auto i : it.second)
            {
                ans.push_back(i);
            }
        }
        return ans;
}

/*
int main(){
	map<string, vector<int> > marks;
	marks["Ali Shair"].push_back(3);
	map<string, vector<int> > :: iterator itr;
	itr = marks.begin();
	for(itr = marks.begin(); itr != marks.end(); itr++){
		cout<<itr->first<<" "<<itr->second.at(0)<<endl;
	}
	return 0;
}
*/
/*
int main(){
	map<int, string> m;
	m[0] = "ali shair";
	m[1] = "Hello World";
	m.insert({-2, "HaHaHa"});
	map<int, string> :: iterator iter;
	iter = m.begin();
	for(iter = m.begin(); iter != m.end(); iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	return 0;
}
*/
