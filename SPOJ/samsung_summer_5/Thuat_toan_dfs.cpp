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

int n, m, u;
vector<int> dsk[1005];
int vs[1005];

void dfs(int k){
    cout << k << " ";
    vs[k] = 1;
    for(int v : dsk[k]) {
        if(!vs[v]) {
            dfs(v);
        }
    }
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){ 
        cin >> n >> m >> u;

        memset(vs, 0, sizeof(vs));
        FOR(i, 0, n){
            dsk[i].clear();
        }

        FOR(i, 1, m){
            int x, y; cin >> x >> y;
            dsk[x].pb(y);
            dsk[y].pb(x);
        }
        
        dfs(u);
        cout << endl;
    }

    return 0;
}