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
const int MAXN = 1e5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int a[MAXN + 5];
vi num;

void snt() {
    for(int i = 0; i <= MAXN; i++) {
        a[i] = 1;
    }
    a[0] = a[1] = 0;
    for(int i = 2; i <= MAXN; i++) {
        if(a[i]) {
            num.push_back(i);
            for(int j = i * i; j <= MAXN; j += i) {
                a[j] = 0;
            }
        }
    }
}

int legendre(int n, int p) {
    int res = 0;
    while (n > 0) {
        n /= p;
        res += n;
    }
    return res;
}

signed main(){
    faster;
    snt();
    
    int n, k;
    while(cin >> n >> k) {
        ll res = 1;
        for(int x : num) {
            if(x > n) break;
            int cnt = 0;
            cnt += legendre(n, x);
            cnt -= legendre(n - k, x);
            cnt -= legendre(k, x);
            res *= (ll)(cnt + 1); // Explicit cast to long long
        }
        cout << res << '\n';
    }
    return 0;
}