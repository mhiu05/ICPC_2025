#include <bits/stdc++.h>
#define ll long long
#define int long long
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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int roundUp(string &ans) {
    int i = ans.size() - 2;  // Bỏ chữ số cuối (vị trí 400000)
    while (i >= 0 && ans[i] == '9') {
        ans[i] = '0';
        i--;
    }
    if (i == -1) {
        // Làm tròn vượt lên 1 đơn vị nguyên
        return 1;
    }
    ans[i]++;
    ans.pop_back();  // xóa chữ số thứ 400001
    return 0;
}

signed main(){
    faster;

    int n; cin >> n;
    vector<ii> a;
    FOR(i, 1, n){
        ll x, y; cin >> x >> y;
        a.pb({x, y});
    }

    ll ts = a[0].fi, ms = a[0].sc;
    FOR(i, 1, a.sz() - 1){
        ts = a[i].sc * ts + ms * a[i].fi;
        ms = ms * a[i].sc; 
    }

    ll tmp1 = ts, tmp2 = ms;
    ts = ts / __gcd(tmp1, tmp2);
    ms = ms / __gcd(tmp1, tmp2);

    string ans;
    ll r = ts % ms;

    int check = 0;
    while(r != 0){
        check = 1;
        r *= 10;
        ans.pb(r / ms + '0');
        r %= ms;
        if(ans.sz() == 400001) break;
    }

    // làm tròn
    if(ans.size() == 400001){
    if(ans.back() >= '5'){
        bool overflow = roundUp(ans);
        if (overflow) ans.clear();
    } else {
        ans.pop_back();
    }
}

    if(check){
        if(ans.empty()) cout << ts / ms + 1;
        else{
            cout << ts / ms << "." << ans;
        }
    }
    else cout << ts / ms;

    return 0;
}
