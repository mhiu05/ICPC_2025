#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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

vector<int> adj[MAXN];
int vs[MAXN];
int ans = 1, cnt = 1;

void dfs(int u){
    vs[u] = 1;
    for(int v : adj[u]){
        if(!vs[v]){
            ++cnt;
            ans = max(ans, cnt);
            dfs(v);
        }
    }
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        memset(vs, 0, sizeof(vs));
        FOR(i, 1, n){
            adj[i].clear();
        }
        ans = 0, cnt = 0;
        FOR(i, 1, m){
            int x, y; cin >> x >> y;
            adj[x].pb(y);
            adj[y].pb(x);
        }

        FOR(i, 1, n){
            if(!vs[i]){
                cnt = 1;
                dfs(i);
            }
        }

        cout << ans << endl;
    }

    return 0;
}