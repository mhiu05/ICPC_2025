#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct PairHash {
    size_t operator()(const pair<int, int> &p) const noexcept {
        return ((size_t)p.first << 32) ^ (size_t)p.second;
    }
};

class DSU {
public:
    int n;
    vector<int> par, sz;

    DSU(int n) {
        this->n = n;
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int FIND(int u) {
        if (par[u] == u) return u;
        return par[u] = FIND(par[u]);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> edges;
    edges.reserve(2 * n);

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edges.emplace_back(u, v);
    }

    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        edges.emplace_back(u, v);
    }

    vector<multiset<int>> adj(n + 1);
    unordered_map<pair<int, int>, int, PairHash> mp;
    for (auto [u, v] : edges) {
        adj[u].insert(v);
        adj[v].insert(u);
        mp[{u, v}]++;
    }

    queue<pair<int, int>> q;
    for (auto &it : mp) {
        if (it.second >= 2) {
            q.push(it.first);
        }
    }

    DSU dsu(n);
    int steps = 0;

    while (steps < n - 1) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            x = dsu.FIND(x);
            y = dsu.FIND(y);
            if (x == y) continue;
            if (dsu.sz[x] > dsu.sz[y]) swap(x, y);
            dsu.par[x] = y;
            dsu.sz[y] += dsu.sz[x];
            steps++;

            for (int z : adj[x]) {
                int nz = dsu.FIND(z);
                auto itNz = adj[nz].find(x);
                if (itNz != adj[nz].end()) {
                    adj[nz].erase(itNz);
                }
                if (nz == y) continue;
                adj[nz].insert(y);
                adj[y].insert(nz);
                pair<int, int> nEdge = {min(nz, y), max(nz, y)};
                if (++mp[nEdge] == 2) {
                    q.push(nEdge);
                }
            }
            adj[x].clear();
            break;
        }
        if (steps == n - 1) break;
        if (q.empty()) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}