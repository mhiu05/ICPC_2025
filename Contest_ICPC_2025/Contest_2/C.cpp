#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point {
    double x, y;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<array<int,4>> seg(N);
    map<pair<int,int>, int> mp;
    vector<Point> pts;
    pts.reserve(2*N);

    // Gán ID cho mỗi toạ độ
    auto getId = [&](int x, int y)->int {
        auto p = make_pair(x,y);
        auto it = mp.find(p);
        if(it != mp.end()) return it->second;
        int id = pts.size();
        mp[p] = id;
        pts.push_back({(double)x, (double)y});
        return id;
    };

    vector<pair<int,int>> edges;
    edges.reserve(2*N);
    for(int i = 0; i < N; i++){
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int u = getId(x1,y1);
        int v = getId(x2,y2);
        edges.emplace_back(u,v);
    }
    int V = pts.size();

    // Tạo danh sách kề (half-edge list)
    vector<vector<int>> adj(V);
    vector<pair<int,int>> half; half.reserve(2*N);
    for(auto &e : edges){
        int u = e.first, v = e.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
        half.emplace_back(u,v);
        half.emplace_back(v,u);
    }

    // Sắp xếp quanh mỗi đỉnh theo góc atan2
    vector<vector<int>> nbr(V);
    for(int u = 0; u < V; u++){
        auto &A = adj[u];
        sort(A.begin(), A.end(), [&](int v1, int v2){
            double a1 = atan2(pts[v1].y - pts[u].y, pts[v1].x - pts[u].x);
            double a2 = atan2(pts[v2].y - pts[u].y, pts[v2].x - pts[u].x);
            return a1 < a2;
        });
        nbr[u] = A;
    }

    // Đánh dấu đã duyệt half-edge
    map<pair<int,int>, bool> used;
    vector<double> areas;

    // Tính diện tích đa giác (shoelace)
    auto polygonArea = [&](const vector<int>& path){
        double A = 0;
        int m = path.size();
        for(int i = 0; i < m; i++){
            auto &P = pts[path[i]];
            auto &Q = pts[path[(i+1)%m]];
            A += P.x*Q.y - P.y*Q.x;
        }
        return fabs(A)*0.5;
    };

    // Duyệt từng half-edge chưa thăm
    for(auto &e : half){
        int u = e.first, v = e.second;
        if(used[{u,v}]) continue;

        vector<int> face;
        int cu = u, cv = v;
        // Lặp đến khi quay lại half-edge gốc
        while(true){
            used[{cu,cv}] = true;
            face.push_back(cu);

            // Tìm vị trí cu trong nbr[cv]
            auto &A = nbr[cv];
            int pos = find(A.begin(), A.end(), cu) - A.begin();
            // Chọn neighbor trước pos (đi vòng phải quanh face)
            int nextPos = (pos - 1 + A.size()) % A.size();
            int w = A[nextPos];

            cu = cv;
            cv = w;
            if(cu == u && cv == v) break;
        }

        double a = polygonArea(face);
        if(a > 1e-9) areas.push_back(a);
    }

    // Loại bỏ face vô cực (largest area)
    if(!areas.empty()){
        sort(areas.begin(), areas.end());
        areas.pop_back();
    }

    // Tính tổng bình phương diện tích
    double total = 0;
    for(double a : areas){
        total += a*a;
    }

    cout << fixed << setprecision(6) << total << "\n";
    return 0;
}
