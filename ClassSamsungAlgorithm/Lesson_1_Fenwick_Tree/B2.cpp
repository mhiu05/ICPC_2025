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

int bit[MAXN];
int a[MAXN], n, q;

void updatePoint(int u, int k){
    int idx = u;
    while(idx <= n){
        bit[idx] += k;
        idx += (idx & (-idx));
    }
}

void updateRange(int u, int v, int k){
    updatePoint(u, k);
    updatePoint(v + 1, -k);
}

int get(int u){
    int idx = u, ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

signed main(){
    faster;

    cin >> n;
    FOR(i, 1, n){
        cin >> a[i];
    }

    cin >> q;
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int u, v, k; cin >> u >> v >> k;
            updateRange(u, v, k);
        }
        else{
            int u; cin >> u;
            cout << a[u] + get(u) << endl;
        }
    }

    return 0;
}