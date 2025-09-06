#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxN = 100005;

int n, q;
ll dp[maxN];
int parent[maxN], sz[maxN];
vector<int> adj[maxN];
set<pair<int, int>> children[maxN]; // stores {-size, child} for each node

void dfs(int u, int p) {
    parent[u] = p;
    sz[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
        dp[u] += dp[v];
        children[u].insert({-sz[v], v});
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
    }
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    while (q--) {
        int type, u;
        cin >> type >> u;
        if (type == 1) {
            cout << dp[u] << '\n';
        } else {
            if (u == 1 || children[u].empty()) continue;

            auto it = children[u].begin();
            int heavy_child = it->second;
            int p = parent[u];

            // Remove u from its parent's children set
            children[p].erase({-sz[u], u});
            // Remove the heavy child from u's children set
            children[u].erase(it);

            // Update sizes and dp values
            sz[u] -= sz[heavy_child];
            dp[u] -= dp[heavy_child];
            sz[heavy_child] += sz[u];
            dp[heavy_child] += dp[u];

            // Update parent relationships
            parent[u] = heavy_child;
            parent[heavy_child] = p;

            // Add the heavy child to the parent's children set
            children[p].insert({-sz[heavy_child], heavy_child});
            // Add u to the heavy child's children set
            children[heavy_child].insert({-sz[u], u});
        }
    }

    return 0;
}