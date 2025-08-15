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
const int MAXN = 1e7 + 5;
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

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        map<int, int> mp;
        int n; cin >> n;
        tsnt(n, mp);
        for(auto it : mp){
            cout << it.fi << " " << it.sc << endl;
        }
    }
    return 0;
}