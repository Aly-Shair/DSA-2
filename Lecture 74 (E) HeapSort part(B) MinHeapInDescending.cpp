#include<iostream>
using namespace std;

void heapifyMax(int* arr, int n, int i){
	int largest = i;
	int leftChild = 2*i;
	int rightChild = 2*i+1;
	
	if(leftChild <= n and arr[leftChild] > arr[largest]){
		largest = leftChild;
	}
	if(rightChild <= n and arr[rightChild] > arr[largest]){
		largest = rightChild;
	}
	
	if(largest != i){
		swap(arr[largest], arr[i]);
		heapifyMax(arr, n, largest);
	}
}

void heapifyMin(int* arr, int n, int i) {
	
	int smallest = i;
	int leftChild = i*2;
	int rightChild = i*2+1;

	if(leftChild <= n and arr[leftChild] < arr[smallest]) {
		
		smallest = leftChild;
	
	} 
	// use if condition not else-if
	if(rightChild <= n and arr[rightChild] < arr[smallest]) {
	
		smallest = rightChild;
	
	}

	if(smallest != i) {
		
		swap(arr[smallest], arr[i]);
		heapifyMin(arr, n, smallest);
	
	}
}

void heapSort(int* arr, int size){
	while(size > 1){
		swap(arr[size], arr[1]);
		size--;
		heapifyMin(arr, size, 1);		
	}
}



int main(){
//	int arr[6] = {-1, 54, 55, 53, 52, 50};
	int arr[6] = {-1, 59, 62, 65, 52, 50};
	int n = 5;
	
	for(int i = (n/2); i > 0; i--){
		heapifyMin(arr, n, i);
	}
	
	cout<<"Printing of heap"<<endl;
	
	for(int i = 1; i <= n; i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
	
	heapSort(arr, n);	
	
	cout<<"Printing of sorted heap"<<endl;
	
	for(int i = 1; i <= n; i++){
		cout<<arr[i]<<" ";
	}cout<<endl;

}
