#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void find(string input, int& max, int& start)
{
    int n = input.length();
    max = 0;                
    start = 0; 

    if (n == 0) {
        return;
    }

    stack<int> st;      //储存括号的标记
    st.push(-1);        //【改进点】压入-1作为初始边界标记，便于计算第一个有效子串的长度

    for (int i = 0; i < n; i++) {
        if (input[i] == '(') {      //左括号入栈
            st.push(i);
        }
        else {      //右括号弹出栈顶栈顶元素
            st.pop();

            if (st.empty()) {   //空栈直接压入新边界
                st.push(i);
            }
            else {  //栈非空计算有效长度
                int currentLen = i - st.top();
                if (currentLen > max) {     //更新长度和起始位置
                    max = currentLen;
                    start = st.top() + 1; 
                }
            }
        }
    }
}

int main()
{
    string input;           // 存储输入字符串
    int max = 0, start = 0; // 分别存储最长有效子串的长度和起始位置
    getline(cin, input);    // 读取输入字符串

    find(input, max, start);  // 调用find函数计算结果

    cout << max << " " << start << endl;  // 输出最长长度和起始位置

    return 0;
}

