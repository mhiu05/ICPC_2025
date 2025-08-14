#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int MAXN = 2e5 + 5;
const double EPS = 1e-10;
const int INF = 1e18;

using namespace std;

int n, q;
int a[MAXN];
int st[4 * MAXN];

int better(int idx1, int idx2) {
    if (idx1 == -1) return idx2;
    if (idx2 == -1) return idx1;
    if (a[idx1] < a[idx2]) return idx1;
    if (a[idx1] > a[idx2]) return idx2;
    return min(idx1, idx2);
}

void build(int id, int l, int r){
    if(l == r){
        st[id] = l;
        return;
    }   

    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);

    st[id] = better(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int i) {
    if (l > i || r < i) return; 
    if (l == r) return;
    
    int m = (l + r) / 2;
    update(2 * id, l, m, i);
    update(2 * id + 1, m + 1, r, i);
    
    st[id] = better(st[2 * id], st[2 * id + 1]); 
}

int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return -1;

    if(l >= u && r <= v) return st[id];

    int m = (l + r) / 2;
    int get1 = get(2 * id, l, m, u, v);
    int get2 = get(2 * id + 1, m + 1, r, u, v);

    return better(get1, get2);
}

signed main(){
    faster;

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    build(1, 1, n);

    while(q--){
        int x; cin >> x;
        if(x == 1){
            int u, val; cin >> u >> val;
            a[u] = val;
            update(1, 1, n, u);
        }
        else{
            int u, v; cin >> u >> v;
            cout << get(1, 1, n, u, v) << endl;
        }
    }

    return 0;
}