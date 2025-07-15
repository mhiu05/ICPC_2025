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

int n;
char a[101][101];
string dp[101][101];


signed main(){
    faster;

    cin >> n;
    FOR(i, 1, n){
        FOR(j, 1, n){
            cin >> a[i][j];
            dp[i][j] = "";
        }
    }

    dp[1][1] += a[1][1];
    FOR(i, 2, n){
        dp[i][1] = dp[i - 1][1] + a[i][1];
    }
    FOR(j, 2, n){
        dp[1][j] = dp[1][j - 1] + a[1][j];
    }

    FOR(i, 2, n){
        FOR(j, 2, n){
            string s1 = dp[i - 1][j] + a[i][j];
            string s2 = dp[i][j - 1] + a[i][j];

            while(s1[0] == '0' && s1.sz() > 1) s1.erase(0, 1);
            while(s2[0] == '0' && s2.sz() > 1) s2.erase(0, 1);

            if(s1.sz() < s2.sz()) dp[i][j] = s2;
            else if(s1.sz() > s2.sz()) dp[i][j] = s1;
            else dp[i][j] = max(s1, s2);
        }
    }

    string s = dp[n][n];
    while(s.sz() % 4 != 0){
        s = "0" + s;
    }

    string ans = "";

    for(int i = 0; i < s.sz(); i += 4){
        int a = (s[i] - '0') * 8 + (s[i + 1] - '0') * 4 + (s[i + 2] - '0') * 2 + (s[i + 3] - '0');
        if(a <= 9) ans.pb(a + '0');
        else if(a == 10) ans.pb('A');
        else if(a == 11) ans.pb('B');
        else if(a == 12) ans.pb('C');
        else if(a == 13) ans.pb('D');
        else if(a == 14) ans.pb('E');
        else ans.pb('F');
    }

    while(ans[0] == '0' && ans.sz() > 1) ans.erase(0, 1);

    cout << ans;

    return 0;
}