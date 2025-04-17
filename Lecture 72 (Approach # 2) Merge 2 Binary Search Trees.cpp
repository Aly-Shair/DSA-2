void  BST2LL(Node* root, Node* &head){ // bst to sorted linked list
	if(!root){
		return;
	}
	
	BST2LL(root->right, head);
	
		root->right = head;
		
		if(head){
			head->left = root;
		}
		
		head = root;

	 BST2LL(root->left, head);
}

Node* sortedMerge(Node* head1, Node* head2){ // merge two sorted linked lists  
    Node* n = new Node(-1);
    Node* temp = n;
    while(head1 and head2){
        if(head1->data < head2->data){
            temp->next = head1;
            head1 = head1->next;
        }else{
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    
    while(head1){
        temp->next = head1;
        head1 = head1->next;
        temp = temp->next;
    }
    
    while(head2){
        temp->next = head2;
        head2 = head2->next;
        temp = temp->next;
    }
    
    return n->next;
} 

void LLToBST(Node* &head, int n){
	if(n <= 0 or !head)
		return nullptr;
		
	Node* Left = LLToBST(head, n/2);
	
	Node* root = head;
	
	root->left = Left;
	
	head = head->next;
	
	root->right = LLToBST(head, n-(n/2)-1);
	
	return root;
}
