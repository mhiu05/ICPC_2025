#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

// Đếm số dãy độ dài N, giá trị từ 1..M, có LIS <= k
int64 count_LIS_le_k(int N, int M, int k) {
    int INF = M + 1;

    // 1. Sinh tất cả trạng thái hợp lệ
    // Mỗi trạng thái là vector độ dài k:
    // - phần đầu: dãy tăng (các giá trị "top" của pile)
    // - phần còn lại: INF
    vector<vector<int>> states;
    function<void(int,int,vector<int>&)> gen = [&](int pos, int start, vector<int>& cur) {
        if (pos == k) {
            states.push_back(cur);
            return;
        }
        if ((int)cur.size() < k) {
            // Thêm INF (để độ dài < k)
            vector<int> tmp = cur;
            while ((int)tmp.size() < k) tmp.push_back(INF);
            states.push_back(tmp);
        }
        for (int val = start; val <= M; ++val) {
            cur.push_back(val);
            gen(pos+1, val+1, cur);
            cur.pop_back();
        }
    };
    vector<int> init;
    gen(0, 1, init);

    // Map trạng thái -> id
    map<vector<int>, int> state_id;
    for (int i = 0; i < (int)states.size(); i++) {
        state_id[states[i]] = i;
    }

    int S = states.size();
    // 2. Tiền tính chuyển tiếp: state + thêm 1 số x -> state mới
    vector<vector<pair<int,int>>> trans(S);
    for (int i = 0; i < S; i++) {
        unordered_map<int,int> count_next;
        for (int x = 1; x <= M; x++) {
            // tìm vị trí đầu tiên >= x
            int pos = -1;
            for (int t = 0; t < k; t++) {
                if (states[i][t] >= x) { pos = t; break; }
            }
            if (pos == -1) continue; // không còn slot -> LIS vượt k
            vector<int> nxt = states[i];
            nxt[pos] = x;
            int id = state_id[nxt];
            count_next[id]++;
        }
        for (auto &pr : count_next) {
            trans[i].push_back(pr);
        }
    }

    // 3. DP theo số bước
    vector<int64> dp(S, 0), ndp(S, 0);
    int start_state = state_id[vector<int>(k, INF)];
    dp[start_state] = 1;

    for (int step = 0; step < N; step++) {
        fill(ndp.begin(), ndp.end(), 0);
        for (int s = 0; s < S; s++) if (dp[s]) {
            for (auto &pr : trans[s]) {
                int nxt = pr.first;
                int cnt = pr.second;
                ndp[nxt] = (ndp[nxt] + dp[s] * cnt) % MOD;
            }
        }
        dp.swap(ndp);
    }

    // 4. Tổng số dãy hợp lệ
    int64 total = 0;
    for (int64 v : dp) total = (total + v) % MOD;
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int64 total_LIS_le_3 = count_LIS_le_k(N, M, 3);
    int64 total_LIS_le_2 = count_LIS_le_k(N, M, 2);

    int64 ans = (total_LIS_le_3 - total_LIS_le_2 + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}
