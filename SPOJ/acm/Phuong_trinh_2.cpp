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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

signed main(){
    faster;
    ll n;
    cin >> n;

    ll res = 1;
    for (ll i = 2; i * i <= n; ++i) {
        int cnt = 0;
        while (n % i == 0) {
            ++cnt;
            n /= i;
        }
        if (cnt > 0) res *= (2 * cnt + 1);
    }
    if (n > 1) res *= 3; 

    cout << res << '\n';
    
    return 0;
}