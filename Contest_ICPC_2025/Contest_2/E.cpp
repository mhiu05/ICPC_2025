#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int mod = 998244353;
const int MAXN = 200000;

vector<long long> pow2(MAXN + 1);

void precompute() {
    pow2[0] = 1;
    for (int i = 1; i <= MAXN; i++) {
        pow2[i] = (pow2[i - 1] * 2) % mod;
    }
}

int main() {
    precompute();
    int T;
    cin >> T;
    while (T--) {
        int N;
        long long K;
        cin >> N >> K;
        vector<long long> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        map<long long, vector<long long>> groups;
        for (long long x : A) {
            long long r = x % K;
            groups[r].push_back(x);
        }

        long long total = 1;

        for (auto &p : groups) {
            long long r = p.first;
            vector<long long> &arr = p.second;
            sort(arr.begin(), arr.end());

            vector<pair<long long, int>> classes;
            for (int i = 0; i < arr.size(); i++) {
                long long t = (arr[i] - r) / K;
                if (classes.empty() || classes.back().first != t) {
                    classes.push_back({t, 1});
                } else {
                    classes.back().second++;
                }
            }

            if (classes.empty()) {
                continue;
            }

            long long dp0 = 1;
            long long dp1 = pow2[classes[0].second];
            for (int i = 1; i < classes.size(); i++) {
                long long c = classes[i].second;
                long long ways = (pow2[c] - 1 + mod) % mod;
                long long new_dp = (dp1 + ways * dp0) % mod;
                dp0 = dp1;
                dp1 = new_dp;
            }

            total = (total * dp1) % mod;
        }

        long long ans = (total - 1 + mod) % mod;
        cout << ans << '\n';
    }
    return 0;
}