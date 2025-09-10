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
const int MAXN = 2e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    int cnt[MAXN] = {0};
    FOR(i, 1, n){
        int x; cin >> x;
        if(x <= n + 1) cnt[x]++;
    }

    int mex = 0;
    while(mex <= n + 1 && cnt[mex] > 0){
        mex++;
    }

    vi ans;
    FOR(iter, 1, 10){
        int total_cnt = 0;
        FOR(i, 0, n + 1){
            if(cnt[i] > 1 || i > mex){
                total_cnt += cnt[i];
                cnt[i] = 0;
            }
        }
        cnt[mex] = total_cnt;

        int sum = 0;
        FOR(i, 0, n + 1){
            sum += cnt[i] * i;
        }
        ans.pb(sum);

        mex = 0;
        while(mex <= n + 1 && cnt[mex] > 0){
            mex++;
        }
    }

    if(k <= 10){
        cout << ans[k - 1] << endl;
    }
    else{
        k %= 2;
        cout << ans[9 - k] << endl;
    }

}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}