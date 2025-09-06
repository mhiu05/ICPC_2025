#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void prepare() {
    // Nếu cần tiền xử lý thì viết ở đây
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> H(n + 2, vector<int>(m + 2, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> H[i][j];
        }
    }

    long long res = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (H[i][j] == 0) continue;

            // Cộng mặt trên + mặt dưới
            res += 2;

            // Kiểm tra 4 hướng
            for (int dir = 0; dir < 4; dir++) {
                int ni = i + dx[dir];
                int nj = j + dy[dir];

                if (H[i][j] > H[ni][nj]) {
                    res += H[i][j] - H[ni][nj];
                }
            }
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (fopen("VanLam.inp", "r")) {
        freopen("VanLam.inp", "r", stdin);
        freopen("VanLam.out", "w", stdout);
    }

    prepare();

    int testCases = 1;
    cin >> testCases;
    while (testCases--) {
        solve();
    }

    return 0;
}
