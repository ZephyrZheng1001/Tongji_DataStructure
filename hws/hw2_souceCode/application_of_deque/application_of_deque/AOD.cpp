#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> g;  // �洢������󣬼�¼ÿ��λ�õ�0/1״̬
vector<vector<bool>> v; // ���ʱ�Ǿ��󣬼�¼ÿ��λ���Ƿ��ѱ�����

// ���������������¡��ϡ��ҡ���
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

pair<int, bool> f(int sx, int sy) {
    queue<pair<int, int>> q;  //BFS���У��洢�����ʵ�����
    q.push({ sx, sy });
    v[sx][sy] = true;  //�����ʼλ��Ϊ�ѷ���

    int cnt = 0;       //��ǰ��ͨ����Ĵ�С
    bool edge = true;  //��Ǹ������Ƿ�Ӵ�����߽�

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;

        //��鵱ǰ�����Ƿ��ڱ߽���
        if (!(x == 0 || x == n - 1 || y == 0 || y == m - 1)) {
            edge = false;  //�������ڲ��㣬����Ϊ�Ǳ߽�����
        }

        //�����ĸ�������
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //��֤���������Ч�ԣ��ھ���Χ�ڡ�ֵΪ1��δ������
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                g[nx][ny] == 1 && !v[nx][ny]) {
                v[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    return { cnt, edge };  // ���������С�ͱ߽���
}

int main() {
    cin >> n >> m;
    g.resize(n, vector<int>(m));
    v.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 1 && !v[i][j]) {
                pair<int, bool> result = f(i, j);
                int sz = result.first;
                bool e = result.second;
                if (!e) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}