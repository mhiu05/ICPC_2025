#include <bits/stdc++.h>
using namespace std;

// Cre: ChatGPT (Đã AC, chưa hiểu)

const int MAXN = 105;
int N; // Kích thước ma trận N x N x N
long long bit[MAXN][MAXN][MAXN]; // Fenwick Tree 3D
map<tuple<int, int, int>, int> current_val; // Lưu giá trị hiện tại tại (x, y, z)

void update(int x, int y, int z, int delta) {
    for (int i = x; i <= N; i += i & -i)
        for (int j = y; j <= N; j += j & -j)
            for (int k = z; k <= N; k += k & -k)
                bit[i][j][k] += delta;
}

long long query(int x, int y, int z) {
    long long res = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            for (int k = z; k > 0; k -= k & -k)
                res += bit[i][j][k];
    return res;
}

long long range_query(int x1, int y1, int z1, int x2, int y2, int z2) {
    auto get = [&](int x, int y, int z) {
        return query(x, y, z);
    };
    return get(x2, y2, z2)
         - get(x1 - 1, y2, z2)
         - get(x2, y1 - 1, z2)
         - get(x2, y2, z1 - 1)
         + get(x1 - 1, y1 - 1, z2)
         + get(x1 - 1, y2, z1 - 1)
         + get(x2, y1 - 1, z1 - 1)
         - get(x1 - 1, y1 - 1, z1 - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int M;
        cin >> N >> M;

        // Reset BIT and value map
        memset(bit, 0, sizeof(bit));
        current_val.clear();

        while (M--) {
            string cmd;
            cin >> cmd;

            if (cmd == "UPDATE") {
                int x, y, z, w;
                cin >> x >> y >> z >> w;
                auto key = make_tuple(x, y, z);
                int old_val = current_val[key];
                int delta = w - old_val;
                current_val[key] = w;
                update(x, y, z, delta);
            } else if (cmd == "QUERY") {
                int x1, y1, z1, x2, y2, z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout << range_query(x1, y1, z1, x2, y2, z2) << '\n';
            }
        }
    }

    return 0;
}
