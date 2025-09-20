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

const ll MOD = 998244353;
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// Chia thành nhiều nhóm, mỗi nhóm gồm: x, x + k, x + 2k,....
// Tính số cách chọn trong mỗi nhóm, ans = tích các số cách chọn đó

int binpow(int x, int n){
    if(n == 1) return (x % MOD);
    if(n == 0) return 1;
    int X = binpow(x, n / 2);
    if(n % 2 == 0){
        return (X % MOD) * (X % MOD) % MOD;
    }
    else{
        return (((X % MOD) * (X % MOD)) % MOD) * (x % MOD) % MOD;
    }
}

void solve(){
    int n, k; cin >> n >> k;
    int a[n + 1];

    map<int, int> mp;
    FOR(i, 1, n) {
        cin >> a[i];
        mp[a[i]]++;
    }

    vi A; // chứa các phần tử riêng biệt trong a[] theo thứ tự tăng dần
    for(auto it : mp){
        A.pb(it.fi);
    }

    set<int> visited;
    int ans = 1;
    FOR(i, 0, A.sz() - 1){
        if(visited.count(A[i])) continue;

        vi v;
        int cur = A[i];
        while(mp.count(cur)){
            v.pb(cur);
            visited.insert(cur);
            cur += k;
        }

        int dp0 = 1, dp1 = 0;
        FOR(j, 0, v.sz() - 1){
            int new_dp0 = (dp0 + dp1) % MOD;
            int new_dp1 = (dp0 * (binpow(2, mp[v[j]]) - 1)) % MOD;
            dp0 = new_dp0;
            dp1 = new_dp1;
        }
        int ways = (dp0 + dp1) % MOD;
        ans *= ways;
        ans %= MOD;
    }
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << endl;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}