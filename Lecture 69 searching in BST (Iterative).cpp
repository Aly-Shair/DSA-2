bool search(Node* root, int val){ // T.C => O(log(n)) and S.C => O(H)

    Node* temp = root;
    
    while(temp){
        if(temp->data == val){
            return true;
        }else if(temp->data > val){
            temp = temp->left;
        }else if(temp->data < val){
            temp = temp->right;
        }
    }
    return false;
	
}
