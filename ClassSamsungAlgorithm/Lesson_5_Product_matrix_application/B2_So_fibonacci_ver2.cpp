#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define pf push_front
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
int n, base; 
struct matrix{
    int a[2][2];
    friend matrix operator* (matrix x, matrix y){
        matrix c;
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                __int128_t sum = 0;
                FOR(k, 0, 1){
                    sum += (__int128_t)x.a[i][k] * y.a[k][j];
                    sum %= base;
                }
                c.a[i][j] = 1ll * sum;
            }
        }
        return c;
    }
};

matrix binpow(matrix x, int n){
    if(n == 1) return x;
    matrix X = binpow(x, n / 2);
    if(n % 2 == 0) return X * X;
    else return X * X * x;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        cin >> n >> base;
        matrix x;
        x.a[0][0] = 1; x.a[0][1] = 1;
        x.a[1][0] = 1; x.a[1][1] = 0;
        matrix ans = binpow(x, n + 1);
        cout << ans.a[0][1] << endl;
    }

    return 0;
}