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
void heapSort(int* arr, int size){
	while(size > 1){
		swap(arr[size], arr[1]);
		size--;
		heapifyMax(arr, size, 1);		
	}
}



int main(){
//	int arr[6] = {-1, 54, 55, 53, 52, 50};
	int arr[6] = {-1, 59, 62, 65, 52, 50};
	int n = 5;
	
	for(int i = (n/2); i > 0; i--){
		heapifyMax(arr, n, i);
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

/* // https://www.geeksforgeeks.org/problems/heap-sort/0
//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Youir Code Here
      
      
      int largest = i;
      int leftChild = 2*i +1;
      int rightChild = 2*i +2;
      
      if(leftChild < n and arr[leftChild] > arr[largest])
            largest = leftChild;
      if(rightChild < n and arr[rightChild] > arr[largest])
            largest = rightChild;
            
        if(largest != i){
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
        
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i = n/2; i >= 0; i--){
            heapify(arr, n, i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        
        while(n > 1){
            swap(arr[0], arr[n-1]);
            n--;
            heapify(arr, n, 0);
        }
    }
};




//{ Driver Code Starts.

///* Function to print an array 
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends
*/
