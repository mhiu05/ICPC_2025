#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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

// thuật toán DSU

int n, m; 
int Size[MAXN]; // số đỉnh trong tập hợp
int edges[MAXN]; // số cạnh trong tập hợp
int parent[MAXN];

void make_set(int u){
    parent[u] = u;
    Size[u] = 1;
    edges[u] = 0;
}

int find_set(int u){
    if(u == parent[u]) return u;
    return find_set(parent[u]);
}

void union_set(int x, int y){
    int a = find_set(x);
    int b = find_set(y);
    if(a != b){
        parent[b] = a;
        Size[a] += Size[b];
        edges[a] += edges[b] + 1;
    }
    else edges[a]++;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        cin >> n >> m;
        FOR(i, 1, n) make_set(i);
        FOR(i, 1, m){
            int x, y; cin >> x >> y;
            union_set(x, y);
        }

        int ok = 1;
        set<int> se;
        FOR(i, 1, n){
            int root = find_set(i);
            if(se.count(i)) continue;
            se.insert(i);

            int k = Size[root];
            int m = k * (k - 1) / 2;
            if(m !=  edges[root]){
                ok = 0;
                break;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}