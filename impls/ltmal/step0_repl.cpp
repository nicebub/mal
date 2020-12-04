#include <iostream>
#include <string>
using namespace std;

string READ(const string str){
	return str;
}

string EVAL(const string str){
	return str;
}

string PRINT(const string str){
	return str;
}
string rep(const string str){
	return PRINT(EVAL(READ(str)));
}

int main(){
	string str;
	cout << "user> ";
	while(getline(cin,str)){
		cout << rep(str) << endl;
		cout << "user> ";
	}
	return 0;
}