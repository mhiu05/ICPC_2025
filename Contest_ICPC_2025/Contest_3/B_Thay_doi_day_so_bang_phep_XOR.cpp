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

// Gọi msb(x) là bit 1 lớn nhất của x, nếu mảng có 3 msb(a[i]) bằng nhau thì luôn thỏa mãn 1 bước.
// vì a[i] <= 1e9 nên có khoảng 30 msb(x) khác nhau => n > 60 luôn thỏa mãn 1 bước.


signed main(){
    faster;

    int n; cin >> n;
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];

    if(n > 60){
        cout << 1;
        return 0;
    }

    // với n <= 60
    int ans = INF;
    FOD(len, n, 3){
        FOR(l, 1, n - len + 1){
            int r = l + len - 1;    
            FOR(i, l, r - 1){
                int x1 = 0;
                int x2 = 0;
                FOR(j, l, i){
                    x1 = (x1^a[j]);
                }
                FOR(j, i + 1, r){
                    x2 = (x2^a[j]);
                }
                if(x1 > x2) {
                    ans = min(len - 2, ans);
                }
            }
        }
    }
    if(ans != INF) cout << ans;
    else cout << -1; 

    // cout << (11^81);
    return 0;
}