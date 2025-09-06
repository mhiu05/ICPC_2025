#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

struct SqrtBlocks {
    int n, B, numB;
    vector<long long> a;
    vector<vector<long long>> blk;
    
    void init(const vector<long long>& arr, int B_given = 700) {
        n = (int)arr.size() - 1;
        B = max(1, min(n, B_given));
        numB = (n + B - 1) / B;
        a = arr;
        blk.resize(numB);
        for (int i = 1; i <= n; i++) {
            int id = (i-1) / B;
            blk[id].push_back(a[i]);
        }
        for (int i = 0; i < numB; i++) {
            sort(blk[i].begin(), blk[i].end());
        }
    }
    
    void update(int pos, long long val) {
        int id = (pos-1) / B;
        auto &v = blk[id];
        // Tìm và xóa giá trị cũ
        auto it = lower_bound(v.begin(), v.end(), a[pos]);
        if (it != v.end() && *it == a[pos]) {
            v.erase(it);
        }
        // Chèn giá trị mới vào đúng vị trí đã sắp xếp
        it = upper_bound(v.begin(), v.end(), val);
        v.insert(it, val);
        a[pos] = val;
    }
    
    long long query(int l, int r, long long X) {
        long long ans = INF;
        int bl = (l-1) / B;
        int br = (r-1) / B;
        
        if (bl == br) {
            for (int i = l; i <= r; i++) {
                if (a[i] > X) {
                    ans = min(ans, a[i]);
                }
            }
        } else {
            // Khối bên trái
            for (int i = l; i <= (bl+1)*B; i++) {
                if (a[i] > X) {
                    ans = min(ans, a[i]);
                }
            }
            // Các khối giữa
            for (int id = bl+1; id < br; id++) {
                auto it = upper_bound(blk[id].begin(), blk[id].end(), X);
                if (it != blk[id].end()) {
                    ans = min(ans, *it);
                }
            }
            // Khối bên phải
            for (int i = br*B + 1; i <= r; i++) {
                if (a[i] > X) {
                    ans = min(ans, a[i]);
                }
            }
        }
        return (ans == INF) ? -1 : ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    vector<long long> a(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    
    SqrtBlocks ds;
    ds.init(a);
    
    while (M--) {
        int type;
        cin >> type;
        if (type == 1) {
            int u;
            long long val;
            cin >> u >> val;
            ds.update(u, val);
        } else {
            int u, v;
            long long X;
            cin >> u >> v >> X;
            cout << ds.query(u, v, X) << '\n';
        }
    }
    
    return 0;
}