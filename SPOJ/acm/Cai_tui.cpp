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

    int n, M; cin >> n >> M;
    int W[n + 1], V[n + 1];
    FOR(i, 1, n){
        int w, v; cin >> w >> v;
        W[i] = w; V[i] = v;
    }

    int dp[n + 1][M + 1] = {0};
    FOR(j, 0, M) dp[0][j] = 0;
    FOR(i, 0, n) dp[i][0] = 0;
    
    FOR(i, 1, n){
        FOR(j, 0, M){
            dp[i][j] = dp[i - 1][j];
            if(j >= W[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - W[i]] + V[i]);
            }
            // cout << i << " " << j << ": " << dp[i][j] << endl;
        }
    }

    cout << dp[n][M];

    return 0;
}