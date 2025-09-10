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

void solve(){
    int n; cin >> n;
    map<int, vi> mp; // lưu các chỉ số của 1 giá trị
    int b[n + 1]; 
    FOR(i, 1, n) {
        cin >> b[i];
        if(b[i] != 1) {
            mp[b[i]].pb(i);
        }
    }

    for(auto it : mp){
        if((it.sc).sz() % it.fi != 0){
            cout << -1 << endl;
            return;
        }
    }

    vi ans(n + 1);
    int cnt = 1;
    FOR(i, 1, n){
        if(b[i] == 1){
            ans[i] = cnt;
            ++cnt;  
        }
    }
    
    for(auto it : mp){
        // cout << it.fi << endl;
        // FOR(i, 0, it.sc.sz() - 1) cout << it.sc[i] << " ";
        // cout << endl;
        FOR(i, 0, (it.sc).sz() - 1){
            if(i != 0 && i % it.fi == 0) {
                ++cnt;
                // cout << "____\n";
            }
            ans[it.sc[i]] = cnt;
        }
        
        ++cnt;
    }

    FOR(i, 1, n) cout << ans[i] << " ";
    cout << endl;

}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}