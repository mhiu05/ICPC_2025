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
const int MAXN = 1e2 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// Thuật toán Ford - Fulkerson

int n, m, s, t;

vvi dsk(MAXN, vi(MAXN));
vvi C(MAXN, vi(MAXN));
int vs[MAXN];

int dfs(int u, int d){
    if(u == t) return d;
    vs[u] = 1;
    for(int v : dsk[u]){
        if(!vs[v] && C[u][v]){
            int delta = dfs(v, min(d, C[u][v]));
            if(delta > 0){
                C[u][v] -= delta;
                C[v][u] += delta;
                return delta;
            }
        }
    }
    return 0;
}

int max_flow(){
    int flow = 0;
    while(1){
        memset(vs, 0, sizeof(vs));
        int delta = dfs(s, INF);
        if(delta == 0) break;
        flow += delta;
    }
    return flow;
}

signed main(){
    faster;

    cin >> n >> m >> s >> t;
    FOR(i, 1, m){
        int x, y, c; cin >> x >> y >> c;
        dsk[x].pb(y);
        dsk[y].pb(x);
        C[x][y] += c;
    }

    cout << max_flow();
    return 0;
}