#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    vector<pair<int,int>> edges(M+1);
    for (int i = 1; i <= M; ++i) {
        int u,v; cin >> u >> v;
        edges[i] = {u,v};
    }
    int K; cin >> K;
    vector<int> Sidx(K);
    vector<char> isS(M+1, 0);
    for (int i = 0; i < K; ++i) {
        cin >> Sidx[i];
        if (1 <= Sidx[i] && Sidx[i] <= M) isS[Sidx[i]] = 1;
    }

    // deg trong H (chỉ đếm các cạnh thuộc S)
    vector<int> degH(N+1, 0);
    for (int idx : Sidx) {
        int u = edges[idx].first;
        int v = edges[idx].second;
        degH[u]++; degH[v]++;
    }

    // xây đồ thị chỉ gồm các cạnh không thuộc S
    vector<vector<int>> adjNonS(N+1);
    for (int i = 1; i <= M; ++i) if (!isS[i]) {
        int u = edges[i].first, v = edges[i].second;
        adjNonS[u].push_back(v);
        adjNonS[v].push_back(u);
    }

    // tìm thành phần của G \ S
    vector<int> comp(N+1, 0);
    int compId = 0;
    vector<char> vis(N+1, 0);
    for (int i = 1; i <= N; ++i) {
        if (vis[i]) continue;
        ++compId;
        // BFS/DFS
        stack<int> st; st.push(i);
        vis[i] = 1;
        comp[i] = compId;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : adjNonS[u]) if (!vis[v]) {
                vis[v] = 1;
                comp[v] = compId;
                st.push(v);
            }
        }
    }

    // với những đỉnh cô lập trong G\S (không có cạnh non-S), chúng vẫn đã được gán compId
    // Đếm số đỉnh có degH lẻ theo từng thành phần
    vector<int> oddCount(compId+1, 0);
    for (int v = 1; v <= N; ++v) {
        if (degH[v] % 2 != 0) oddCount[ comp[v] ]++;
    }

    // Số thành phần có oddCount % 2 == 1
    int oddComp = 0;
    for (int c = 1; c <= compId; ++c) if (oddCount[c] % 2 == 1) ++oddComp;

    if (oddComp == 0 || oddComp == 2) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
