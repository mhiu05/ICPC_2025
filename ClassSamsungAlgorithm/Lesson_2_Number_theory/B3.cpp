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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// v_p(n!) = số nguyên M lớn nhất sao cho N! chia hết cho p^M.
// legendre's formula: v_p(n!) = [n/p] + [n / p^2] + ......
// Trường hợp m là hợp số (m không phải số nguyên tố) ans = min[v_pi(n!) / r_i]
// m = p1^r1 * .... * pn ^rn


int legendre_formula(int n, int p) {
    int res = 0;
    for (int i = p; i <= n; i *= p) {
        res += n / i;
        if (i > n / p) break;
    }
    return res;
}

int legendre_for_composite(int n, int m)
{
    int res = LLONG_MAX;
    for (int i = 2; i * i <= m; ++i){
        if (m % i == 0)
        {
            int cnt = 0;
            while (m % i == 0)
            {
                ++cnt; 
                m /= i;
            }
            res = min(res, legendre_formula(n, i) / cnt);
        }
    }
    if(m != 1){
        res = min(res, legendre_formula(n, m) / 1);
    }
    return res;
}

signed main(){
    faster;
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        cout << legendre_for_composite(n, k) << endl;
    }

    return 0;
}