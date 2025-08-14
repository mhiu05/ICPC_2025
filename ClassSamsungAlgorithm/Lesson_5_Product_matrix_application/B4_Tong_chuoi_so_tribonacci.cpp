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

const ll MOD = 1e15 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

//[[Fn + 1] T[n + 1] T[n] T[n - 1]]^T = [[1 1 1 1], [0 1 1 1], [0 1 0 0], [0 0 1 0]] x [F[n] T[n] T[n - 1] T[n - 2]]^T       

struct matrix{
    ll a[4][4] = {
        {1, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };
    
    friend matrix operator *(matrix x, matrix y){
        matrix c;
        memset(c.a, 0, sizeof(c.a));
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                __int128 sum = 0;
                for(int k = 0; k < 4; ++k) {
                    sum += (__int128)x.a[i][k] * y.a[k][j];
                }
                c.a[i][j] = 1ll * (sum % MOD);
            }
        }
        return c;
    }
};

matrix binpow(matrix a, ll n){
    if(n == 1) return a;
    matrix X = binpow(a, n / 2);
    if(n % 2 == 0) return X * X;
    return X * X * a;
}

int main(){
    faster;
    
    int t; cin >> t;
    while(t--){
        matrix x;
        ll n; cin >> n;
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        if(n == 2){
            cout << 3 << endl;
            continue;
        }
        if(n == 3){
            cout << 6 << endl;
            continue;
        }
        matrix ans = binpow(x, n - 3);
        ll kq = (
            (__int128)6 * ans.a[0][0] +
            (__int128)3 * ans.a[0][1] +
            (__int128)2 * ans.a[0][2] +
            (__int128)1 * ans.a[0][3]
        ) % mod;
        cout << kq << endl;
    }


    return 0;
}