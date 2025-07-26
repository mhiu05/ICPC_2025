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
    ll n, s;
    cin >> n >> s;
    ll a[n + 1];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<pair<ll, int>> l;
    vector<pair<ll, int>> r;

    int n1 = n / 2;
    int n2 = n - n1;
    for(int msk = 0; msk < (1 << n1); msk++) {
        ll sum = 0;
        int cnt = 0;
        for(int i = 0; i < n1; i++) {
            if(msk & (1 << i)) {
                sum += a[i];
                cnt++;
            }
        }
        l.emplace_back(sum, cnt);
    }

    for(int msk = 0; msk < (1 << n2); msk++) {
        ll sum = 0;
        int cnt = 0;
        for(int i = 0; i < n2; i++) {
            if(msk & (1 << i)) {
                sum += a[n1 + i];
                cnt++;
            }
        }
        r.emplace_back(sum, cnt);
    }

    unordered_map<ll, int> mp;
    for(pair<ll, int> p: r) {
        if(!mp.count(p.first)) mp[p.first] = p.second;
        else mp[p.first] = min(mp[p.first], p.second);

    }
    int res = INF;
    for(pair<ll, int> p: l) {
        ll tmp = s - p.first;
        if(mp.count(tmp)) {
            res = min(res, p.second + mp[tmp]);
        }
    }
    if(res == INF) cout << -1;
    else  cout << res << '\n';

    return 0;
}   