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
const int MAXN = 1111111;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int F[10000005], X;


vi primes;
int prime[MAXN];
void sieve1(){
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

int check_snt(int n){
    FOR(i, 2, sqrt(n)){
        if(n % i == 0) return 0;
    }
    return n > 1;
}

int cntDiv(int n){
    int cnt = 1;
    for(int p : primes){
        if(p * p > n) break;
        if(n % p == 0){
            int dem = 0;
            while(n % p == 0){
                ++dem;
                n /= p;
            }
            cnt *= (dem + 1);
        }
    }
    if(n != 1) cnt *= 2;
    return cnt;
}

void sieve(){
    FOR(i, 1, MAXN){
        F[i] = cntDiv(i);
    }
}

int scp(int X){
    int can = sqrt(X);
    return can * can == X;
}

int binpow(int a, int n){
    if(n == 1) return a;
    if(n == 0) return 1;
    int X = binpow(a, n / 2);
    if(n % 2 == 0) return X * X;
    return X * X * a;
}

signed main(){
    faster;
    sieve1();
    sieve();
    
    cin >> X;

    if(X == 0){
        cout << -1;
        return 0;
    }

   int check = 0;
    FOR(i, 1, MAXN){
        int P = binpow(i, F[i]);
        if(P == X){
            check = 1;
            cout << i;
            return 0;
        }
    }

    if(scp(X) && check_snt((int)sqrt(X)) && check == 0){
        cout << (int)sqrt(X);
        return 0;
    }

    if(!check) cout << -1;
    

    return 0;
}