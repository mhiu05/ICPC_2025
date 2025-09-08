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

const ll MOD = 998244353;
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// ans = 3^n - (3|A| - 3|A giao B|)
// |A|: số cách R >= ceil(S / 2)

int n; 
int a[301];

int POW(int x, int n) {
    int res = 1;
    FOR(i, 1, n){
        res *= x;
        res %= MOD;
    }
    return res;
}

signed main(){
    faster;
    cin >> n;
    int S = 0;
    FOR(i, 1, n) {
        cin >> a[i];
        S += a[i];
    }

    int total = POW(3, n);

    vi dpcnt(S + 1, 0); //subset-sum dp basic
    vi dpw(S + 1, 0);
    dpcnt[0] = 1;
    dpw[0] = 1;

    int inv2 = (MOD + 1) / 2;

    int currentSum = 0;
    FOR(i, 1, n) {
        int x = a[i];
        FOD(s, currentSum + x, 0) {
            if (s - x >= 0) {
                dpcnt[s] = (dpcnt[s] + dpcnt[s - x]) % MOD;
                dpw[s] = (dpw[s] + dpw[s - x] * inv2) % MOD ;
            }
        }
        currentSum += x;
    }

    // Threshold: ceil(S/2)
    int thr = (S + 1) / 2;
    int pow2N = POW(2, n);
    int bad = 0;
    for (int s = thr; s <= S; s++) {
        bad = (bad + dpw[s] * 1LL * pow2N) % MOD;
    }

    int bad_total = 3 * bad % MOD;
    if (S % 2 == 0) {
        bad_total =  (bad_total % MOD - 3 * dpcnt[S/2] % MOD + MOD) % MOD;
    }

    int ans = (total - bad_total) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans << endl;
    return 0;
}
