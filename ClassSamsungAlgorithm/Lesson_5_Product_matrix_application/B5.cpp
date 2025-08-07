#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
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

// dp[i][r] =  c_d * dp[i - 1][(r - d) mod k], 0 <= d <= 2 với d: số phần tử được chọn từ (i - 1) -> i
// dp[i][j]: matrix k x k
// [dp[i][0],....,dp[i][k - 1]]^t = T = T * [dp[i - 1][0],....,dp[i - 1][k - 1]]^t
// với matrix T: T[r][(r + 0) mod k] =  1
//               T[r][(r + 1) mod k] =  3
//               T[r][(r + 2) mod k] =  3
// T^m[i][j]: Số cách chuyển từ trạng thái i (tổng ban đầu đồng dư i (mod k)) sang trạng thái j (tổng sau m bước đồng dư j (mod k))

int m, k;
struct matrix{
    vvi a;
    int size;

    matrix() {}
    matrix(int n){
        size = n;
        a.resize(n);
        for (int i = 0; i < n; i++) {
            a[i] = vector<int>(n, 0);
        }
    }

    friend matrix operator *(matrix x, matrix y){
        matrix c(x.size);
        FOR(i, 0, x.size - 1){
            FOR(j, 0, x.size - 1){
                FOR(h, 0, x.size - 1){
                    c.a[i][j] = (c.a[i][j] + x.a[i][h] * y.a[h][j]) % MOD;
                }
            }
        }
        return c;
    }
};

matrix binpow(matrix x, ll n){
    if(n == 1) return x;
    matrix X = binpow(x, n / 2);
    if(n % 2 == 0) return X * X;
    return X * X * x;
}

signed main(){
    faster;

    cin >> m >> k;

    if (m == 0) {
        cout << 0;
        return 0;
    }

    matrix T(k);
    FOR(i, 0, k - 1){
        T.a[i][(i + 0) % k] = (T.a[i][(i + 0) % k] + 1) % MOD;
        T.a[i][(i + 1) % k] = (T.a[i][(i + 1) % k] + 3) % MOD;
        T.a[i][(i + 2) % k] = (T.a[i][(i + 2) % k] + 3) % MOD;
    }

    matrix ans = binpow(T, m);
    cout << (ans.a[0][0] - 1 + MOD) % MOD;
    return 0;
}