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

const ll base = 31;
const ll MOD2 = 111539786; 
const ll MOD1 = 1e9 + 7;
const int MAXN = 1e6 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int h1[MAXN], h2[MAXN], mu1[MAXN], mu2[MAXN];

int get_hash1(int l, int r){
    return (h1[r] - h1[l - 1] * mu1[r - l + 1] % MOD1 + MOD1) % MOD1;
}
int get_hash2(int l, int r){
    return (h2[r] - h2[l - 1] * mu2[r - l + 1] % MOD2 + MOD2) % MOD2;
}

signed main(){
    faster;

    string a, b; cin >> a >> b;
    a = "." + a;

    mu1[0] = 1; mu2[0] = 1;
    FOR(i, 1, a.sz() - 1){
        h1[i] = (h1[i - 1] * base + (a[i] - '0' + 1)) % MOD1;
        mu1[i] = (mu1[i - 1] * base) % MOD1;
        h2[i] = (h2[i - 1] * base + (a[i] - '0' + 1)) % MOD2;
        mu2[i] = (mu2[i - 1] * base) % MOD2;
    }

    int hash1 = 0, hash2 = 0;
    FOR(i, 0, b.sz() - 1){
        hash1 = (hash1 * base + (b[i] - '0' + 1)) % MOD1;
        hash2 = (hash2 * base + (b[i] - '0' + 1)) % MOD2;
    }

    vi ans;
    FOR(i, 1, a.sz() - b.sz()){
        if(hash1 == get_hash1(i, i + b.sz() - 1) && hash2 == get_hash2(i, i + b.sz() - 1)) ans.pb(i);
    }

    FOR(i, 0, ans.sz() - 1) cout << ans[i] << " ";

    return 0;
}