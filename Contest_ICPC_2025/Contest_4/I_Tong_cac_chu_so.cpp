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

int tcs(int n){
    int sum =  0;
    while(n != 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void solve(){
    int N, S; cin >> N >> S;
    
    if(tcs(N) <= S){
        cout << 0 << endl;
        return;
    }

    int ans = 0, pw = 1;
    while(tcs(N) > S){
        int x = (N / pw) % 10;

        int inc = (10 - x) * pw;
        N += inc;
        ans += inc;
        pw *= 10;
    }
    cout << ans << endl;
    
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}