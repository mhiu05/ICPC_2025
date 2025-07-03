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

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n, m, u; cin >> n >> m >> u;
        vi dsk[n + 1];
        vi vs(n + 1, 0);
        FOR(i, 1, m){
            int x, y; cin >> x >> y;
            dsk[x].pb(y);
            dsk[y].pb(x);
        }

        queue<int> q;
        q.push(u);
        vs[u] = 1;
        while(!q.empty()){
            int s = q.front(); q.pop();
            cout << s << " ";
            for(int v : dsk[s]){
                if(!vs[v]){
                    q.push(v);
                    vs[v] = 1;
                }
            }
        }
        cout << endl;
    }

    return 0;
}