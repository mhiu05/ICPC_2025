#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Đề:
// cho a[], n phần tử, 0 <= a[i] <= M, M là 1 số cho trước
// Trong 1 thao tác, có thể chọn k phần tử bất kì thuộc a[] rồi thay a[i] -> (a[i] + 1) mod M
// Tìm số thao tác tối thiểu để biến a[] thành dãy không giảm
// input:                        output:
// 5 3                           0
// 0 0 1 3 4                     

// 5 7                           1
// 0 6 1 3 2

// 10 10                         6
// 5 0 5 9 4 6 4 5 0 0

// chatGPT (Code đã submit AC nhưng chưa xem lại) 

bool isNonDecreasing(const vector<int>& a) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

bool check(int T, int M, const vector<int>& a) {
    if (T == 0) {
        return isNonDecreasing(a);
    }

    long long b = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int ai = a[i];
        bool in_if = false;
        if (T >= M - ai) {
            in_if = true;
        }
        long long next_b = LLONG_MAX;

        if (in_if) {
            int R1 = ai + T - M;
            if (R1 >= 0) {
                int r1 = min(M - 1, R1);
                if (b <= r1) {
                    next_b = min(next_b, (long long)max(b, 0LL));
                }
            }
            if (b <= M - 1) {
                next_b = min(next_b, (long long)max(b, (long long)ai));
            }
        } else {
            int R = ai + T;
            int r = min(M - 1, R);
            if (b <= r) {
                next_b = min(next_b, (long long)max(b, (long long)ai));
            }
        }

        if (next_b == LLONG_MAX) {
            return false;
        }
        b = next_b;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    if (isNonDecreasing(A)) {
        cout << 0 << endl;
        return 0;
    }

    int low = 0, high = M;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(mid, M, A)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
}