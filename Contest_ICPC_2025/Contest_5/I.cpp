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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e18;

using namespace std;

int dist(int x1, int y1, int x2, int y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

signed main(){
    faster;

    vector<ii> v;
    int n; cin >> n;
    FOR(i, 0, n - 1){
        int x, y; cin >> x >> y;
        v.pb({x, y}); 
    }

    FOR(i, 0, n - 1){
        int max_dist = -1;
        int idx = -1;
        FOR(j, 0, n - 1){
            if(i == j) continue;
            int d = dist(v[i].fi, v[i].sc, v[j].fi, v[j].sc);
            if(d > max_dist){
                idx = j + 1;
                max_dist = d;
            }
        }
        cout << idx << endl;
    }
    
    return 0;
}