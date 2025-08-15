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

int cmp(ii a, ii b){
    return a.fi < b.fi;
}

signed main(){
    faster;

    int n; cin >> n;
    vector<ii> v;
    int ans = 0;
    FOR(i, 1, n){
        int x, y; cin >> x >> y;
        ans += y;
        v.pb({x, y});
    }

    sort(all(v), cmp);

    int maxx = v[0].fi + v[0].sc;
    FOR(i, 1, n - 1){
        int h = v[i].fi, p = v[i].sc;
        ans += max(0ll, h - maxx);
        maxx = max(maxx, h + p);
    }
    cout << ans;

    return 0;
}