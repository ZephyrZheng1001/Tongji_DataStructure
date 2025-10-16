#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> BigNum;

void printBigNum(const BigNum& num) {
    if (num.empty()) {
        cout << 0;
        return;
    }
    for (int i = num.size() - 1; i >= 0; i--) {
        cout << num[i];
    }
}

BigNum addBigNum(const BigNum& a, const BigNum& b) {
    BigNum result;
    int carry = 0;
    int i = 0;
    while (i < a.size() || i < b.size() || carry) {
        int sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        carry = sum / 10;
        result.push_back(sum % 10);
        i++;
    }
    return result;
}

BigNum multiplyBigNum(const BigNum& a, int b) {
    if (b == 0) {
        return BigNum(1, 0);
    }
    BigNum result;
    int carry = 0;
    for (int i = 0; i < a.size() || carry; i++) {
        int product = carry;
        if (i < a.size()) product += a[i] * b;
        carry = product / 10;
        result.push_back(product % 10);
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    return result;
}

int main() {
    int N, A;
    while (cin >> N >> A) {
        BigNum sum(1, 0);
        BigNum current_power(1, 1);

        for (int k = 1; k <= N; k++) {
            current_power = multiplyBigNum(current_power, A);
            BigNum term = multiplyBigNum(current_power, k);
            sum = addBigNum(sum, term);
        }

        printBigNum(sum);
        cout << endl;
    }
    return 0;
}