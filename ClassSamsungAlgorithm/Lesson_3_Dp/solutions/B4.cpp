#include <bits/stdc++.h>
using namespace std;

// Cre: Chat GPT (Đã AC, chưa hiểu)

struct Big {
    static const uint32_t BASE = 1000000000;
    vector<uint32_t> d;

    Big(uint64_t x = 0) { 
        if (x == 0) return;
        while (x) {
            d.push_back(x % BASE);
            x /= BASE;
        }
    }
    void add(const Big &y) {
        uint32_t carry = 0;
        size_t n = max(d.size(), y.d.size());
        if (d.size() < n) d.resize(n, 0);
        for (size_t i = 0; i < n; i++) {
            uint64_t sum = uint64_t(d[i]) + (i < y.d.size() ? y.d[i] : 0) + carry;
            d[i] = sum % BASE;
            carry = sum / BASE;
        }
        if (carry) d.push_back(carry);
    }
    string toString() const {
        if (d.empty()) return "0";
        string s = to_string(d.back());
        char buf[10];
        for (int i = (int)d.size() - 2; i >= 0; i--) {
            snprintf(buf, sizeof(buf), "%09u", d[i]);
            s += buf;
        }
        return s;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    string S;
    cin >> K >> S;
    int n = S.size();

    // dp[i][b][m] = số cách đạt được vị trí i, với b dấu mở ngoặc và m độ sâu max
    vector<vector<vector<Big>>> dp(n + 1,
        vector<vector<Big>>(n + 1, vector<Big>(K + 1, Big(0)))
    );

    dp[0][0][0] = Big(1); // base case

    for (int i = 0; i < n; i++) {
        for (int b = 0; b <= i; b++) {
            for (int m = 0; m <= K; m++) {
                if (dp[i][b][m].d.empty()) continue;

                if (S[i] == '(' || S[i] == '?') {
                    int b2 = b + 1;
                    int m2 = max(m, b2);
                    if (m2 <= K)
                        dp[i + 1][b2][m2].add(dp[i][b][m]);
                }

                if ((S[i] == ')' || S[i] == '?') && b > 0) {
                    int b2 = b - 1;
                    dp[i + 1][b2][m].add(dp[i][b][m]);
                }
            }
        }
    }

    cout << dp[n][0][K].toString() << '\n';
    return 0;
}
