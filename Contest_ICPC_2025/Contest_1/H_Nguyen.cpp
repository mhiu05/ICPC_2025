#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// Đề: Cho hai số nguyên A và B. Bạn có thể thực hiện một chuỗi các phép tính: trong phép tính đầu tiên, 
// chọn một số và tăng nó lên 1; trong phép tính thứ hai, chọn một số và tăng nó lên 2, v.v. Bạn được phép tự chọn số lượng các phép tính này.
// Ví dụ, nếu A = 1 và B = 3, bạn có thể thực hiện chuỗi ba phép tính sau:
// 1. Cộng 1 vào A, khi đó A = 2 và B = 3
// 2. Cộng 2 vào B, khi đó A = 2 và B = 5
// 3. Cộng 3 vào A, khi đó A = 5 và B = 5
// Hãy tính số phép tính tối thiểu cần thiết để làm cho A và B bằng nhau.


signed main(){
    faster;
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        ll d = abs(a - b);
        if(d == 0) {
            cout << 0 << '\n';
            continue;
        }
        ll k = (ll) ceil((sqrt(1 + 8(double)d) - 1) / 2);
        ll s = k (k + 1) / 2;

        while((s - d) & 1) {
            k++;
            s += k;
        }
        cout << k << '\n';
    }

    return 0;
}