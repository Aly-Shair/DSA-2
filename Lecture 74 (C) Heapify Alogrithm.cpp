#include<iostream>
using namespace std;

void heapify(int* arr, int n, int i)
{

	int largest = i;
	int leftChild = i*2;
	int rightChild = i*2+1;

	if(leftChild <= n and arr[leftChild] > arr[largest])
	{

		largest = leftChild;

	}
	// use if condition not else-if
	if(rightChild <= n and arr[rightChild] > arr[largest])
	{

		largest = rightChild;

	}

	if(largest != i)
	{

		swap(arr[largest], arr[i]);
		heapify(arr, n, largest);

	}
}


int main()
{

//	int arr[6] = {-1, 54, 55, 53, 52, 50};
//	int arr[6] = {-1, 1, 2, 3, 4, 5};
	int arr[6] = {-1, 59, 62, 65, 52, 50};
	int n = 5;

	for(int i = (n/2); i > 0; i--) 
	{
		heapify(arr, n, i);
	}

	cout<<"Printing of heap"<<endl;

	for(int i = 1; i <= n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
//	second __part__
//	int arr2[6] = {-1, 54, 55, 53, 52, 50};
	int arr2[6] = {-1, 1, 2, 3, 4, 5};
//	int arr[6] = {-1, 59, 62, 65, 52, 50};
	int n2 = 5;

	
	
		heapify(arr2, n2, 1);
	

	cout<<"Printing of heap"<<endl;

	for(int i = 1; i <= n2; i++)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
}
