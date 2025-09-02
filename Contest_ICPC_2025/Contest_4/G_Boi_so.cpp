#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

static inline int64 floordiv(int64 a, int64 b) { // b>0
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}
static inline int64 ceildiv(int64 a, int64 b) { // b>0
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        long long A,B,C,D;
        cin >> A >> B >> C >> D;

        const long long diff = C - B;
        if (diff <= 0) { cout << 0 << '\n'; continue; }

        long long Kmax = (D - 1) / diff;
        if (Kmax <= 0) { cout << 0 << '\n'; continue; }

        // m range that can produce intervals intersecting [1..Kmax]
        long long mL = ceildiv(A + B, D);
        long long mR = floordiv(A + C * Kmax, D);
        if (mL > mR) {                      // không có bội nào “đi vào” dải K cần xét
            cout << Kmax << '\n';
            continue;
        }

        long long banned = 0;
        long long curL = (long long)4e18, curR = -(long long)4e18; // interval đang merge

        for (long long m = mL; m <= mR; ) {
            // L = ceil((mD - A)/C) = floor((mD - A + C - 1)/C)
            long long L = ( (m*D - A + C - 1) ) / C;
            // R = floor((mD - A)/B)
            long long R = ( (m*D - A) ) / B;

            // cắt với [1..Kmax]
            long long l = max(1LL, L);
            long long r = min(Kmax, R);

            // tính m lớn nhất còn giữ nguyên L và R tại m hiện tại
            // Với F(m)=floor((D*m + q)/r) không đổi khi m <= ( r*(F+1) - q - 1 )/D
            // cho L: qL = -A + (C-1), rL = C
            long long qL = -A + (C - 1);
            long long Llast = ( C * (L + 1) - qL - 1 ) / D;

            // cho R: qR = -A, rR = B
            long long qR = -A;
            long long Rlast = ( B * (R + 1) - qR - 1 ) / D;

            long long upto = min({Llast, Rlast, mR});

            if (l <= r) {
                // vì trong đoạn [m..upto], [L,R] cố định → chỉ cần merge 1 lần
                if (curL > curR) {      // rỗng
                    curL = l; curR = r;
                } else if (l > curR + 1) {
                    banned += (curR - curL + 1);
                    curL = l; curR = r;
                } else {
                    curR = max(curR, r);
                }
            }
            m = upto + 1;
        }
        if (curL <= curR) banned += (curR - curL + 1);

        long long ans = Kmax - banned;
        if (ans < 0) ans = 0;
        cout << ans << '\n';
    }
    return 0;
}
