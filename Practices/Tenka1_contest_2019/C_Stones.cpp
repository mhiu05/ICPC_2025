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
const int MAXN = 2e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// Với mỗi 1 <= i <= n: tính số kí tự cần đổi từ # -> . từ vị trí 1 -> i - 1
//                                               . -> # từ vị trí i -> n
// ans = min(các phương án)

int F1[MAXN], F2[MAXN];

signed main(){
    faster;

    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;

    FOR(i, 1, n){
        if(s[i] == '#') {
            F1[i] = F1[i - 1] + 1;
            F2[i] = F2[i - 1];
        }
        else {
            F1[i] = F1[i - 1];
            F2[i] = F2[i - 1] + 1;
        }
    }

    // Trường hợp chỉ có . hoặc #
    if(F2[n] == n || F1[n] == n){
        cout << 0;
        return 0;
    }

    int ans = INF;
    FOR(i, 1, n){
        int x1 = F1[i] + F2[n] - F2[i];
        int x2 = F1[i - 1] + F2[n] - F2[i - 1];
        // if()
        // cout << i << ": " << F1[i - 1] << " " << F2[n] - F2[i - 1] << endl;
        ans = min({x1, x2, ans}); 
    }

    cout << ans;

    return 0;
}