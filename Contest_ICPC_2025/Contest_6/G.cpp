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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int n;
int a[MAXN];
bool isPrime[MAXN];
vi primes;

void sieve(){
    FOR(i, 0, MAXN - 1) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    FOR(i, 2, sqrt(MAXN)){
        if(isPrime[i]){
            for(int j = i * i; j < MAXN; j += i){
                isPrime[j] = false;
            }
        }
    }
    FOR(i, 2, MAXN - 1){
        if(isPrime[i]) primes.pb(i);
    }
}

set<int> getPrimeFactors(int n){
    set<int> res;
    if(n == 0) return res;
    for(int x : primes){
        if(x * x > n) break;  
        if(n % x == 0){
            res.insert(x);
            while(n % x == 0){
                n /= x;
            }
        }
    }
    if(n != 1) res.insert(n);
    return res;
}

// kiểm tra tất cả các hệ số % p = 0
bool checkDivisible(int p){
    vi v(p, 0);
    FOR(i, 0, n){
        int m; // số mũ với chu kỳ p - 1
        if(i == 0){
            m = 0;
        }
        else{
            if(p == 2){
                m = 1;
            }
            else{
                m = (i - 1) % (p - 1) + 1;
            }
        }
        
        int val = (a[i] % p + p) % p; 
        v[m] = (v[m] + val) % p;
    }

    FOR(i, 0, p - 1){
        if(v[i] != 0){
            return false;
        }
    }
    return true;
}

signed main(){
    faster;
    sieve();

    cin >> n;
    FOD(i, n, 0) cin >> a[i];

    int gcd_val = 0;
    FOR(i, 0, n){
        gcd_val = __gcd(gcd_val, abs(a[i]));
    }

    set<int> ans = getPrimeFactors(gcd_val);

    for(int x : primes){
        if(x > n) break;
        if(ans.count(x)) continue;
        if(checkDivisible(x)) ans.insert(x);
    }

    for(int x : ans) cout << x << endl;

    return 0;
}