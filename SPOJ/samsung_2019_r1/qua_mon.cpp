#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    FOR(i, 1, n) cin >> a[i];

    vector<ii> p(m);
    FOR(i, 0, m - 1) cin >> p[i].fi >> p[i].sc;

    sort(all(p)); 

    vi diff(m + 1);
    vector<ll> dp(m + 1);
    dp[0] = 0;
    FOR(i, 1, m) {
        diff[i] = p[i - 1].fi;
        dp[i] = dp[i - 1] + p[i - 1].sc;
    }

    FOR(i, 1, n) {
        int x = a[i];
        int pos = upper_bound(diff.begin() + 1, diff.end(), x) - diff.begin() - 1;
        if(pos < 0 || pos > m) cout << 0 << ' ';
        else cout << dp[pos] << ' ';
    }

    return 0;
}
