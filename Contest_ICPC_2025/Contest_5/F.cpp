#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pf push_front
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

vi sieve(){
    vi res(MAXN, INF);
    res[1] = 0;
    FOR(i, 1, MAXN - 1){
        FOR(x, 1, i){
            int j = i + i / x;
            if(j < MAXN){
                res[j] = min(res[j], res[i] + 1);
            } 
        }
    }
    return res;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int b[n + 1], c[n + 1];
        FOR(i, 1, n) cin >> b[i];
        FOR(i, 1, n) cin >> c[i];

        vi sie = sieve();
        // cout << sie[1000] << endl;
        int total_w = 0;
        vi w(n + 1), v(n + 1);
        FOR(i, 1, n){
            w[i] = sie[b[i]];
            v[i] = c[i];
            total_w += w[i];
        }

        int cap = min({total_w, k, 12000LL});
        vvi dp(n + 1, vi(cap + 1, 0));
        FOR(i, 1, n){
            FOR(j, 0, cap){
                if(j < w[i]){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
                }
            }
        }

        int ans = 0;
        FOR(i, 0, cap){
            ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
    }

    return 0;
}