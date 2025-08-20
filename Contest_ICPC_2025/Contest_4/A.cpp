#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 MOD = 1000000007LL;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    if (!(cin >> N >> M)) return 0;
    // hàm đếm số dãy có LIS <= k
    auto count_LIS_le_k = [&](int k)->int64{
        int INF = M + 1;
        vector<vector<int>> states;
        // sinh tất cả trạng thái: chọn p phần tử tăng (p = 0..k)
        // một trạng thái là vector length k, phần đầu là các giá trị tăng, phần sau là INF
        for (int p = 0; p <= k; ++p) {
            if (p == 0) {
                vector<int> v(k, INF);
                states.push_back(v);
            } else {
                // chọn p giá trị tăng từ 1..M -> kết hợp combinations
                vector<int> comb(p);
                // sinh combinations bằng đệ quy / iterative
                // iterative: sử dụng stack của indices
                // sử dụng recursive lambda:
                function<void(int,int,int)> gen = [&](int idx, int start, int remain){
                    if (remain == 0){
                        vector<int> v;
                        for (int t = 0; t < p; ++t) v.push_back(comb[t]);
                        for (int t = 0; t < k-p; ++t) v.push_back(INF);
                        states.push_back(v);
                        return;
                    }
                    for (int val = start; val <= M - remain + 1; ++val){
                        comb[idx] = val;
                        gen(idx+1, val+1, remain-1);
                    }
                };
                gen(0, 1, p);
            }
        }

        // map trạng thái -> index
        map<vector<int>, int> idx;
        for (int i = 0; i < (int)states.size(); ++i) idx[states[i]] = i;

        // tiền tính chuyển tiếp: từ mỗi trạng thái, cho mỗi x in [1..M] ta có trạng thái mới (nếu hợp lệ)
        int S = states.size();
        vector<vector<pair<int,int>>> trans(S); // (next_idx, count_of_x)
        for (int i = 0; i < S; ++i){
            // dùng map để cộng số x dẫn tới cùng trạng thái
            unordered_map<int,int> mp;
            for (int x = 1; x <= M; ++x){
                // tìm vị trí j: first index where states[i][j] >= x
                int j = -1;
                for (int t = 0; t < k; ++t){
                    if (states[i][t] >= x) { j = t; break; }
                }
                if (j == -1) {
                    // tất cả < x => sẽ cần mở pile mới, nhưng vì không có vị trí INF (tức đã có k pile),
                    // nên tạo pile thứ k+1 => LIS > k => không hợp lệ => bỏ
                    continue;
                }
                vector<int> nxt = states[i];
                nxt[j] = x; // replace top
                // đảm bảo nxt vẫn là trạng thái hợp lệ (prefix tăng) — do trước đó first >= x, prefix < x nên vẫn ok
                int nxt_id = idx[nxt];
                mp[nxt_id] += 1;
            }
            // chuyển vào trans
            for (auto &pr : mp) trans[i].push_back({pr.first, pr.second});
        }

        // DP: dp[cur_state] = ways
        vector<int64> dp(S, 0), ndp(S, 0);
        int start_state = idx[vector<int>(k, INF)];
        dp[start_state] = 1;
        for (int step = 0; step < N; ++step){
            fill(ndp.begin(), ndp.end(), 0);
            for (int s = 0; s < S; ++s){
                if (dp[s] == 0) continue;
                int64 ways = dp[s];
                for (auto &pr : trans[s]){
                    int ns = pr.first;
                    int cnt_x = pr.second;
                    ndp[ns] = (ndp[ns] + ways * cnt_x) % MOD;
                }
            }
            dp.swap(ndp);
        }
        int64 total = 0;
        for (int i = 0; i < S; ++i){
            total += dp[i];
            if (total >= MOD) total -= MOD;
        }
        return total % MOD;
    };

    int64 A = count_LIS_le_k(3); // LIS <= 3
    int64 B = count_LIS_le_k(2); // LIS <= 2
    int64 ans = (A - B) % MOD;
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
    return 0;
}
