#include<iostream>
using namespace std;

int main()
{

	int r;
	cout<<"Enter number of rows ";
	cin>>r;

	int** arr = new int*[r];
	int* c = new int[r];

	for(int i = 0; i < r; i++)
	{
		cout<<"Enter number of cols for row no. " << i+1;
		cin>>c[i];
		arr[i] = new int[c[i]];
	}

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c[i]; j++)
		{
			cin>>arr[i][j];
		}
	}

	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c[i]; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i = 0; i < r; i++)
	{
		delete [] arr[i];
	}
	delete [] arr;
	delete [] c;

	return 0;
}
