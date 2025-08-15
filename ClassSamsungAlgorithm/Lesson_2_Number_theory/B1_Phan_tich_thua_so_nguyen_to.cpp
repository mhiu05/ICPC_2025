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
const int MAXN = 1e7 + 7;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

vi primes;
int prime[MAXN];
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
    FOR(i, 0, MAXN - 1){
        if(prime[i]) primes.pb(i);
    }
}

void tsnt(int n, map<int, int> &mp){
    for(int x : primes){
        if(x * x > n) break;
        if(n % x == 0){
            int cnt = 0;
            while(n % x == 0){
                ++cnt;
                n /= x;
            }
            mp[x] += cnt;
        }
    }
    if(n != 1) mp[n]++;
}

signed main(){
    faster;
    sieve();

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