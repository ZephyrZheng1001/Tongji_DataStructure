#define T true
#define F false
#include <stack>
#include <string>
#include <unordered_map>
//ʹ��map���������������㼶��Ĺ�ϵ
std::unordered_map<char, int> map;
//�������ȼ� ) > not > and > or > (
enum operatorPrecedence { RIGHTBRACKET, OR, AND, NOT, LEFTBRACKET };
class calculator {
private:
	std::stack<bool> m_val_stack;
	std::stack<char> m_sign_stack;
	int orderOfOperation = 0;
public:
	calculator() {
		this->orderOfOperation;
		//��ʼ��map
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