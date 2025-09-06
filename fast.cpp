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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int cmp(string a, string b){
    return a + b > b + a;
}

signed main(){
    faster;

    int n; cin >> n;
    string s[n];
    FOR(i, 0, n - 1){
        int x; cin >> x;
        s[i] = to_string(x);
    }
    sort(s, s + n, greater<string>());
    sort(s, s + min(3*1ll, n), cmp);

    string ans = "";
    FOR(i, 0, min(3*1ll, n) - 1){
        ans += s[i];
    }
    cout << ans;

    return 0;
}