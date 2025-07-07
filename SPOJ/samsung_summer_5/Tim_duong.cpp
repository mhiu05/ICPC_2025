#include <bits/stdc++.h>
using namespace std;

const int MAX = 505;
char A[MAX][MAX];
bool visited[MAX][MAX][4]; // x, y, direction
int dx[4] = {-1, 1, 0, 0}; // up, down, left, right
int dy[4] = {0, 0, -1, 1};
int n, m;

struct State {
    int x, y, dir, turns;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        int sx, sy, tx, ty;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                cin >> A[i][j];
                for (int d = 0; d < 4; ++d) visited[i][j][d] = false;
                if (A[i][j] == 'S') sx = i, sy = j;
                if (A[i][j] == 'T') tx = i, ty = j;
            }

        queue<State> q;
        for (int d = 0; d < 4; ++d) {
            int nx = sx + dx[d];
            int ny = sy + dy[d];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && A[nx][ny] != '*') {
                q.push({nx, ny, d, 0});
                visited[nx][ny][d] = true;
            }
        }

        bool found = false;
        while (!q.empty()) {
            auto [x, y, dir, turns] = q.front(); q.pop();

            if (x == tx && y == ty && turns <= 2) {
                found = true;
                break;
            }

            // tiếp tục bắn tia theo hướng hiện tại
            int nx = x + dx[dir], ny = y + dy[dir];
            while (nx >= 1 && nx <= n && ny >= 1 && ny <= m && A[nx][ny] != '*') {
                if (!visited[nx][ny][dir]) {
                    visited[nx][ny][dir] = true;
                    q.push({nx, ny, dir, turns});
                }
                nx += dx[dir];
                ny += dy[dir];
            }

            // thử rẽ sang hướng mới
            for (int nd = 0; nd < 4; ++nd) {
                if (nd == dir) continue;
                int nx = x + dx[nd], ny = y + dy[nd];
                if (turns + 1 > 2) continue;
                if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && A[nx][ny] != '*' && !visited[nx][ny][nd]) {
                    visited[nx][ny][nd] = true;
                    q.push({nx, ny, nd, turns + 1});
                }
            }
        }

        if(found) cout << "YES\n";
		else cout << "NO\n";
    }
}
