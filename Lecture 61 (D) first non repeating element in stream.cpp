#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;

// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

/*
//	--> solve by my self but incomplete
	
string firstNonRepeatingElement(string s) {

	queue<char> q;
	string str = "";
	str += s.at(0);
	q.push(s.at(0));
	s = s.substr(1);

	while(s.size() > 0) {
		if(q.empty()){
			str += s.at(0);
			q.push(s.at(0));
		}
		else if(!q.empty() && q.front() != s.at(0)) {
			str += q.front();
			q.push(s.at(0));
		}

		else if(q.front() == s.at(0)) {
			q.pop();
			if(q.empty()) {
				str += '#';
//				q.push(s.at(0));
			} else {
				str += q.front();
					q.push(s.at(0));
			}
//			q.push(s.at(0));
		}

		s = s.substr(1);
	}
	return str;
}
*/

string firstNonRepeatingElement(string s){
	queue<char> q;
	map<char, int> count;
	string ans = "";
	for(int i = 0; i < s.size(); i++){
		
		char ch = s.at(i);
		count[ch]++;
		q.push(ch);
		
		while(!q.empty()){
			
			if(count[q.front()] > 1){
				q.pop();
			}else{
				ans.push_back(q.front());
				break; 	
			}
		}
		
		if(q.empty()){
			ans.push_back('#');
		}
	}
	return ans;
}

/*
string FirstNonRepeating(string A){
		   queue<int> q;
		   string ans = "";
		   map<char, int> count;
		   for(int i = 0; i < A.size(); i++){
		       q.push(A.at(i));
		       count[A.at(i)]++;
		       while(!q.empty() && count[q.front()] > 1){
		           q.pop();
		       }
		       
		       if(!q.empty()){
		           ans.push_back(q.front());
		       }else{
		           ans.push_back('#');
		       }
		   }
		   return ans;
		}
*/

int main() {
	cout<<firstNonRepeatingElement("tcpmxaixsswjelbswxytyhbwjinuhxhvpwaybmdhndafszoghpyzdahiqsgluufqcekjk")<<endl;
	
	cout<<"tttttttttttttttttttcccccccccccccccccccccccccccccccccccccccccccccevvvv";


	return 0;
}
