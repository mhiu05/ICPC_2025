#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<ll> prefix(n + 1, 0);
    
    // Tính prefix sum
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        prefix[i] = (prefix[i - 1] + a) % k;
    }

    map<ll, vector<int>> groups; // Lưu các chỉ số i theo giá trị value[i]

    ll result = 0;
    for (int j = 0; j <= n; j++) { // j là chỉ số hiện tại
        ll value_j = prefix[j] - j; // Tính value[j]

        // Hàm đếm số phần tử trong vector > threshold
        auto count_greater = [](const vector<int>& vec, int threshold) {
            auto it = upper_bound(vec.begin(), vec.end(), threshold);
            return distance(it, vec.end());
        };

        // Đếm số i đã xuất hiện (i < j) thỏa value[i] == value_j
        result += count_greater(groups[value_j], j - k);

        // Đếm số i đã xuất hiện (i < j) thỏa value[i] == value_j + k
        result += count_greater(groups[value_j + k], j - k);

        // Thêm chỉ số j vào nhóm tương ứng
        groups[value_j].push_back(j);
    }
    
    cout << result;
    
    return 0;
}