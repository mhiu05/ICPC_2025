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

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll b_cnt = 0, ans = 0;
        FOD(i, s.sz() - 1, 0){
            if(s[i] == 'b') ++b_cnt;
            else{
                ans += b_cnt;
                ans %= MOD;
                b_cnt = 2 * b_cnt;
                b_cnt %= MOD;
            }
        }
        cout << ans << endl;
    }

    return 0;
}