#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

// Cre: ChatGPT (Đã AC, chưa hiểu)

// bao hàm loại trừ: Đếm số lượng số <= x bị xóa (chia hết cho ít nhất 1 số trong a[])
// count = Tổng các số chia hết cho all số trong a[] - các số chia hết cho cả 2 số + các số chia hết cho cả 3 số .......
// count = (-1)^(|S| + 1) * [x / lcm(S)] vứi mọi S tập con a[], S khác rỗng


// Hàm tính số lượng số <= X mà chia hết cho ít nhất một số trong a[]
ll countRemoved(ll X, const vector<ll>& a) {
    ll total = 0;
    int n = a.size();
    for (int mask = 1; mask < (1 << n); ++mask) {
        ll lcm = 1;
        int bits = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                bits++;
                ll g = __gcd(lcm, a[i]);
                if (lcm / g > X / a[i]) { // Tránh tràn số
                    lcm = X + 1;
                    break;
                }
                lcm = (lcm / g) * a[i];
            }
        }
        if (lcm > X) continue;
        if (bits % 2 == 1) {
            total += X / lcm;
        } else {
            total -= X / lcm;
        }
    }
    return total;
}

// Hàm tìm số thứ K còn lại sau khi xóa
ll findKthNumber(ll K, const vector<ll>& a) {
    ll low = 1, high = K * (*max_element(a.begin(), a.end()));
    ll ans = high;
    while (low <= high) {
        ll mid = (low + high) / 2;
        ll removed = countRemoved(mid, a);
        ll remaining = mid - removed;
        if (remaining < K) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll N, K;
        cin >> N >> K;
        vector<ll> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        cout << findKthNumber(K, a) << '\n';
    }

    return 0;
}