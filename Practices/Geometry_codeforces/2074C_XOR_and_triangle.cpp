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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// sử dụng tính chất: (x^y) = x + y - 2(x&y
// ta được: (x&y) > 0: có ít nhất 1 vị trí mà cả x, y là 1 (1)
//          y > (x&y): có ít nhất 1 vị trí mà y là 1, x là 0 (2)
// => y chỉ cần chứa 2 bit là 1: 1 thỏa mãn (1), 1 thỏa mãn (2)

void solve(){
    int x; cin >> x;
    int ans = -1;
    FOR(i, 0, 30){
        FOR(j, 0, 30){
            if(i != j){
                int y = ((1 << i) | (1 << j));
                if((x + y > (x^y)) && (x + (x^y) > y) && ((x^y) + y > x) && (y < x)){
                    ans = y;
                }
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    faster;


    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}