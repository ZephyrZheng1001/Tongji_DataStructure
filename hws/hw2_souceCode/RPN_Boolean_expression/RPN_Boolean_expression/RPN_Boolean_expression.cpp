#define T true
#define F false
#include <stack>
#include <string>
#include <unordered_map>
//使用map来存放运算符与运算级别的关系
std::unordered_map<char, int> map;
//运算优先级 ) > not > and > or > (
enum operatorPrecedence { RIGHTBRACKET, OR, AND, NOT, LEFTBRACKET };
class calculator {
private:
	std::stack<bool> m_val_stack;
	std::stack<char> m_sign_stack;
	int orderOfOperation = 0;
public:
	calculator() {
		this->orderOfOperation;
		//初始化map
		map['('] = LEFTBRACKET;
		map['!'] = NOT;
		map['&'] = AND;
		map['|'] = OR;
		map[')'] = RIGHTBRACKET;
	}
	char doCalculation(std::string expression) {
		for (char ch : expression) {
			
		}
	}
};