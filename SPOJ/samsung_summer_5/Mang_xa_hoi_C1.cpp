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

// DFS

int n, m;
int vs[MAXN];
vector<int> dsk[MAXN];

void dfs(int u, set<int> &se){
    se.insert(u);
    vs[u] = 1;
    for(int v : dsk[u]){
        if(!vs[v]){
            dfs(v, se);
        }
    }
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        memset(vs, 0, sizeof(vs));
        FOR(i, 1, n) dsk[i].clear();
        int deg[n + 1] = {0};
        FOR(i, 1, m){
            int x, y; cin >> x >> y;
            deg[x]++; deg[y]++;
            dsk[x].pb(y);
            dsk[y].pb(x);
        }
        int ok = 1;
        FOR(i, 1, n){
            set<int> se;
            if(!vs[i]){
                dfs(i, se);
            }
            int total = 0;
            for(int x : se){
                total += deg[x];
            }
            int m = total / 2, n = se.sz(); // m là số cạnh, n là tổng đỉnh trong 1 tplt
            if(m != (n - 1)*n / 2){
                ok = 0;
                break;
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        
    }

    return 0;
}