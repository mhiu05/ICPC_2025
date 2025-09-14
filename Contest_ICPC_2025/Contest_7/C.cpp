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

signed main(){
    faster;

    int N, Q;
    cin >> N >> Q;

    vector<int> a(N+1);
    for (int i = 1; i <= N; ++i) cin >> a[i];

    vector<int> p(N+1, 0);
    p[1] = 0;
    for (int i = 2; i <= N; ++i) {
        cin >> p[i];
    }

    while (Q--) {
        int x, y;
        cin >> x >> y;
        long long ans = 0;
        while (x != 0 && y != 0) {
            ans += 1LL * a[x] * a[y];
            x = p[x];
            y = p[y];
        }
        cout << ans << '\n';
    }

    return 0;
}