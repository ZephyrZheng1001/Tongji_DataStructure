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

    stack<int> st;      //�������ŵı��
    st.push(-1);        //���Ľ��㡿ѹ��-1��Ϊ��ʼ�߽��ǣ����ڼ����һ����Ч�Ӵ��ĳ���

    for (int i = 0; i < n; i++) {
        if (input[i] == '(') {      //��������ջ
            st.push(i);
        }
        else {      //�����ŵ���ջ��ջ��Ԫ��
            st.pop();

            if (st.empty()) {   //��ջֱ��ѹ���±߽�
                st.push(i);
            }
            else {  //ջ�ǿռ�����Ч����
                int currentLen = i - st.top();
                if (currentLen > max) {     //���³��Ⱥ���ʼλ��
                    max = currentLen;
                    start = st.top() + 1; 
                }
            }
        }
    }
}

int main()
{
    string input;           // �洢�����ַ���
    int max = 0, start = 0; // �ֱ�洢���Ч�Ӵ��ĳ��Ⱥ���ʼλ��
    getline(cin, input);    // ��ȡ�����ַ���

    find(input, max, start);  // ����find����������

    cout << max << " " << start << endl;  // �������Ⱥ���ʼλ��

    return 0;
}

