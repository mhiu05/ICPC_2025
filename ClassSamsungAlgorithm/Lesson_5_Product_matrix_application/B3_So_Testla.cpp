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
    int a[3][3] = {{1, 2, 3}, {1, 0, 0}, {0, 1, 0}};
    friend matrix operator* (matrix x, matrix y){
        matrix c;
        FOR(i, 0, 2){
            FOR(j, 0, 2){
                __int128_t sum = 0;
                FOR(k, 0, 2){
                    sum += ((__int128_t)x.a[i][k] * y.a[k][j]);
                    sum %= base;
                }
                c.a[i][j] = 1ll * sum;
            }
        }
        return c;
    }
};

matrix binpow(matrix a, int n){
    if(n == 1) return a;
    matrix X = binpow(a, n / 2);
    if(n % 2 == 0) return X * X;
    return X * X * a;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        cin >> n >> base;
        if(n == 0){
            cout << 0 << endl;
            continue;
        }
        else if(n == 1){
            cout << 1 % base << endl;
            continue;
        }
        else if(n == 2){
            cout << 2 % base << endl;
            continue;
        }
        else if(n == 3){
            cout << 3 % base << endl;
            continue;
        }
        else{
            matrix x;
            matrix ans = binpow(x, n - 3);
            cout << (3*ans.a[0][0] + 2*ans.a[0][1] + ans.a[0][2]) % base << endl;
        }
    }

    return 0;
}