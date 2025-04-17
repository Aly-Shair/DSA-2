vector<int> diagonal(Node *root)
{
   vector <int> diagonal;
   if(root==NULL) return diagonal;
   
   queue <Node *> q;
   q.push(root);
   
   while(!q.empty()){
       Node *temp = q.front();
       q.pop();
       
       while(temp!=NULL){
           diagonal.push_back(temp->data);
           q.push(temp->left);
           
           temp = temp->right;
       }
   }
   return diagonal;
}

vector<int> diagonal(Node *root)
{
 vector<int> ans;
 if(!root) return ans;
 queue<Node*> q;
 q.push(root);
 while(!q.empty()){
     Node* temp = q.front();
     q.pop();
     while(temp){
         ans.push_back(temp->data);
         if(temp->left) q.push(temp->left);
         temp = temp->right;
     }
 }
 return ans;
}
