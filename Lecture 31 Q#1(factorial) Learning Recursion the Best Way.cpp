#include<iostream>
using namespace std;

int factorial(int n)
{
	if(n < 2)
	{
		return 1;
	}
	int chotiProblem = factorial(n-1);
	int badiProblem = n*chotiProblem;
	
	return badiProblem ;
}

int main()
{
	cout<<factorial(5)<<endl;
}
