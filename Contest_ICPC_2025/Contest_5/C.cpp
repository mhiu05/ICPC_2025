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

int pttsnt(int n, int p){
    int ans = 1;
    int N = p;
    for(int prime : primes){
        if(prime * prime > N) break;
        if(N % prime == 0){
            int cnt = 0;
            while(N % prime == 0){
                ++cnt;
                N /= prime;
            }
            if(cnt >= n){
                // cout << prime << endl;
                int k = cnt / n;
                FOR(i, 1, k){
                    ans *= prime;
                }
            }
        }
    }
    if(N != 1){
        if(n == 1) ans *= N;
    }
    return ans;
}

signed main(){
    faster;
    sieve();

    int n, p; cin >> n >> p;

    if(n == 1) {
        cout << p;
        return 0;
    }

    if(p == 1){
        cout << 1;
        return 0;
    }

    cout << pttsnt(n, p);

    return 0;
}