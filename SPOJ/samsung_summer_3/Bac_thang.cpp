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

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int dp[n + 5] = {0};
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= k; ++j){
                if(i - j >= 0){
                    dp[i] += dp[i - j];
                    dp[i] %= mod;
                }
            }
        }
        cout << dp[n] << endl;
    }

    return 0;
}