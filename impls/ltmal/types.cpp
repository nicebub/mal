#include <variant>
#include <string>
#include <list>
class MalType {
	public:
		MalType(){}
		MalType(std::variant<int,std::string> inv): var{inv} {}
		~MalType(){}
		std::variant<int, std::string> getvar(){
			return var;
		}
		void setvar(std::variant<int,std::string> inv){
			var = inv;
		}
	private:
		std::variant<int,std::string> var;
};

class MalList : MalType {
	public:

		MalList(){}
		MalList(std::list<MalType> lis): mlist{lis} {}
		~MalList(){}
		
	private:
		std::list<MalType> mlist;
};