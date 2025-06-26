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
        int a[n + 1];
        FOR(i, 1, n){
            cin >> a[i];
        }
        int dp[10001] = {0};
        dp[0] = 1;
        FOR(j, 1, n){
            FOD(i, k, a[j]){
                if(dp[i - a[j]]){
                    dp[i] = 1;
                }
            }
        }
        if(dp[k]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}