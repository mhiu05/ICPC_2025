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

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int a[n + 1][m + 1];
        FOR(i, 1, n){
            FOR(j, 1, m){ 
                cin >> a[i][j];
            }
        }
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));
        FOR(i, 1, n){
            FOR(j, 1, m){
                if(i == 1) dp[i][j] = dp[i][j - 1] + a[i][j];
                else if(j == 1) dp[i][j] = dp[i - 1][j] + a[i][j];
                else dp[i][j] = min({dp[i - 1][j - 1] + a[i][j], dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]});
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}