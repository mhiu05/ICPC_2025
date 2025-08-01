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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

signed main(){
    faster;

    int n; cin >> n;
    int a[n + 5];
    FOR(i, 1, n) cin >> a[i];
    
    int j_2 = 1, j_24 = 1;
    vi dp(n + 5, 0);
    FOR(i, 1, n){
        while(j_2 <= i && a[i] - a[j_2] > 119) j_2++;
        while(j_24 <= i && a[i] - a[j_24] > 1439) j_24++;
        
        ll cost1 = dp[i-1] + 6000;
        ll cost2 = dp[j_2-1] + 15000;
        ll cost3 = dp[j_24-1] + 40000;

        dp[i] = min({cost1, cost2, cost3});
    }
    FOR(i, 1, n) cout << dp[i] - dp[i - 1] << " ";
    return 0;
}
