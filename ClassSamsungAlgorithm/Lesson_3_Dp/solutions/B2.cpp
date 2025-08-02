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

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int check(int X, int a, int b, int e, vvi &dp){
    FOR(i, 1, a - X + 1){
        FOR(j, 1, b - X + 1){
            int u = i + X - 1, v = j + X - 1;
            int sum = dp[u][v] + dp[i - 1][j - 1] - dp[i - 1][v] - dp[u][j - 1];
            if(sum <= e) return 1;
        }
    }
    return 0;
}

signed main(){
    faster;

    int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
    vvi dp(a + 1, vi(b + 1, 0));

    FOR(i, 1, c){
        int x, y; cin >> x >> y;
        dp[x][y] = 1;
    }

    FOR(i, 1, a){
        FOR(j, 1, b){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + dp[i][j] - dp[i - 1][j - 1];
        }
    }

    int ans = 0;
    int l = 1, r = min(a, b);
    while(l <= r){
        int m = (l + r) / 2;
        int X = m * d;
        if(check(X, a, b, e, dp)){
            l = m + 1;
            ans = X;
        }
        else r = m - 1;
    }
    cout << ans;

    return 0;
}