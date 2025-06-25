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

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

// Code vẫn WA

ll n, base; 

struct matrix{
    ll a[2][2];
    
    friend matrix operator *(matrix x, matrix y){
        matrix c;
        for(int i = 0; i < 2; ++i){
            for(int j = 0; j < 2; ++j){
                c.a[i][j] = 0;
                for(int k = 0; k < 2; ++k){
                    c.a[i][j] += x.a[i][k] * y.a[k][j];
                    c.a[i][j] %= base;
                }
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
        cin >> n >> base;
        if(n == 0){
            cout << 1 << endl;
            continue;
        }
        matrix x;
        x.a[0][0] = 1; x.a[0][1] = 1;
        x.a[1][0] = 1; x.a[1][1] = 0;
        matrix ans =  binpow(x, n);
        
        cout << (ans.a[1][0] + ans.a[1][1]) % base << endl;
    }
    return 0;
}