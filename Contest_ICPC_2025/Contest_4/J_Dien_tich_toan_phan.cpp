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
const int MAXN = 1e3 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int a[MAXN][MAXN];

void solve(){
    int n, m; cin >> m >> n;
    memset(a, 0, sizeof(a));
    FOR(i, 1, m){
        FOR(j, 1, n){
            cin >> a[i][j];
        }
    }

    int area = 0;
    // cout << area << endl;
    FOR(i, 1, m){
        FOR(j, 1, n){
            if(a[i][j] == 0) continue;

            area += 2;

            FOR(k, 0, 3){
                int i1 = i + dx[k], j1 = j + dy[k];
                // cout << a[i][j] << " " << a[i1][j1] << endl;
                if(a[i][j] > a[i1][j1]){
                    area += a[i][j] - a[i1][j1];
                }
            }
        }
    }

    cout << area << endl;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}