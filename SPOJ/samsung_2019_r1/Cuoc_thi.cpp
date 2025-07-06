#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define int long long
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

signed main(){
    faster;

    int n, m; cin >> n >> m;
    // Ghép những người cùng chuyên môn vào 1 nhóm
    vvi a(m + 1);
    FOR(i, 1, n){
        int s, r; cin >> s >> r;
        a[s].pb(r);
    }

    vi dp(n + 1, 0); // dp[i]: tổng chuyên môn khi chọn i người 
    FOR(i, 1, m){
        if(a[i].empty()) continue; 
        sort(all(a[i]), greater<int>());

        int prefix_sum = 0;
        FOR(j, 0, a[i].sz() - 1){
            prefix_sum += a[i][j];
            if(prefix_sum > 0){
                dp[j + 1] += prefix_sum;
            }
        }
    }
    
    cout << *max_element(dp.begin() + 1, dp.end()) << endl;
    return 0;
}
