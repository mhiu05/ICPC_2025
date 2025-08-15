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
const int MAXN = 1e6 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int prime[MAXN];
vi prs;
void sieve(){
    FOR(i, 0, MAXN - 1){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i < MAXN; ++i){
        if(prime[i]){
            for(int j = i * i; j < MAXN; j += i){
                prime[j] = 0;
            }
        }
    }
    FOR(i, 2, MAXN - 1){
        if(prime[i]) prs.pb(i);
    }
}

int legendre(int n, int p){
    int res = 0;
    for(int i = p; i <= n; i *= p){
        res += n / i;
        if(i > n / p) break;
    }
    return res;
}

vi v;
void solve(int k, int n){
    int ans = LLONG_MAX;
    for(int x : prs){
        if(x * x > k) break;
        if(k % x == 0){
            int cnt = 0;
            while(k % x == 0){
                ++cnt;
                k /= x;
            }
            ans = min(ans, legendre(n, x) / cnt);
        }
    }
    if(k != 1) {
        ans = min(ans, legendre(n, k));
    }
    cout << ans << endl;
}

signed main(){
    faster;
    sieve();

    int t;cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        solve(k, n);
    }

    return 0;
}