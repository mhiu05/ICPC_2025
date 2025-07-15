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
const int MAXN = 20005;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// duyệt trâu

int covered[MAXN][MAXN];
int offset = 1e4;

signed main(){
    faster;

    int n; cin >> n;
    FOR(i, 0, n - 1){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
 
        FOR(x, x1, x2 - 1){
            FOR(y, y1, y2 - 1){
                covered[x + offset][y + offset] = 1;
            }
        }
    }

    int ans = 0;
    FOR(i, 0, MAXN - 1){
        FOR(j, 0, MAXN - 1){
            if(covered[i][j]) ++ans;
        }
    }
    cout << ans;

    return 0;
}