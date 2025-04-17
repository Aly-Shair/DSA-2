#include<iostream>
using namespace std;

// https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1

struct PetrolPump{
	int petrol;
	int distance;
};

class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(PetrolPump p[],int n)
    {
       int start;
       int balance = 0;
       int deficit = 0;
       
       for(int i = 0; i < n; i++){
           balance += p[i].petrol - p[i].distance;
           if(balance < 0){
               deficit += balance;
               start = i + 1;
               balance = 0;
           }
       }
       if(balance + deficit >= 0){
       	/*
       		cout<<balance<<endl;
       		cout<<deficit<<endl;
       		cout<<balance + deficit<<endl;
       	*/
           return start;
       }else{
           return -1;
       }
    }
};

int main(){
	
	int n;
	cin>>n;
	PetrolPump p[n];
	
	for(int i = 0; i < n; i++){
		cin>>p[i].petrol>>p[i].distance;
	}
	
	Solution obj;
	cout<<obj.tour(p,n);
	
	return 0;
}
