#include<iostream>
#include<stack>
using namespace std;

bool knows(int members[][3],int a, int b, int n){
	if(members[a][b] == 1)
		return true;
	else
		return false;
}

int findCelebrity(int members[][3], int n){
	stack<int> s;
	for(int i = 0; i < n; i++){
		s.push(i); // adding members in stack
	}
	while(s.size() > 1){
		int a = s.top();
		s.pop();
		int b = s.top();
		s.pop();
		if(knows(members, a, b, n)){
			s.push(b);
		}else{
			s.push(a);	
		}
	}
	int celebrity =  s.top();
	
	int colCheck = 0;
	// check celebrity ko sab jantay han
	for(int i = 0; i < n; i++){
		if(members[i][celebrity] == 1){
			colCheck++;
		}
	}
	int rowCheck = 0;
	// check celebrity ko koi nahi janta
	for(int j = 0; j < n; j++){
		if(members[celebrity][j] == 0){
			rowCheck++;
		}
	}
	if(colCheck == n-1 and rowCheck == n)
	
		return celebrity;
	return -1;

}

int main(){
	int n = 3;
	int M[n][3] = 
//	{
//	//  one ko sab jantay han
//		{0, 1, 0},
//		{0, 0, 0}, // one kisi ko nahi janta
//		{0, 1, 0}
//	};
		{
	
		{0, 0, 1},
		{0, 0, 0}, // replace last 0 with 1
		{0, 0, 0}
	};
	int celebrity = findCelebrity(M, n);
	cout<<"celebrity is: "<<celebrity<<endl;
	
	return 0;
}
