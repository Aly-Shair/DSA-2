#include<iostream>
using namespace std;

class Heap{
	private:
		int arr[100];
		int size;
	public:
		Heap(){
			arr[0] = -1;
			size = 0;
		}
		
		void insert(int val){
			int idx = ++size;
			arr[idx] = val;
			
			while(idx > 1){
				int parent = idx/2;
				if(arr[parent] < arr[idx]){
					swap(arr[parent], arr[idx]);
					idx = parent;
				}else{
					return;
				}
			}
		}
		
		void print(){
			for(int i = 1; i <= size; i++){
				cout<<arr[i]<<" ";
			}cout<<endl;
		}
		
};

int main(){
	Heap h;
	h.insert(60);
	h.insert(50);
	h.insert(40);
	h.insert(30);
	h.insert(20);
	h.insert(55);
	h.print();
	return 0;
}
