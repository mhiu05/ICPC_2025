#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; // N hàng rào, M bò
    if(!(cin >> N >> M)) return 0;

    struct Seg { int x1,y1,x2,y2; };
    vector<Seg> fences(N);
    vector<pair<int,int>> cows(M);

    vector<int> xs, ys;
    const int MIN_SENT = -1;
    const int MAX_SENT = 1000001; // vì coords in [0..1e6]

    for (int i = 0; i < N; ++i) {
        int Ax,Ay,Bx,By; cin >> Ax >> Ay >> Bx >> By;
        // normalize endpoints order (not strictly necessary)
        fences[i] = {Ax,Ay,Bx,By};
        xs.push_back(Ax); xs.push_back(Bx);
        ys.push_back(Ay); ys.push_back(By);
    }
    for (int i = 0; i < M; ++i) {
        int cx, cy; cin >> cx >> cy;
        cows[i] = {cx, cy};
        xs.push_back(cx);
        ys.push_back(cy);
    }

    // For robust cell creation we insert v and v+1 for every coordinate v,
    // and add sentinels so that outside areas are represented.
    vector<int> xs2, ys2;
    xs2.push_back(MIN_SENT); ys2.push_back(MIN_SENT);
    for (int v : xs) { xs2.push_back(v); xs2.push_back(v+1); }
    xs2.push_back(MAX_SENT);
    ys2.push_back(MIN_SENT);
    for (int v : ys) { ys2.push_back(v); ys2.push_back(v+1); }
    ys2.push_back(MAX_SENT);

    sort(xs2.begin(), xs2.end());
    xs2.erase(unique(xs2.begin(), xs2.end()), xs2.end());
    sort(ys2.begin(), ys2.end());
    ys2.erase(unique(ys2.begin(), ys2.end()), ys2.end());

    int W = (int)xs2.size() - 1; // number of cells in x direction
    int H = (int)ys2.size() - 1; // number of cells in y direction

    // linear index helper
    auto idx = [&](int i, int j){ return i * H + j; };

    // blocked_right[i][j] = edge from cell (i,j) -> (i+1,j) is blocked
    // blocked_up[i][j]    = edge from cell (i,j) -> (i,j+1) is blocked
    vector<unsigned char> blocked_right((size_t)W * H, 0);
    vector<unsigned char> blocked_up((size_t)W * H, 0);

    // helper to get position in compressed arrays
    auto posx = [&](int v){
        return int(lower_bound(xs2.begin(), xs2.end(), v) - xs2.begin());
    };
    auto posy = [&](int v){
        return int(lower_bound(ys2.begin(), ys2.end(), v) - ys2.begin());
    };

    // mark fences -> block corresponding edges
    for (auto &s : fences) {
        int x1 = s.x1, y1 = s.y1, x2 = s.x2, y2 = s.y2;
        if (x1 == x2) {
            // vertical fence at x = x1, spanning y in [minY, maxY]
            int X = posx(x1);
            int ymin = min(y1,y2), ymax = max(y1,y2);
            int j0 = posy(ymin);
            int j1 = posy(ymax); // we will iterate j in [j0 .. j1-1]
            for (int j = j0; j < j1; ++j) {
                int left = X - 1;
                if (left >= 0 && left < W && j >= 0 && j < H) {
                    blocked_right[idx(left, j)] = 1;
                }
                // right cell is left+1 = X, but blocking left->right is enough
            }
        } else {
            // horizontal fence at y = y1, spanning x in [minX, maxX]
            int Y = posy(y1);
            int xmin = min(x1,x2), xmax = max(x1,x2);
            int i0 = posx(xmin);
            int i1 = posx(xmax);
            for (int i = i0; i < i1; ++i) {
                int below = Y - 1;
                if (i >= 0 && i < W && below >= 0 && below < H) {
                    blocked_up[idx(i, below)] = 1;
                }
            }
        }
    }

    // BFS to label components (cells that are reachable without crossing fences)
    vector<int> comp((size_t)W * H, -1);
    int compCnt = 0;
    deque<pair<int,int>> dq;
    for (int i = 0; i < W; ++i) {
        for (int j = 0; j < H; ++j) {
            int id = idx(i,j);
            if (comp[id] != -1) continue;
            // BFS/DFS
            comp[id] = compCnt;
            dq.clear();
            dq.push_back({i,j});
            while(!dq.empty()){
                auto [cx, cy] = dq.front(); dq.pop_front();
                int cid = idx(cx, cy);
                // right
                if (cx + 1 < W) {
                    if (!blocked_right[cid]) {
                        int nid = idx(cx+1, cy);
                        if (comp[nid] == -1) {
                            comp[nid] = compCnt;
                            dq.push_back({cx+1, cy});
                        }
                    }
                }
                // left
                if (cx - 1 >= 0) {
                    int leftId = idx(cx-1, cy);
                    if (!blocked_right[leftId]) {
                        int nid = leftId;
                        if (comp[nid] == -1) {
                            comp[nid] = compCnt;
                            dq.push_back({cx-1, cy});
                        }
                    }
                }
                // up (y+1)
                if (cy + 1 < H) {
                    if (!blocked_up[cid]) {
                        int nid = idx(cx, cy+1);
                        if (comp[nid] == -1) {
                            comp[nid] = compCnt;
                            dq.push_back({cx, cy+1});
                        }
                    }
                }
                // down (y-1)
                if (cy - 1 >= 0) {
                    int downId = idx(cx, cy-1);
                    if (!blocked_up[downId]) {
                        int nid = downId;
                        if (comp[nid] == -1) {
                            comp[nid] = compCnt;
                            dq.push_back({cx, cy-1});
                        }
                    }
                }
            }
            ++compCnt;
        }
    }

    // Count cows per component
    vector<int> cnt(compCnt, 0);
    for (auto &p : cows) {
        int cx = p.first, cy = p.second;
        int ix = posx(cx);
        int iy = posy(cy);
        // map to cell index: cell i is [xs2[i], xs2[i+1]) so cx belongs to i = lower_bound(xs2, cx)
        if (ix == (int)xs2.size()-1) ix = (int)xs2.size()-2;
        if (iy == (int)ys2.size()-1) iy = (int)ys2.size()-2;
        // ensure inside
        if (ix < 0 || ix >= W || iy < 0 || iy >= H) continue;
        int id = idx(ix, iy);
        if (comp[id] >= 0) cnt[comp[id]]++;
    }

    int ans = 0;
    for (int v : cnt) ans = max(ans, v);
    cout << ans << "\n";
    return 0;
}
