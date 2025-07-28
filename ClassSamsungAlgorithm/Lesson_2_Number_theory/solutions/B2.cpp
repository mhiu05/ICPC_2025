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
const int MAXN = 1e7 + 1;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// spf: small prime factor
vi spf(MAXN, 1);

void sieve(){
    for (int i = 2; i < MAXN; ++i) spf[i] = i;
    for (int i = 2; i * i < MAXN; ++i){
        if (spf[i] == i){
            for (int j = i * i; j < MAXN; j += i){
                if (spf[j] == j){
                    spf[j] = i; 
                }
            }
        }
    }
}

void tsnt(ll x, map<int, int> &mp){
    if (x < MAXN){
        while(x != 1){
            mp[spf[x]]++;
            x /= spf[x];
        }
    } else {
        for (ll i = 2; i*i <= x; ++i){
            while (x % i == 0){
                mp[i]++;
                x /= i;
            }
        }
        if (x > 1) mp[x]++;
    }
}


int n, m;
int a[101], b[101][101];

signed main(){
    faster;
    sieve();
        
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m){
        FOR(j, 1, n){
            cin >> b[i][j];
        }
    }

    map<int, int> mp;
    mp[1] = INF;
    FOR(i, 1, n){
        tsnt(a[i], mp);
    }

    vi ans;
    FOR(i, 1, m){
        map<int, int> mp1;
        FOR(j, 1, n){
            tsnt(b[i][j], mp1);
        }

        int check = 1;
        for(auto it : mp1){
            if(it.sc > mp[it.fi]){
                check = 0;
                break;
            }
        }
        if(check){
            ans.pb(i);
        }
    }

    cout << ans.sz() << endl;
    for(int x : ans) cout << x << " ";

    return 0;
}