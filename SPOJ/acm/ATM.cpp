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
ll n, s;
ll a[100];
using namespace std;

signed main(){
    faster;

    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }    
    int res = INF;
    for(int msk = 0; msk < (1 << n); msk++) {
        ll sum = 0;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(msk & (1 << i)) {
                sum += a[i];
                cnt++;
            }
        }
        if(sum == s) res = min(res, cnt);
    }    
    if(res == INF) cout << -1 << '\n';
    else cout << res;
    return 0;
}