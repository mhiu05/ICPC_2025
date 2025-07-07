#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> t(N+1), dp(N+1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> t[i];
        // Tìm vị trí j2 sao cho t[j2] >= t[i] - 119
        int j2 = lower_bound(t.begin() + 1, t.begin() + i + 1, t[i] - 119) - t.begin();
        // Tìm vị trí j24 sao cho t[j24] >= t[i] - 1439
        int j24 = lower_bound(t.begin() + 1, t.begin() + i + 1, t[i] - 1439) - t.begin();

        ll cost1 = dp[i-1] + 6000;
        ll cost2 = dp[j2-1] + 15000;
        ll cost3 = dp[j24-1] + 40000;

        dp[i] = min({cost1, cost2, cost3});

        // In ra phần chi phí phải trả thêm cho chuyến i
        cout << dp[i] - dp[i-1] << "\n";
    }

    return 0;
}
