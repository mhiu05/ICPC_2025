#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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

void solve(){
    int n, k; cin >> n >> k;
    int S[n + 1], T[n + 1];

    map<int, int> mp;
    FOR(i, 1, n) {
        cin >> S[i];
        S[i] %= k;
    }
    FOR(i, 1, n) {
        cin >> T[i];
        T[i] %= k;
        mp[T[i]]++;
    }

    int check = 1;
    FOR(i, 1 , n){
        if(mp[S[i]] == 0){
            if(mp[k - S[i]] == 0){
                check = 0;
                break;
            }
            else{
                mp[k - S[i]]--;
            }
        }
        else{
            mp[S[i]]--;
        }
    }

    if(check) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}