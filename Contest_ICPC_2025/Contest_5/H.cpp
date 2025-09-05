#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 1e9 + 7;
const int maxN = 1005;

int n, m, r, c;
int board[maxN][maxN];
int pre[maxN][maxN];

bool isSuccess(int median) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int current = (board[i][j] <= median) ? 1 : -1;
            pre[i][j] = current + pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1];
        }
    }

    for (int i = r; i <= n; i++) {
        for (int j = c; j <= m; j++) {
            int sum = pre[i][j] - pre[i-r][j] - pre[i][j-c] + pre[i-r][j-c];
            if (sum > 0) { // số phần tử <= medium lớn hơn số phần tử > medium
                return true; // => số cần tìm (truth medium) <= medium
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r >> c;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    int left = 0, right = INF;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (isSuccess(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;

    return 0;
}