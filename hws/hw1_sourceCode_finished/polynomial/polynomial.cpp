#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef pair<int, int> Term; // ��: (ϵ��, ָ��)
typedef vector<Term> Polynomial;

// ����ʽ�ӷ�
Polynomial addPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result;
    int i = 0, j = 0;
    int size1 = poly1.size(), size2 = poly2.size();

    while (i < size1 && j < size2) {
        int exp1 = poly1[i].second;
        int exp2 = poly2[j].second;

        if (exp1 == exp2) {
            // ָ����ͬ��ϵ�����
            int coef_sum = poly1[i].first + poly2[j].first;
            if (coef_sum != 0) {
                result.push_back(make_pair(coef_sum, exp1));
            }
            i++;
            j++;
        }
        else if (exp1 < exp2) {
            // poly1��ָ����С
            result.push_back(poly1[i]);
            i++;
        }
        else {
            // poly2��ָ����С
            result.push_back(poly2[j]);
            j++;
        }
    }

    // ����ʣ����
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

// ����ʽ�˷�
Polynomial multiplyPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    map<int, int> exp_map; // ָ��->ϵ��ӳ�䣬�Զ���ָ������

    // �����������
    for (const Term& term1 : poly1) {
        for (const Term& term2 : poly2) {
            int coef_product = term1.first * term2.first;
            int exp_sum = term1.second + term2.second;
            exp_map[exp_sum] += coef_product;
        }
    }

    // �����������ʽ��������ϵ����
    Polynomial result;
    for (const auto& entry : exp_map) {
        if (entry.second != 0) {
            result.push_back(make_pair(entry.second, entry.first));
        }
    }

    return result;
}

// �������ʽ
void printPolynomial(const Polynomial& poly) {
    if (poly.empty()) return; // �ն���ʽ�����

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
    case 0: // �ӷ�
        printPolynomial(addPolynomials(poly1, poly2));
        break;
    case 1: // �˷�
        printPolynomial(multiplyPolynomials(poly1, poly2));
        break;
    case 2: // �ӷ��ͳ˷�
        printPolynomial(addPolynomials(poly1, poly2));
        printPolynomial(multiplyPolynomials(poly1, poly2));
        break;
    }

    return 0;
}