#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll MOD = 1e9 + 9;
const int MAXN = 1005;

using namespace std;

signed main() {
    faster;

    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1), b(m + 1);
    
    FOR(i, 1, n) cin >> a[i];
    FOR(j, 1, m) cin >> b[j];
    
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());
    
    int dp[MAXN][MAXN][11] = {0};
    
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            dp[i][j][0] = 1;
        }
    }
    
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            FOR(t, 0, k) {
                dp[i][j][t] = dp[i-1][j][t] + dp[i][j-1][t] - dp[i-1][j-1][t];
                dp[i][j][t] %= MOD;
                
                if (t > 0 && a[i] > b[j]) {
                    dp[i][j][t] += dp[i-1][j-1][t-1];
                    dp[i][j][t] %= MOD;
                }
                
                if (dp[i][j][t] < 0) dp[i][j][t] += MOD;
            }
        }
    }
    
    cout << dp[n][m][k];
    return 0;
}