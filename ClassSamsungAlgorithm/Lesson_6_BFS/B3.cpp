#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int INF = 1e9;

int N, M, Q;
string board[MAXN];
int dist[MAXN][MAXN];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dist[i][j] = INF;

    deque<pair<int,int>> dq;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (board[i][j] == '*') {
                dist[i][j] = 0;
                dq.push_front({i,j});
            }
        }
    }

    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!inside(nx, ny)) continue;

            int cost = (board[nx][ny] == board[x][y]) ? 0 : 1;

            if (dist[nx][ny] > dist[x][y] + cost) {
                dist[nx][ny] = dist[x][y] + cost;
                if (cost == 0)
                    dq.push_front({nx, ny});
                else
                    dq.push_back({nx, ny});
            }
        }
    }

    while (Q--) {
        int x, y; 
        cin >> x >> y;
        x--; y--;
        cout << dist[x][y] << "\n";
    }

    return 0;
}
