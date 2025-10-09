#include <iostream>
#include <list>
#include <string>
using namespace std;

// 定义扑克牌结构体
struct Card {
    string suit;
    string rank;
};

// 将牌面值转换为数字以便排序
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
    list<Card> deck;  // 牌堆：链表前端为顶部，后端为底部

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

            // 遍历牌堆，提取指定花色的牌
            auto it = deck.begin();
            while (it != deck.end()) {
                if (it->suit == suit) {
                    extracted.push_back(*it);
                    it = deck.erase(it);  // 从原牌堆移除
                }
                else {
                    it++;
                }
            }

            // 按数字值升序排序提取的牌
            extracted.sort([](const Card& a, const Card& b) {
                return rankToValue(a.rank) < rankToValue(b.rank);
                });

            // 将排序后的牌按降序插入牌堆顶部（确保最小牌在最上面）
            for (auto rit = extracted.rbegin(); rit != extracted.rend(); rit++) {
                deck.push_front(*rit);
            }
        }
    }

    // 输出最终牌堆状态
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