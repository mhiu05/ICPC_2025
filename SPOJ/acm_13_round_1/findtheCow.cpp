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

using namespace std;
signed main(){
    faster;

    string s;
    cin >> s;
    vi rem1, rem2;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] == '(' && s[i - 1] == '(') rem1.push_back(i);
        else if(s[i] == ')' && s[i - 1] == ')') rem2.push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < rem2.size(); i++) {
        int x = upper_bound(all(rem1), rem2[i]) - rem1.begin();
        ans += x;
    }
    cout << ans;
    return 0;
}