#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> g;  // 存储输入矩阵，记录每个位置的0/1状态
vector<vector<bool>> v; // 访问标记矩阵，记录每个位置是否已被访问

// 四邻域方向向量：下、上、右、左
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

pair<int, bool> f(int sx, int sy) {
    queue<pair<int, int>> q;  //BFS队列，存储待访问的坐标
    q.push({ sx, sy });
    v[sx][sy] = true;  //标记起始位置为已访问

    int cnt = 0;       //当前连通区域的大小
    bool edge = true;  //标记该区域是否接触矩阵边界

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;

        //检查当前坐标是否不在边界上
        if (!(x == 0 || x == n - 1 || y == 0 || y == m - 1)) {
            edge = false;  //若存在内部点，则标记为非边界区域
        }

        //遍历四个邻域方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            //验证新坐标的有效性：在矩阵范围内、值为1、未被访问
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                g[nx][ny] == 1 && !v[nx][ny]) {
                v[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }

    return { cnt, edge };  // 返回区域大小和边界标记
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