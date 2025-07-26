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

// Đồ thị 2 phía: tô màu đồ thị

int a[101][101];
vi dsk[101];
int n;
int color[101];

bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 1;

    while(!q.empty()){
        int s = q.front(); q.pop();
        for(int v : dsk[s]){
            if(color[v] == -1){
                color[v] = 1 - color[s];
                q.push(v);
            }
            else{
                if(color[v] == color[s]) return false;
            }
        }
    }

    return true;
}

signed main(){
    faster;

    while(1){
        cin >> n;
        if(n == 0) break;

        FOR(i, 1, n) dsk[i].clear();
        memset(color, -1, sizeof(color));

        FOR(i, 1, n){
            FOR(j, 1, n){
                cin >> a[i][j];
                if(a[i][j]) dsk[i].pb(j);
            }
        }
        
        int check = 1;
        FOR(i, 1, n){
            if(color[i] == -1){
                if(!bfs(i)) check = 0;
            }
        }

        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}