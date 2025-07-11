#include <bits/stdc++.h>
#define ll long long
// #define int long long
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

// Tarjan algorithm: https://wiki.vnoi.info/algo/graph-theory/Depth-First-Search-Tree.md

stack<int> st;
vi on_stack(MAXN), scc_id(MAXN), num(MAXN), low(MAXN);
vvi SCCs; // chứa các đỉnh trong các thành phần liên thông
int scc_count = 0; // số thành phần liên thông
int time_dfs = 0;

int n, m;
int cost[MAXN];
vi dsk[MAXN];


void dfs(int u){
    num[u] = low[u] = ++time_dfs;
    st.push(u);
    on_stack[u] = 1;

    for(int v : dsk[u]){
        if(!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(on_stack[v]){
            low[u] = min(low[u], num[v]);
        }
    }

    if(num[u] == low[u]){
        vi scc;
        while(1){
            int v = st.top(); st.pop();
            on_stack[v] = 0;
            scc_id[v] = scc_count; 
            scc.pb(v);
            if(v == u) break;
        }
        SCCs.pb(scc);
        scc_count++;
    }
}


signed main(){
    faster;

    cin >> n;
    FOR(i, 0, n - 1) cin >> cost[i];
    cin >> m;
    FOR(i, 1, m){
        int x, y; cin >> x >> y;
        --x; --y;
        dsk[x].pb(y);
    }

    FOR(i, 0, n - 1){
        if(!num[i]) dfs(i);
    }

    ll total_cost = 0;
    ll ways = 1;

    for(auto scc : SCCs){
        int min_cost = INT_MAX;
        int cnt = 0;
        for(int u : scc){
            if(cost[u] < min_cost){
                min_cost = cost[u];
                cnt = 1;
            }
            else if(cost[u] == min_cost){
                cnt++;
            }
        }
        
        total_cost += min_cost;
        ways = (ways * cnt) % MOD;
    }

    cout << total_cost << " " << ways;

    return 0;
}