#include<iostream>
using namespace std;

void sayDigits(long long n, string* arr){
	if(n == 0){
		return;
	}
		
	int digit = n%10;
	n /= 10;
	
	sayDigits(n, arr);
	
	cout<<arr[digit]<<" ";
}

int main(){
	string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	
	long long n;
	cin>>n;
	
	cout<<endl;
	sayDigits(n, arr);
	cout<<endl;
	
	return 0;
}
