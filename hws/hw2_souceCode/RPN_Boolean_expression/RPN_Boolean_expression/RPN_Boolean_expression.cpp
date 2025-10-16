#include <stack>
#include <string>
#include <iostream>
#include <stdexcept>

class calculator {
private:
    std::string postfixNotation;

    // ��������ȼ�
    int precedence(char op) const {
        if (op == '!') return 3;
        if (op == '&') return 2;
        if (op == '|') return 1;
        return 0;
    }
    // ������Ƿ��ҽ��
    bool isRightAssociative(char op) const {
        return op == '!';
    }

    void infixToPostfix(const std::string& infixNotation) {
        postfixNotation.clear();
        std::stack<char> operatorSt;
        int bracketCount = 0;

        for (size_t i = 0; i < infixNotation.size(); ++i) {
            char ch = infixNotation[i];
            if (ch == ' ') continue;

            if (ch == '(') {
                operatorSt.push(ch);
                bracketCount++;
            }
            else if (ch == ')') {
                bracketCount--;
                while (!operatorSt.empty() && operatorSt.top() != '(') {
                    postfixNotation.push_back(operatorSt.top());
                    operatorSt.pop();
                }
                if (operatorSt.empty()) {
                    throw std::invalid_argument("�����Ŷ���������");
                }
                operatorSt.pop(); // ���� '('
            }
            else if (ch == 'V' || ch == 'F') {
                postfixNotation.push_back(ch);
            }
            else if (ch == '!' || ch == '&' || ch == '|') {
                while (!operatorSt.empty() && operatorSt.top() != '(' &&
                    (precedence(ch) < precedence(operatorSt.top()) ||
                        (precedence(ch) == precedence(operatorSt.top()) && !isRightAssociative(ch)))) {
                    postfixNotation.push_back(operatorSt.top());
                    operatorSt.pop();
                }
                operatorSt.push(ch);
            }
            else {
                throw std::invalid_argument("�Ƿ��ַ�");
            }
        }

        if (bracketCount != 0) {
            throw std::invalid_argument("���Ų�ƥ��");
        }

        while (!operatorSt.empty()) {
            if (operatorSt.top() == '(') throw std::invalid_argument("�����Ŷ���������");
            postfixNotation.push_back(operatorSt.top());
            operatorSt.pop();
        }
    }

    char calculateOnce(char ch1, char ch2, char oper) {
        if (oper == '&') return (ch1 == 'V' && ch2 == 'V') ? 'V' : 'F';
        if (oper == '|') return (ch1 == 'V' || ch2 == 'V') ? 'V' : 'F';
        return 'F';
    }

public:
    calculator() = default;

    char calculate(const std::string& infixNotation) {
        postfixNotation.clear();
        infixToPostfix(infixNotation);
        std::stack<char> st;
        for (char ch : postfixNotation) {
            if (ch == 'V' || ch == 'F') {
                st.push(ch);
            }
            else if (ch == '!') {
                if (st.empty()) throw std::runtime_error("����������");
                char top = st.top(); st.pop();
                st.push(top == 'V' ? 'F' : 'V');
            }
            else if (ch == '&' || ch == '|') {
                if (st.size() < 2) throw std::runtime_error("����������");
                char ch1 = st.top(); st.pop();
                char ch2 = st.top(); st.pop();
                st.push(calculateOnce(ch2, ch1, ch));
            }
            else {
                throw std::runtime_error("δ֪�����");
            }
        }
        if (st.size() != 1) throw std::runtime_error("���ʽ�������");
        return st.top();
    }
};

int main() {
    calculator cal;
    std::string str;
    int cnt = 1;
    while (std::getline(std::cin, str)) {
        try {
            std::cout << "Expression " << cnt << ": " << cal.calculate(str) << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error in expression " << cnt << ": " << e.what() << std::endl;
        }
        cnt++;
    }
    return 0;
}
