#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
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

int n, p;

void solve(){
    if(n == 1){
        cout << p;
        return;
    }
    if(p == 1){
        cout << 1;
        return;
    }

    int N = p;
    int ans = 1;
    FOR(i, 2, (int)sqrt(N)){
        if(N % i == 0){
            int cnt = 0;
            while(N % i == 0){
                ++cnt;
                if(cnt % n == 0) ans *= i;
                N /= i;
            }
        }
    }
    if(N != 1) {
        if(n <= 1) ans *= N;
    }

    cout << ans;
}

signed main(){
    faster;

    cin >> n >> p;
    solve();

    return 0;
}