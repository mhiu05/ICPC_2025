#include <bits/stdc++.h>
using namespace std;

using int64 = long long;
using Edge = array<int, 3>; // {weight, u, v}

struct DSU {
    explicit DSU(int n) : parent_or_size(n, -1) {}

    int leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int merge(int a, int b) {
        a = leader(a);
        b = leader(b);
        if (a == b) return a;
        if (-parent_or_size[a] < -parent_or_size[b]) swap(a, b);
        parent_or_size[a] += parent_or_size[b];
        parent_or_size[b] = a;
        return a;
    }

private:
    vector<int> parent_or_size;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    int64 total = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {w, u, v};
        total += w;
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n + 1);

    for (auto [w, u, v] : edges) {
        int lu = dsu.leader(u);
        int lv = dsu.leader(v);

        if (lu == lv && w >= 0) continue;

        dsu.merge(lu, lv);
        total -= w;
    }

    cout << total << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
