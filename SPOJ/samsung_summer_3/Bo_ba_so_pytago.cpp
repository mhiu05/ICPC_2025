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

int scp(ll n){
    ll can = sqrt(n);
    return can * can == n;
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n + 1];
        FOR(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1);
        int check = 0;
        FOR(i, 1, n){
            FOR(j, 1, n){
                if(scp(a[i] * a[i] + a[j] * a[j])){
                    if(binary_search(a + 1, a + n + 1 , (ll)sqrt(a[i] * a[i] + a[j] * a[j]))){
                        check = 1;
                    }
                }
            }
        }
        if(check) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}