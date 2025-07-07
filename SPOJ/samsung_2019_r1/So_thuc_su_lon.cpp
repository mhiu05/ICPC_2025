#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
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

int sum_digit(ll n){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// s + sum_digit(x) <= x <= n
// x thuộc [s + 17*9, n] luôn thỏa mãn vì sum_digit(x) <= 17*9
// Kiểm tra khi x thuộc [s, min(n, s + 17*9 - 1)]

signed main(){
    faster;
    ll n, s; cin >> n >> s;

    ll ans = n - s - 17*9 + 1;
    if (ans < 0) ans = 0;

    FOR(i, s, min(n, s + 17*9 - 1)) {
        if (i - sum_digit(i) >= s) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
