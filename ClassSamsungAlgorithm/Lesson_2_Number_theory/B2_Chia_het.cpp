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
const int MAXN = 4e7 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

vi v;
int prime[MAXN];
void sieve(){
    FOR(i, 0, MAXN - 1){
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for(int i = 2; i * i < MAXN; ++i){
        if(prime[i]){
            for(int j = i * i; j < MAXN; j += i){
                prime[j]= 0;
            }
        }
    }
    FOR(i, 2, MAXN - 1){
        if(prime[i]) v.pb(i);
    }
}

void solve(int n, map<int, int> &mp){
    for(int x : v){
        if(x * x > n) break;
        while(n % x == 0){
            mp[x]++;
            n /= x;
        }
    }
    if(n != 1) mp[n]++;
}

signed main(){
    faster;
    sieve();
    
    int n, m; cin >> n >> m;
    vi a(n + 1);
    FOR(i, 1, n) cin >> a[i];
    map<int, int> mp1;
    FOR(i, 1, n){
        solve(a[i], mp1);
    }

    vi ans;
    FOR(idx, 1, m){
        vi b(n + 1);
        FOR(i, 1, n) cin >> b[i];
        map<int, int> mp2;
        FOR(i, 1, n){
            solve(b[i], mp2);
        }
        int ok = 1;
        for(auto it : mp2){
            if(it.sc > mp1[it.fi]){
                ok = 0;
                break;
            }
        }
        if(ok){
            ans.pb(idx);
        }
    }

    cout << ans.sz() << endl;
    for(int x : ans) cout << x << " ";

    return 0;
}