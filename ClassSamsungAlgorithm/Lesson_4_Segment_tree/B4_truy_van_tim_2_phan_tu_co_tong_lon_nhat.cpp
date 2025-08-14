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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

struct Node{
    int max1, max2;
};

int n, q;
int a[MAXN];
Node st[4 * MAXN];

Node merge(Node l, Node r){
    Node res;
    vi v = {l.max1, l.max2, r.max1, r.max2};
    sort(all(v), greater<int>());
    res.max1 = v[0];
    res.max2 = v[1];
    return res;
}

void build(int id, int l, int r){
    if(l == r){
        st[id] = {a[l], -INF};
        return;
    }

    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);
    
    st[id] = merge(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int u, int val){
    if (l > u || r < u) return;

    if (l == r) {
        st[id] = {val, -INF};
        return;
    }

    int m = (l + r) / 2;
    update(2 * id, l, m, u, val);
    update(2 * id + 1, m + 1, r, u, val);
    
    st[id] = merge(st[2 * id], st[2 * id + 1]);
}

Node get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return {-INF, -INF};

    if (l >= u && r <= v) return st[id];

    int m = (l + r) / 2;
    Node get1 = get(2 * id, l, m, u, v);
    Node get2 = get(2 * id + 1, m + 1, r, u, v);
    
    return merge(get1, get2);
}

signed main(){
    faster;

    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];
    build(1, 1, n);

    while(q--){
        char c; cin >> c;
        if(c == 'U'){
            int u, val; cin >> u >> val;
            update(1, 1, n, u, val);
        }
        else {
            int u, v; cin >> u >> v;
            Node res = get(1, 1, n, u, v);
            cout << res.max1 + res.max2 << endl;
        }
    }

    return 0;
}