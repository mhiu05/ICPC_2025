#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
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
const int MAXN = 1e3 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int n, m, q;
string s[MAXN];
int dist[MAXN][MAXN];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void solve(){
    FOR(i, 0, n - 1) FOR(j, 0, m - 1) dist[i][j] = INF;
    
    deque<ii> dq;
    FOR(i, 0, n - 1){
        FOR(j, 0, m - 1){
            if(s[i][j] == '*'){
                dist[i][j] = 0;
                dq.pf({i, j});
            }
        }
    }

    while(!dq.empty()){
        int x = dq.front().fi, y = dq.front().sc;
        dq.pop_front();
        FOR(i, 0, 3){
            int x1 = x + dx[i], y1 = y + dy[i];
            if(x1 >= 0 && x1 < n && y1 >= 0 && y1 < m){
                int add = 0;
                if(s[x1][y1] != s[x][y]) add = 1;
                if(dist[x1][y1] > dist[x][y] + add){
                    dist[x1][y1] = add + dist[x][y];
                    if(add == 0) dq.pf({x1, y1});
                    else dq.pb({x1, y1});
                }
            }
        }
    }
} 

signed main(){
    faster;

    cin >> n >> m >> q;
    FOR(i, 0, n - 1){
        cin >> s[i];
    }

    solve();

    while(q--){
        int x, y; cin >> x >> y;
        --x; --y;
        cout << dist[x][y] << endl;
    }

    return 0;
}