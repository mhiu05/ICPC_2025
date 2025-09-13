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

int cal (int l, int r, int d){
    return r / d - (l - 1) / d;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        int cnt2 = cal(l, r, 2);
        int cnt3 = cal(l, r, 3);
        int cnt5 = cal(l, r, 5);
        int cnt7 = cal(l, r, 7);
        
        int cnt23 = cal(l, r, 2*3);
        int cnt25 = cal(l, r, 2*5);
        int cnt27 = cal(l, r, 2*7);
        int cnt35 = cal(l, r, 3*5);
        int cnt37 = cal(l, r, 3*7);
        int cnt57 = cal(l, r, 5*7);
        
        int cnt235 = cal(l, r, 2*3*5);
        int cnt237 = cal(l, r, 2*3*7);
        int cnt257 = cal(l, r, 2*5*7);
        int cnt357 = cal(l, r, 3*5*7);
        
        int cnt2357 = cal(l, r, 2*3*5*7);

        cout << (r - l + 1) - (cnt2 + cnt3 + cnt5 + cnt7 - (cnt23 + cnt25 + cnt27 + cnt35 + cnt37 + cnt57)
                         + cnt235 + cnt237 + cnt257 + cnt357 - cnt2357) << endl;
    }

    return 0;
}
