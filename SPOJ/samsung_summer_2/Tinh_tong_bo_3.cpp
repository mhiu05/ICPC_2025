#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

// Đặt p = a + b + c, q = ab + bc + ca, r = abc với 0 < a < b < c; a, b ,c nguyên dương 
// Biểu diễn f2, f3, f4 theo p, q, r. Thay q, r theo p, f2, f3, f4 và rút gọn ta có:
// p^4 - 6.f2.p^2 + 8.f3.p + 3.(f2)^2 - 6.f4 = 0 với q = (p^2 - f2)/2 , r = (p^3 - 3*p*f2 + 2*f3)/6 
// Gs P(x) có nghiệm a, b, c: P(x) = (x - a)(x - b)(x - c) = x^3 - (a + b + c)x^2 + (ab + bc + ca)x - abc = 0
// => f(n) = p.f(n-1) - q.f(n - 2) + r.f(n - 3)
// [f(n) f(n - 1) f(n - 2) T(n)]^T = Matrix(4x4) x [f(n - 1) f(n - 2) f(n - 3) T(n - 1)]^T với T(n) = F(1) + ... + f(n)

struct matrix{
    ll a[4][4];
    friend matrix operator*(matrix x, matrix y){
        matrix c;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                __int128 sum = 0;
                for(int k = 0; k < 4; ++k){
                    sum += (__int128)x.a[i][k] * y.a[k][j];
                }
                c.a[i][j] = (ll)(sum % mod);
            }
        }
        return c;
    }
};

matrix binpow(matrix x, ll k){
    if(k == 1) return x;
    matrix X = binpow(x, k / 2);
    if(k % 2 == 0) return X * X;
    return X * X * x;
}

// tính f(1) + f(2) + ... + f(k)
ll getT(ll k, ll f1, ll f2, ll f3, matrix M){
    if(k==0) return 0;
    if(k==1) return f1 % mod;
    if(k==2) return (f1 + f2) % mod;
    if(k==3) return (f1 + f2 + f3) % mod;

    ll T3 = ( (f1 + f2) % mod + f3 ) % mod;
    vector<ll> v = {f3, f2, f1, T3};
    matrix P = binpow(M, k-3);
    ll T_k = 0;
    for(int i=0;i<4;i++){
        T_k = (T_k + P.a[3][i]*v[i]) % mod;
    }
    return T_k;
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        ll f2, f3, f4, L, R; cin >> f2 >> f3 >> f4 >> L >> R;
        // tìm p
        ll p = 0;
        for(ll i = 6; i <= 15000; ++i){
            __int128 t = (__int128)i*i*i*i - (__int128)6*f2*i*i + (__int128)8*f3*i + (__int128)3*(__int128)f2*f2 - (__int128)6*f4;
            if(t == 0){
                p = i;
                break;
            }
        }
        
        // tìm q, r
        __int128 q0 = ((__int128)p*p - f2) / 2;
        __int128 r0 = ((__int128)p*p*p - (__int128)3*p*f2 + (__int128)2*f3) / 6;
        ll f1 = p;
        ll q  = (ll)((q0 % mod + mod) % mod);
        ll r  = (ll)((r0 % mod + mod) % mod);

        // set matrix chuyển trạng thái
        matrix x;
        x.a[0][0] = p; x.a[0][1] = (-q + mod) % mod; x.a[0][2] = r; x.a[0][3] = 0;
        x.a[1][0] = 1; x.a[1][1] = 0;                 x.a[1][2] = 0; x.a[1][3] = 0;
        x.a[2][0] = 0; x.a[2][1] = 1;                 x.a[2][2] = 0; x.a[2][3] = 0;
        x.a[3][0] = p; x.a[3][1] = (-q + mod) % mod; x.a[3][2] = r; x.a[3][3] = 1;

        // tính S(n) = T(r) - T(l - 1)
        ll T_R   = getT(R, f1, f2 % mod, f3 % mod, x);
        ll T_L_sub_1 = getT(L-1, f1, f2 % mod, f3 % mod, x);
        ll ans  = (T_R - T_L_sub_1 + mod) % mod;
        cout << ans << "\n";
    }

    return 0;
}