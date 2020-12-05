#include <string>
#include <regex>
#include <list>
#include <iostream>

using namespace std;
class Reader {
	public:
	
	Reader(list<string> inTokens): 
		position(0),
		tokList{inTokens},
		tokens{}, current{inTokens.begin()} {}
	Reader(): position(0), tokens(),tokList{}, current{} {}
	Reader(const std::list<string> iTokens,const std::regex reg): 
			position(0),
			tokList{}, current{} {
		tokens = std::regex_token_iterator<std::string::const_iterator>(
				iTokens.begin()->cbegin(),
				iTokens.begin()->cend(),
				reg,
				0
			);
	}
	Reader(const std::string iToken,const std::regex reg): 
			position(0),
			tokList{}, current{},
			tokens{
				iToken.cbegin(),
				iToken.cend(),
				reg,
				0
		}
		{}
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
		std::regex_token_iterator<std::string::const_iterator> tokens;
};

void read_form(Reader reader){}
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
		if(*result.cbegin()=='\"' && *result.cend() != '\"'){
			cerr << "string not terminated with \"" << endl;
		}
		else{
			tokens.emplace_back(result);
		}
	}
	return tokens;
}

void read_str(const string value,const std::regex reg){
/*	tokenize(value,reg);*/
	Reader reader(tokenize(value,reg));
	read_form(reader);
}
