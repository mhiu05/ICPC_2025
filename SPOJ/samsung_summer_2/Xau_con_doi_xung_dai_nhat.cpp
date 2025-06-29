#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

//version O(n^2)

int dp[5005][5005];

void solve(string s){
    memset(dp, 0, sizeof(dp));
    int max_len = 1;

    FOR(i, 0, s.sz() - 1) dp[i][i] = 1;
    FOR(i, 0, s.sz() - 2){
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            max_len = 2;
        }
    }

    for(int len = 3; len <= s.sz(); ++len){
        for(int l = 0; l + len - 1 <= s.sz() - 1; ++l){
            int r = l + len - 1;
            if(s[l] == s[r] && dp[l + 1][r - 1] == 1){
                dp[l][r] = 1;
                max_len = max(max_len, r - l + 1);
            }
        }
    }
    cout << max_len << endl;
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        solve(s);
    }

    return 0;
}