#include<iostream>
using namespace std;

#define PI 3.14

#define AREA(l, b) (l * b)

#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138
/*
#define INSTAGRAM FOLLOWERS: This defines a macro named INSTAGRAM that replaces occurrences of INSTAGRAM with FOLLOWERS. Essentially, INSTAGRAM is just another name for FOLLOWERS
*/

// Multi-line Macro definition
#define ELE 1, \
	2, \
	3

#define min(a, b) ((a < b) ? a : b) // outer brackets must 

//#define  PI  3.1416
#define  AREA(r)  (PI*(r)*(r)) // this line will replace the upper AREA(l, b) macro

int main()  // https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/
{


	/*Example # 1*/
	cout<<!PI<<endl;
	PI + 1;
//	PI++;


	/*Example # 2*/
	/*
	int l1 = 10, l2 = 5, area;
	area = AREA(l1, l2);
	cout<<("Area of rectangle is: " , area); cout<<endl;
	*/

	/*Example # 3*/
	cout<<"Geeks for Geeks have followers on Instagram "<<INSTAGRAM<<endl;

	/*Example # 4*/
	int arr[] = { ELE };
	cout<<"Elements of Array are: "<<endl;
	for (int i = 0; i < 3; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	/*Example # 5*/
	int a = 18;
	int b = 76;
	cout<<"Minimum value between "<<a <<" and "<<b<<" is "<<min(a, b)<<endl;

	/*Example # 6*/
	float r = 7;
	cout<<"Area of Circle with radius "<<r<<" is "<<AREA(r)<<endl;

	return 0;
}
