class TwoStacks{
	int size;
	int *arr;
	int top_1;
	int top_2;
	public:
	TwoStacks(){}
	TwoStacks(int size){
		this->size = size;
		arr = new int[size];
		top_1 = -1;
		top_2 = size;
	}
	void push_1(int element){
		if(top_2 - top_1 > 1){
			top_1++;
			arr[top_1] = element;
		}else{
			cout<<"stack 1 is overflow"<<endl;
		}
	}
	void push_2(int element){
		if(top_2 - top_1 > 1){
			top_2--;
			arr[top_2] = element;
		}else{
			cout<<"stack 2 is overflow"<<endl;
		}
	}
	void pop_1(){
		if(top_1 >= 0){
			top_1--;
		}else{
			cout<<"stack 1 is underflow"<<endl;
		}
	}
	void pop_2(){
		if(top_2 < size){
			top_2++;
		}else{
			cout<<"stack 2 underflow"<<endl;
		}
	}
	int peek_1(){
		if(top_1 >= 0)
			return arr[top_1];
		cout<<"stack 1 is empty"<<endl;
		return top_1;
	}
	int peek_2(){
		if(top_2 < size)
			return arr[top_2];
		cout<<"stack 2 is empty"<<endl;
		return -1;
	}
	bool empty_1(){
		if(top_1 < 0)
			return true;
		return false;		
	}
	bool empty_2(){
		if(top_2 >= size)
			return true;
		return false;
		
	}
	
};


int main(){
	
	//	Q: insert two stacks in an array

	TwoStacks* s2 = new TwoStacks(5);
	s2->push_1(1);
	s2->push_1(2);
	s2->push_2(5);
	s2->push_2(4);
	s2->pop_2();
	s2->pop_2();
	cout<<s2->empty_2();
	
	return 0;
}
