#include <iostream>
#include <stack>
#include <string>

int main() {
	std::string train;
	std::cin >> train;
	std::string str;
	while (std::cin >> str) {
		std::stack<char> st;
		bool canGoOut = true;
		int idx = 0;
		for (char ch : train) {
			st.push(ch);
			while (!st.empty() && st.top() == str[idx]){
				idx++;
				st.pop();
			}
		}
		if (!st.empty())
			canGoOut = false;
		if (canGoOut) {
			std::cout << "yes" << std::endl;
		}
		else {
			std::cout << "no" << std::endl;
		}
	}
	return 0;
}