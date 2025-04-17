#include<iostream>
using namespace std;

void heapify(int* arr, int n, int i) {
	
	int smallest = i;
	int leftChild = i*2 + 1;
	int rightChild = i*2+2;

	if(leftChild < n and arr[leftChild] < arr[smallest]) {
		
		smallest = leftChild;
	
	} 
	// use if condition not else-if
	if(rightChild < n and arr[rightChild] < arr[smallest]) {
	
		smallest = rightChild;
	
	}

	if(smallest != i) {
		
		swap(arr[smallest], arr[i]);
		/* // not working well for sort 
		if(arr[smallest] < arr[rightChild]){
			swap(arr[smallest], arr[rightChild]);
		}
		*/
		heapify(arr, n, smallest);
	
	}
}

int main(){
	
//	int arr[5] = {54, 55, 53, 52, 50};
	int arr[5] = {59, 62, 65, 52, 50};
	int n = 5;
	
	for(int i = (n/2)-1; i >= 0; i--){
		heapify(arr, n, i);
	}
	
	cout<<"Printing of heap"<<endl;
	
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
}
