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
const int MAXN1 = 5e2 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// gcd(a_i + k * c_i) = g
// c_i = a_i mod (k + 1) .... g = k + 1 >= 2 (thỏa mãn)

void solve(){
    int n, k; cin >> n >> k;
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        cout << a[i] + k * (a[i] % (k + 1)) << " ";
    }
    cout << endl;
}

signed main(){
    faster;
    
    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}