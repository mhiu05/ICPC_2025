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

signed main(){
    faster;

    int n; cin >> n;
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];

    int F[n + 1] = {0};
    FOR(i, 1, n){
        F[i] = F[i - 1] + a[i];
    }

    vector<int> suffix_min(n+2, 1e9);
    for(int i=n; i>=1; --i){
        suffix_min[i] = min(a[i], suffix_min[i+1]);
    }

    // FOR(i, 1, n) cout << F[i] << " ";
    // cout << endl;

    vi ans;
    double max_val = -1;
    FOR(i, 1, n - 2){
        int min_ele = suffix_min[i + 1];
        double X = 1.0 * (1.0 * F[n] - F[i] - min_ele) / (n - 1 - i);
        // cout << F[n] << " " << F[i] << " " << i << " " << X << " " << min_ele << endl;
        max_val = max(max_val, X);
    }

    FOR(i, 1, n - 2){
        int min_ele = suffix_min[i + 1];
        double X = 1.0 * (1.0 * F[n] - F[i] - min_ele) / (n - 1 - i);
        if(max_val == X) ans.pb(i);
    }

    if(!ans.sz()){
        cout << 0;
        return 0;
    }

    sort(ans.begin(), ans.end());
    FOR(i, 0, ans.sz() - 1) cout << ans[i] << " ";

    return 0;
}