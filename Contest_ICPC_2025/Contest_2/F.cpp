#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int S = accumulate(A.begin(), A.end(), 0);

    vector<int> sortedB = B;
    sort(sortedB.rbegin(), sortedB.rend());
    int total_cap = 0;
    int K_val = 0;
    for (int i = 0; i < n; i++) {
        total_cap += sortedB[i];
        if (total_cap >= S) {
            K_val = i + 1;
            break;
        }
    }

    vector<int> c_i(n);
    for (int i = 0; i < n; i++) {
        c_i[i] = min(A[i], B[i]);
    }

    vector<vector<int>> dp(K_val + 1, vector<int>(S + 1, -1));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int kk = K_val; kk >= 1; kk--) {
            for (int cap = S; cap >= 0; cap--) {
                if (dp[kk - 1][cap] != -1) {
                    int new_cap = cap + B[i];
                    if (new_cap > S) 
                        new_cap = S;
                    int new_val = dp[kk - 1][cap] + c_i[i];
                    if (dp[kk][new_cap] < new_val) {
                        dp[kk][new_cap] = new_val;
                    }
                }
            }
        }
    }

    int total_x_i = dp[K_val][S];
    total_x_i = min(S, total_x_i);
    int T_val = S - total_x_i;

    cout << K_val << " " << T_val << endl;

    return 0;
}