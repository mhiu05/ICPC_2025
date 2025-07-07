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

ll C[61][61];
void combination(){
    FOR(i, 0, 60){
        FOR(j, 0, i){
            if(i == j || j == 0) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

signed main(){
    faster;

    combination();
    int n, m, t;
    cin >> n >> m >> t;
    ll x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
    if(t <= n) x1 = C[n][t]; // 0 nữ, t nam
    if(t - 3 <= m) x2 = C[n][3] * C[m][t - 3]; // 3 nam, t - 3 nữ
    if(t - 2 <= m) x3 = C[n][2] * C[m][t - 2]; // 2 nam, t - 2 nữ
    if(t - 1 <= m) x4 = C[n][1] * C[m][t - 1];  // 1 nam, t - 1 nữ
    if(t <= m) x5 = C[m][t];  // 0 nam, t nữ
    cout << C[n + m][t] - x1 - x2 - x3 - x4 - x5 << endl;
    return 0;
}
