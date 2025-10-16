#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> Term; // 项: (系数, 指数)
typedef vector<Term> Polynomial;

// 多项式加法
Polynomial addPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result;
    int i = 0, j = 0;
    int size1 = poly1.size(), size2 = poly2.size();

    while (i < size1 && j < size2) {
        int exp1 = poly1[i].second;
        int exp2 = poly2[j].second;

        if (exp1 == exp2) {
            // 指数相同，系数相加
            int coef_sum = poly1[i].first + poly2[j].first;
            if (coef_sum != 0) {
                result.push_back(make_pair(coef_sum, exp1));
            }
            i++;
            j++;
        }
        else if (exp1 < exp2) {
            // poly1的指数较小
            result.push_back(poly1[i]);
            i++;
        }
        else {
            // poly2的指数较小
            result.push_back(poly2[j]);
            j++;
        }
    }

    // 处理剩余项
    while (i < size1) {
        result.push_back(poly1[i]);
        i++;
    }
    while (j < size2) {
        result.push_back(poly2[j]);
        j++;
    }

    return result;
}

// 多项式乘法
Polynomial multiplyPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    map<int, int> exp_map; // 指数->系数映射，自动按指数排序

    // 遍历所有项对
    for (const Term& term1 : poly1) {
        for (const Term& term2 : poly2) {
            int coef_product = term1.first * term2.first;
            int exp_sum = term1.second + term2.second;
            exp_map[exp_sum] += coef_product;
        }
    }

    // 构建结果多项式，过滤零系数项
    Polynomial result;
    for (const auto& entry : exp_map) {
        if (entry.second != 0) {
            result.push_back(make_pair(entry.second, entry.first));
        }
    }

    return result;
}

// 输出多项式
void printPolynomial(const Polynomial& poly) {
    if (poly.empty()) return; // 空多项式不输出

    for (size_t i = 0; i < poly.size(); i++) {
        if (i > 0) cout << " ";
        cout << poly[i].first << " " << poly[i].second;
    }
    cout << endl;
}

int main() {
    int m, n;
    cin >> m;
    Polynomial poly1;
    for (int i = 0; i < m; i++) {
        int coef, exp;
        cin >> coef >> exp;
        poly1.push_back(make_pair(coef, exp));
    }

    cin >> n;
    Polynomial poly2;
    for (int i = 0; i < n; i++) {
        int coef, exp;
        cin >> coef >> exp;
        poly2.push_back(make_pair(coef, exp));
    }

    int operation;
    cin >> operation;

    switch (operation) {
    case 0: // 加法
        printPolynomial(addPolynomials(poly1, poly2));
        break;
    case 1: // 乘法
        printPolynomial(multiplyPolynomials(poly1, poly2));
        break;
    case 2: // 加法和乘法
        printPolynomial(addPolynomials(poly1, poly2));
        printPolynomial(multiplyPolynomials(poly1, poly2));
        break;
    }

    return 0;
}