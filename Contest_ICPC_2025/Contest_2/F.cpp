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

signed main(){
    faster;

    int n; cin >> n;
    vi a(n + 1), b(n + 1);
    int S = 0;
    FOR(i, 1, n){
        cin >> a[i];
        S += a[i];
    }
    FOR(i, 1, n) cin >> b[i];

    // tìm k
    vi b1 = b;
    sort(b1.begin() + 1, b1.end(), greater<int>());
    int k = 0, sum = 0;
    FOR(i, 1, n){
        sum += b1[i];
        if(sum >= S){
            k = i;
            break;
        }
    }

    // tìm t
    vvi dp(k + 1, vi(S + 1, -1));
    dp[0][0] = 0;

    FOR(i, 1, n){
        FOD(j, k, 1){
            FOD(h, S, 0){
                if(dp[j - 1][h] != -1){
                    int new_h = h + b[i];
                    new_h = min(S, new_h);
                    dp[j][new_h] = max(dp[j][new_h], dp[j - 1][h] + a[i]);
                }
            }
        }
    }

    int t = S - dp[k][S];
    cout << k << " " << t;

    return 0;
}