#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
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
const int INF = 1e18;

using namespace std;

int n, m;
int a[MAXN];
multiset<int> st[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id].insert(a[l]);
        return;
    }
    
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    
    for (int x : st[2 * id]) {
        st[id].insert(x);
    }
    for (int x : st[2 * id + 1]) {
        st[id].insert(x);
    }
}

void update(int id, int l, int r, int pos, int old_val, int new_val) {
    auto it = st[id].find(old_val);
    if (it != st[id].end()) {
        st[id].erase(it);
    }
    st[id].insert(new_val);
    
    if (l == r) return;
    
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update(2 * id, l, mid, pos, old_val, new_val);
    } else {
        update(2 * id + 1, mid + 1, r, pos, old_val, new_val);
    }
}

int query(int id, int l, int r, int u, int v, int x) {
    if (v < l || r < u) return INF;
    
    if (u <= l && r <= v) {
        auto it = st[id].upper_bound(x);
        if (it != st[id].end()) {
            return *it;
        }
        return INF;
    }
    
    int mid = (l + r) / 2;
    int query1 = query(2 * id, l, mid, u, v, x);
    int query2 = query(2 * id + 1, mid + 1, r, u, v, x);
    
    return min(query1, query2);
}

signed main() {
    faster;
    
    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    build(1, 1, n);
    
    while (m--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u, val;
            cin >> u >> val;
            update(1, 1, n, u, a[u], val);
            a[u] = val;
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            int res = query(1, 1, n, u, v, x);
            if (res == INF) {
                cout << -1 << endl;
            } else {
                cout << res << endl;
            }
        }
    }
    
    return 0;
}