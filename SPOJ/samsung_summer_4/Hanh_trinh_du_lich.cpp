#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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

// chưa AC

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1][n + 1];
        FOR(i, 0, n - 1){
            FOR(j, 0, n - 1){
                cin >> a[i][j];
            }
        }

        vvi dp((1 << n), vi(n, INF));
        FOR(i, 0, n - 1){
            dp[1 << i][i] = 0;
        }

        FOR(mask, 0, (1 << n) - 1){
            FOR(i, 0, n - 1){
                if(!(mask & (1 << i))) continue;
                if(dp[mask][i] == INF) continue;

                FOR(j, 0, n - 1){   
                    if((mask & (1 << j))) continue;

                    int new_mask = mask | (1 << j);
                    int new_cost = dp[mask][i] + a[i][j];
                    if(new_cost < dp[new_mask][j]){
                        dp[new_mask][j] = new_cost;
                    }
                }
            }
        }

        int res = INF;
        FOR(i, 0, n - 1){
            res = min(res, dp[(1 << n) - 1][i]);
        }
        cout << res << endl;
    }

    return 0;
}