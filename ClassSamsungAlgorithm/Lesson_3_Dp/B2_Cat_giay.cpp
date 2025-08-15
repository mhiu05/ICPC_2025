#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int a, b,c, d, e;
int dp[6001][6001];

int check(int len){
    FOR(i, 1, a - len + 1){
        FOR(j, 1, b - len + 1){
            int u = i + len - 1, v = j + len - 1;
            int sum = dp[u][v] - dp[i - 1][v] - dp[u][j - 1] + dp[i - 1][j - 1];
            if(sum <= e) return 1;
        }
    }
    return 0;
}

signed main(){
    faster;

    cin >> a >> b >> c >> d >> e;

    FOR(i, 1, c){
        int x, y; cin >> x >> y;
        dp[x][y] = 1;
    }

    FOR(i, 1, a){
        FOR(j, 1, b){
            dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int l = 1, r = min(a, b) / d, max_len = 0;
    while(l <= r){
        int m = (l + r) / 2;
        if(check(m * d)){
            max_len = m * d;
            l = m + 1;
        }
        else r = m - 1;
    }

    cout << max_len;

    return 0;
}