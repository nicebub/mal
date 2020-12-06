#include <string>
#include <regex>
#include <list>
#include <iostream>
#include "types.cpp"


using namespace std;
class Reader {
	public:
		Reader(list<string> inTokens): position(0),
		tokList{inTokens},
		current{inTokens.begin()} {}
		Reader(): position(0),tokList{}, current{} {}
		~Reader(){}

	std::string next(void){
		list<string>::iterator end;
		if(current != end){
			return *current++;
		}
		return "";
	}
	std::string peek(void){
		list<string>::iterator end;
		if(current != end){
			return *current;
		}
		return "";
	}
	private:
		int position;
		list<string> tokList;
		list<string>::iterator current;
};

MalType read_form(Reader reader);

list<MalType> read_list(Reader reader){
	list<MalType> mlist{};
	std::string result = reader.peek();
	while(!result.empty() && *result.cbegin() != ')'){
		mlist.emplace_back(read_form(reader));
	}
	if(result.empty()){/*error*/}
	return mlist;
}

void read_atom(Reader reader){
	
}

MalType read_form(Reader reader){
	std::string result = reader.peek();
	if(result.empty()){}
	switch(*result.cbegin()){
		case '(':
			reader.next();
			read_list(reader);
			break;
		default:
			read_atom(reader);
			break;
	}
	return MalType();
}

list<string> tokenize(std::string input, std::regex reg){
	list<string> tokens{};
	std::regex_token_iterator<std::string::const_iterator> tok_iter{
		input.cbegin(),
		input.cend(),
		reg,
		0
	};
	std::regex_token_iterator<std::string::const_iterator> end;
	while(tok_iter != end){
		std::string result = *tok_iter++;
/*		cout << result << endl;*/
/*		if(*result.cbegin()=='\"' && *--result.cend() != '\"'){
			cerr << "string not terminated with \"" << endl;
		}
		else{*/
			tokens.emplace_back(result);
/*			}*/
	}
	return tokens;
}

void read_str(const string value,const std::regex reg){
/*	tokenize(value,reg);*/
	Reader reader(tokenize(value,reg));
	read_form(reader);
}
