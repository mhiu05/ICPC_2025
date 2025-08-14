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

struct matrix{
    int a[2][2];
    friend matrix operator* (matrix x, matrix y){
        matrix c;
        FOR(i, 0, 1){
            FOR(j, 0, 1){
                c.a[i][j] = 0;
                FOR(k, 0, 1){
                    c.a[i][j] += x.a[i][k] * y.a[k][j];
                    c.a[i][j] %= MOD;
                }
            }
        }
        return c;
    }
};

matrix binpow(matrix a, int n){
    if(n == 1) return a;
    matrix X = binpow(a, n / 2);
    if(n % 2 == 0) return X * X;
    else return X * X * a;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        matrix X;
        X.a[0][0] = 1; X.a[0][1] = 1;
        X.a[1][0] = 1; X.a[1][1] = 0;

        matrix ans = binpow(X, n);
        cout << ans.a[1][0] << endl;
    }

    return 0;
}