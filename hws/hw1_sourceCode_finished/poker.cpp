#include <iostream>
#include <list>
#include <string>
using namespace std;

// �����˿��ƽṹ��
struct Card {
    string suit;
    string rank;
};

// ������ֵת��Ϊ�����Ա�����
int rankToValue(const string& rank) {
    if (rank == "A") return 1;
    if (rank == "J") return 11;
    if (rank == "Q") return 12;
    if (rank == "K") return 13;
    return stoi(rank);
}

int main() {
    int n;
    cin >> n;
    list<Card> deck;  // �ƶѣ�����ǰ��Ϊ���������Ϊ�ײ�

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "Pop") {
            if (deck.empty()) {
                cout << "NULL" << endl;
            }
            else {
                Card card = deck.front();
                deck.pop_front();
                cout << card.suit << " " << card.rank << endl;
            }
        }
        else if (command == "Append") {
            string suit, rank;
            cin >> suit >> rank;
            deck.push_back({ suit, rank });
        }
        else if (command == "Revert") {
            deck.reverse();
        }
        else if (command == "Extract") {
            string suit;
            cin >> suit;
            list<Card> extracted;

            // �����ƶѣ���ȡָ����ɫ����
            auto it = deck.begin();
            while (it != deck.end()) {
                if (it->suit == suit) {
                    extracted.push_back(*it);
                    it = deck.erase(it);  // ��ԭ�ƶ��Ƴ�
                }
                else {
                    it++;
                }
            }

            // ������ֵ����������ȡ����
            extracted.sort([](const Card& a, const Card& b) {
                return rankToValue(a.rank) < rankToValue(b.rank);
                });

            // ���������ư���������ƶѶ�����ȷ����С���������棩
            for (auto rit = extracted.rbegin(); rit != extracted.rend(); rit++) {
                deck.push_front(*rit);
            }
        }
    }

    // ��������ƶ�״̬
    if (deck.empty()) {
        cout << "NULL" << endl;
    }
    else {
        for (const auto& card : deck) {
            cout << card.suit << " " << card.rank << endl;
        }
    }

    return 0;
}