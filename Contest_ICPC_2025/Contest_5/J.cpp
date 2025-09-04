#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 100005;

vector<array<ll, 3>> graph[MAXN]; // Mỗi phần tử là {nút kề, thời gian T, chu kỳ K}
ll dist[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        ll t, k;
        cin >> u >> v >> t >> k;
        graph[u].push_back({v, t, k});
        graph[v].push_back({u, t, k});
    }
    
    fill(dist, dist + n + 1, INF);
    dist[X] = 0;
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, X});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d != dist[u]) continue;
        if (u == Y) break;
        
        for (auto &edge : graph[u]) {
            int v = edge[0];
            ll t = edge[1];
            ll k = edge[2];
            
            ll wait = 0;
            if (d % k != 0) {
                wait = k - (d % k);
            }
            ll new_time = d + wait + t;
            
            if (new_time < dist[v]) {
                dist[v] = new_time;
                pq.push({new_time, v});
            }
        }
    }
    
    if (dist[Y] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[Y] << endl;
    }
    
    return 0;
}