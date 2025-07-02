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

int check_0(int a[], int n){
    FOR(i, 1, n){
        if(a[i] != 0) return 0;
    }
    return 1;
}

void solve(int a[], int n){
    if(check_0(a, n)){
        cout << "NO\n";
        return;
    }
    int gcd = a[1];
    FOR(i, 2, n){
        gcd = __gcd(a[i], gcd);
    }
    if(gcd >= 2){
        cout << "YES 0\n";
        return;
    }

    int cnt = 0, ans = 0;
    FOR(i, 1, n){
        if(a[i] % 2 != 0){
            ++cnt;
        }
        else{
            if(cnt % 2 == 0){
                ans += cnt / 2;
            }
            else{
                ans += cnt / 2 + 2;
            }
            cnt = 0;
        }
    }
    if(cnt != 0){
        if(cnt % 2 == 0) ans += cnt/ 2;
        else ans += cnt / 2 + 2;
    }
    cout << "YES" << " " << ans << endl;     
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1];
        FOR(i, 1, n) cin >> a[i];
        solve(a, n);
    }

    return 0;
}