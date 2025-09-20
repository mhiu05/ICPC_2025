#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
const int MAXN = 1e3 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int n; 
char a[MAXN][MAXN];

int check(){
    FOR(i, 1, n){
        FOR(j, 1, n){
            // check row
            if(j >= 3 && j <= n - 3){
                int cnt_row = 0;
                
                for(int k = -2; k <= 3; ++k){
                    if(a[i][j + k] != '#') ++cnt_row;
                }
                
                // if(i == 2) cout << cnt_row;
                if(cnt_row <= 2) {
                    return 1;
                }
            }
            
            if(i >= 3 && i <= n - 3){
                // check col
                int cnt_col = 0;
                FOR(k, -2, 3){
                    if(a[i + k][j] != '#') ++cnt_col;
                }
                if(cnt_col <= 2) {
                    // cout << i << " " << j << endl;
                    return 1;
                }
            }

            if(i >= 3 && j <= n && i >= 3 && j <= n){
                // check dia1
                int cnt_dia1 = 0;
                FOR(k, -2, 3){
                    if(a[i + k][j + k] != '#') ++cnt_dia1;
                }
                if(cnt_dia1 <= 2) {
                    // cout << i << " " << j << endl;
                    return 1;
                }
            }

            if(i >= 3 && j <= n && i >= 3 && j <= n){
                // check dia2
                int cnt_dia2 = 0;
                FOR(k, -2, 3){
                    if(a[i - k][j + k] != '#') ++cnt_dia2;
                }
                if(cnt_dia2 <= 2) {
                    // cout << i << " " << j << endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}

signed main(){
    faster;

    cin >> n;
    FOR(i, 1, n){
        FOR(j, 1, n){
            cin >> a[i][j];
        }
    }

    if(n < 6){
        cout << "No";
        return 0;
    }

    if(check()) cout << "Yes";
    else cout << "No";

    return 0;
}