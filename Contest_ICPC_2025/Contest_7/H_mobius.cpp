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

vi mobius(int n){
    vi mu(n + 1, 1);
    FOR(i, 2, n){
        if(prime[i]){
            mu[i] = -1;
        }
        else{
            int N = i;
            int k = 0;
            int check = 0;
            for(int p : primes){
                if(p * p > N) break;
                if(N % p == 0){
                    ++k;
                    int cnt = 0;
                    while(N % p == 0){
                        ++cnt;
                        N /= p;
                    }
                    if(cnt >= 2){
                        check = 1;
                        break;
                    }
                }
            }
            if(check){
                mu[i] = 0;
                continue;
            }
            else{
                if(N > 1) ++k;
                if(k % 2 == 0) mu[i] = 1;
                else mu[i] = -1;
            }
        }
    }
    return mu;
}

// n ^ (1 / k)
int nth_root(int n, int k) {
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        __int128 t = 1;
        for (int i = 0; i < k && t <= n; i++) t *= mid;
        if (t <= n) lo = mid;
        else hi = mid - 1;
    }
    return lo;
}

// ans - 1 = (-m[i])*(n^(1/i) - 1) với 2 <= i <= B_max = log2(n) + 1
int solve(int n){
    if(n == 1) return 1;
    
    int B_max = log2(n) + 1;
    vi mu = mobius(B_max);

    int cnt = 0;
    FOR(i, 2, B_max){
        if(mu[i] == 0) continue;

        int r = nth_root(n, i);

        if(r < 2) continue;

        cnt += -mu[i] * (r - 1);
    }

    return cnt + 1; // Thêm số 1
}

signed main(){
    faster;
    sieve();
    
    int n; cin >> n;
    cout << solve(n);

    return 0;
}