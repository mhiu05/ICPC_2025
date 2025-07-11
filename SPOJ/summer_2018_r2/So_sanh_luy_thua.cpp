#include <bits/stdc++.h>
#define ll long long
// #define int long long
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
const double EPS = 1e-15;
const int INF = 1e9;

using namespace std;

int kind(int a, int b){
    if(a == 0) return 0;
    if(b == 0) return 1;
    if(a == 1) return 1;
    return 2;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        
        // TH đặc biệt: 0^x, 1^x, x^0
        int k1 = kind(a, b), k2 = kind(c, d);
        if(k1 != k2){
            if(k1 < k2) cout << "<\n";
            else cout << ">\n";
            continue;
        }
        if(k1 == 0 || k1 == 1){
            cout << "=\n";
            continue;
        }

        // cùng cơ số
        if(a == c){
            if(b == d) cout << "=\n";
            else if(b < d) cout << "<\n";
            else cout << ">\n";
            continue;
        }

        // cùng số mũ
        if(b == d){
            if(a < c) cout << "<\n";
            else if(a > c) cout << ">\n";
            else cout << "=\n";
            continue;
        }

        // TH bình thường
        long double d1 = (long double)b * logl((long double)a);
        long double d2 = (long double)d * logl((long double)c);
        if(fabsl(d1 - d2) <= EPS * max(fabsl(d1), fabsl(d2))) cout << "=\n";
        else{
            if(d1 < d2) cout << "<\n";
            else cout << ">\n";
        }
    }

    return 0;
}