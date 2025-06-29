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

void solve(){
    ll n, k; cin >> n >> k;
    ll a[n + 1], F[n + 1];
    F[0] = 0;
    FOR(i, 1, n){
        cin >> a[i];
        F[i] = F[i - 1] + a[i];
    }
    int i = 1, j = 1;
    while(i <= n && j <= n && i <= j){
        ll sum = F[j] - F[i - 1];
        
        if(sum == k){
            cout << "YES\n";
            return;
        }
        else if(sum < k){
            ++j;
        }
        else{
            ++i;
        }
    }
    cout << "NO\n";
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}