#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
	/*creation of unordered map*/
	unordered_map<string, int> m;
	
	/*insertion in unordered map*/
	pair<string, int> p = make_pair("Ali", 3);
	m.insert(p);
	
	pair<string, int> p1("Shair", 2);
	m.insert(p1);
	
	m["Mr Robot"] = 1;
//	updation
	m["Mr Robot"] = 2;
	
	/*searching in unordered map*/
	cout<<m["Ali"]<<endl;
	cout<<m.at("Ali")<<endl;
	
//	cout<<m.at("unknownkey")<<endl;
	cout<<m["unknownkey"]<<endl;
	cout<<m.at("unknownkey")<<endl;

	/*size of unordered map*/
	cout<<m.size()<<endl;
	
	/*is available key in unordered map*/
	
	cout<<m.count("Ali")<<endl;
	cout<<m.count("ali")<<endl;
	cout<<m.count("unknownkey")<<endl;
	
	/*removal in unordered map*/
	m.erase("Mr Robot");
	cout<<m.size()<<endl;
	
	/*triversing unordered map*/
	
	for(auto i: m){
		cout<<i.first <<" "<<i.second<<endl;
	}
	
	unordered_map<string, int> :: iterator itr = m.begin();
	while(itr != m.end()){
		cout<<itr->first <<" "<<itr->second<<endl;
		itr++;
	}
}
