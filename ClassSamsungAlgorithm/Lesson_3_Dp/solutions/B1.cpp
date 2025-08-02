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

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n + 1][m + 1];
        memset(a, 0, sizeof(a));
        FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        FOR(i, 1, n){
            FOR(j, 1, m){
                if(a[i][j]){
                    if(a[i - 1][j] == 1 && a[i - 1][j - 1] == 1 && a[i][j - 1] == 1){
                        dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                    }
                    else dp[i][j] = 1;
                    ans = max(ans, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}