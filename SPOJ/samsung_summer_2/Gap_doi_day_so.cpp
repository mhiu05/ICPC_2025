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

ll solve(ll n, ll k){
    ll X = 1ll * pow(2, n - 1);
    if(k == X) return n;
    else if(k < X) return solve(n - 1, k);
    else return solve(n - 1, k - X);
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        cout << solve(n, k) << endl;
    }

    return 0;
}