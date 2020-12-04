#include <iostream>
#include <string>
#include <peelo/prompt.hpp>

using namespace std;

const string READ(const string str){
	return str;
}

const string EVAL(const string str){
	return str;
}

const string PRINT(const string str){
	return str;
}
const string rep(const string str){
	return PRINT(EVAL(READ(str)));
}

int main(){
	peelo::prompt prompt;

	prompt.set_multi_line(true);
	prompt.set_history_max_size(10);

	while(auto line = prompt.input("user> ")){
		const auto value = line.value();

		if(value.empty()) continue;
		if(value[0] == '/' && !value.compare(0, 11, "/historylen")){
			prompt.set_history_max_size(std::atoi(value.c_str() + 11));
		}
		else{
			cout << rep(value) << endl;
			prompt.add_to_history(value);
		}
	}
		return 0;
}