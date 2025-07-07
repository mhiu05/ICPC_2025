#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define int long long
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
const int MAXN = 1e2 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

vvi dp(101, vi(101));

void sieve(){
    FOR(i, 0, 100){
        FOR(j, 0, 100){
            vi mark(101, 0);
            FOR(k, i + 1, j){
                int tmp = k;
                FOR(l, 2, sqrt(k)){
                    while(tmp % l == 0){
                        mark[l]++;
                        tmp /= l;
                    }
                }
                if(tmp > 1) mark[tmp]++;
            }
            ll s = 1;
            FOR(l, 2, 100){
                if(mark[l] > 0){
                    s *= (mark[l] + 1);
                }
            }
            dp[i][j] = s;
        }
    }
}

signed main(){
    faster;
    sieve();

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a == b) cout << 1 << "\n";
        else cout << dp[a][b] << "\n";
    }

    return 0;
}
