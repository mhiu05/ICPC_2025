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

int n, q;
int a[MAXN];
int st[4 * MAXN];

void build(int id, int l, int r){
    if(l == r) {
        st[id] = a[l];
        return;
    }

    int m = (l + r) / 2;
    build(2 * id, l, m);
    build(2 * id + 1, m + 1, r);

    st[id] = st[2 * id] + st[2 * id + 1];
}

void update(int id, int l, int r, int i, int val){
    if(l > i || r < i) return;

    if(l == r){
        st[id] += val;
        return;
    }

    int m = (l + r) / 2;
    update(2 * id, l, m, i, val);
    update(2 * id + 1, m + 1, r, i, val);

    st[id] = st[2 * id] + st[2 * id + 1];
}

int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return 0;

    if(l >= u && r <= v) return st[id];

    int m = (l + r) / 2;
    int get1 = get(2 * id, l, m, u, v);
    int get2 = get(2 * id + 1, m + 1, r, u, v);

    return get1 + get2;
}

signed main(){
    faster;

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    build(1, 1, n);

    cin >> q;
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int u, K; cin >> u >> K;
            update(1, 1, n, u, K);
        }
        else{
            int u, v; cin >> u >> v;
            cout << get(1, 1, n, u, v) << endl;
        }
    }
    return 0;
}