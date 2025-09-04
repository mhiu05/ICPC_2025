#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 1000;
const int INF = 1e9;
const int MAX_SUM = 15000;

vector<int> precompute_min_ops() {
    vector<int> min_ops(MAX_VAL+1, INF);
    min_ops[1] = 0;
    for (int i = 1; i <= MAX_VAL; i++) {
        for (int x = 1; x <= i; x++) {
            int j = i + i / x;
            if (j <= MAX_VAL) {
                min_ops[j] = min(min_ops[j], min_ops[i] + 1);
            }
        }
    }
    return min_ops;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    auto min_ops = precompute_min_ops();
    
    // for(int x : min_ops) cout << x << " ";
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> B(N), C(N);
        for (int i = 0; i < N; i++) cin >> B[i];
        for (int i = 0; i < N; i++) cin >> C[i];
        
        vector<int> w(N), v(N);
        int total_w = 0;
        for (int i = 0; i < N; i++) {
            w[i] = min_ops[B[i]];
            v[i] = C[i];
            total_w += w[i];
        }
        
        int cap = min(K, total_w);
        cap = min(cap, MAX_SUM);
        
        vector<vector<int>> dp(N+1, vector<int>(cap+1, 0));
        
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= cap; j++) {
                if (j < w[i-1]) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j - w[i-1]] + v[i-1]);
                }
            }
        }
        
        int ans = 0;
        for (int j = 0; j <= cap; j++) {
            ans = max(ans, dp[N][j]);
        }
        cout << ans << "\n";
    }
}