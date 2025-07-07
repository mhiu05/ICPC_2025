#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
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

// Thuật toán prim

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<pair<double, double>> v (n + 1);
        double ans = 0.0;

        FOR(i, 1, n){
            double a, b; cin >> a >> b;
            v[i] = {a, b};
        }

        vector<bool> vis(n + 1, false);
        vector<double> dist(n + 1, 1e18);

        dist[1] = 0.0;

        FOR(k, 1, n){
            // tìm đỉnh u có trọng số nhỏ nhất nằm trong tập V
            int u = -1;
            FOR(i, 1, n){
                if(!vis[i] && (u == -1 || dist[i] < dist[u])){
                    u = i;
                }
            }

            vis[u] = true;
            ans += dist[u];

            // cập nhật trọng số các đỉnh nằm trong tập V
            FOR(i, 1, n){
                if(!vis[i]){
                    double dx = v[u].fi - v[i].fi;
                    double dy = v[u].sc - v[i].sc;
                    double d = sqrt(dx * dx + dy * dy);
                    dist[i] = min(dist[i], d);
                }
            }
        }

        cout << fixed << setprecision(6) << ans << '\n';
    }

    return 0;
}
