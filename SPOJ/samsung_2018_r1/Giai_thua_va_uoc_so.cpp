#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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
const int MAXN = 1e2 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

vector<int> spf(MAXN + 1, 1);
void sieve(){
    spf[0] = spf[1] = 1; 
    for(int i = 2; i <= MAXN; i++){
        if(spf[i] == 1){
            for(int j = i; j * j <= MAXN; j += i){
                if(spf[j] == 1) spf[j] = i;
            }
        }
    }
}

void tsnt_sieve(int n, map<int, ll> &mp){
    while(n > 1){
        mp[spf[n]]++;
        n /= spf[n];
    }
}

signed main(){
    faster;
    sieve();
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        map<int, ll> mp;
        FOR(i, a + 1, b){
            tsnt_sieve(i, mp);
        }
        ll ans = 1;
        for(auto it : mp){
            ans *= (it.second + 1);
        }
        cout << ans << endl;
    }

    return 0;
}
