#include<iostream>
using namespace std;

long long power(long long a, long long b){
	if(b == 0)
		return 1;
	
	if(b == 1)
		return a;
	
	long long ans = power(a, b/2);
	
	if(b%2 == 0)
		return ans*ans;
	else
		return a*ans*ans;
}

long long power_2(long long a, long long b){
	if(b == 0)
		return 1;
	
	
	if(b == 1)
		return a;
	
	long long ans = power_2(a, b-1);
	return ans * a;
}

int main(){
	
	int a, b;
	cin>>a>>b;
	cout<<"tutorial function"<<endl;
	cout<<power(a, b)<<endl;
	cout<<"my function"<<endl;
	cout<<power_2(a, b)<<endl;
	
	return 0;
}
