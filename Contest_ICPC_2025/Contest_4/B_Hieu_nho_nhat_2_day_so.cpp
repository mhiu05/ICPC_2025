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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e18;

using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    int a[n + 1], b[m + 1];
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int ans = INF;
    int i = 1, j = 1;
    while(i <= n && j <= m){
        if(a[i] == b[j]) {
            cout << 0 << endl;
            return;
        }
        else if(a[i] < b[j]){
            ans = min(ans, b[j] - a[i]);
            ++i;
        }
        else{
            ans = min(ans, a[i] - b[j]);
            ++j;
        }
    }

    while(i <= n){
        ans = min(ans, abs(b[m] - a[i]));
        ++i;
    }
    while(j <= m){
        ans = min(abs(a[n] - b[j]), ans);
        ++j;
    }

    cout << ans << endl;
}

signed main(){
    faster;

    int t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}