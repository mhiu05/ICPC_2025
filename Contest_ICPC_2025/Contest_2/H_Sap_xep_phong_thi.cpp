#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pf push_front
#define pb push_back
// #define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int parent[MAXN+5];
int sz[MAXN+5];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v]) return v; 
    int p = find_set(parent[v]); 
    parent[v] = p;
    return p;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b); 
        parent[b] = a;
        sz[a] += sz[b]; 
    }
}   

int n, m;

signed main(){
    faster;

    cin >> n >> m;
    FOR(i, 1, n){
        make_set(i);
    }
    FOR(i, 1, m){
        int x, y; cin >> x >> y;
        union_sets(x, y);
    }

    int ans = 0;
    FOR(i, 1, n) ans = max(ans, sz[i]);
    cout << ans;

    return 0;
}