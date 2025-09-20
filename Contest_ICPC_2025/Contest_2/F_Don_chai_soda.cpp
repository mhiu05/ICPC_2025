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

// Sau khi thì được số lượng chai (k) min thì nó quy về dạng: Chọn k chai sao cho:
// 1. tổng dung tích của chúng ít nhất là total_soda (để chứa hết total_soda)
// 2. tổng lượng soda ban đầu trong các chai là lớn nhất (Để T min)

void solve(){
    int n; cin >> n;
    vi a(n + 1), b(n + 1);
    int total_soda = 0;
    FOR(i, 1, n) {
        cin >> a[i];
        total_soda += a[i];
    }
    FOR(i, 1, n) cin >> b[i];

    int k = -1; // Số lượng chai soda min
    vi B = b;
    sort(B.begin() + 1, B.end(), greater<int>());
    int V = 0;
    FOR(i, 1, n){
        V += B[i];
        if(V >= total_soda){
            k = i;
            break;
        }
    }

    // tìm t
    vvi dp(k + 1, vi(total_soda + 1, -1));
    dp[0][0] = 0;

    FOR(i, 1, n){
        FOD(j, k, 1){
            FOD(h, total_soda, 0){
                if(dp[j - 1][h] != -1){
                    int new_h = h + b[i];
                    new_h = min(total_soda, new_h);
                    dp[j][new_h] = max(dp[j][new_h], dp[j - 1][h] + a[i]); 
                }
            }
        }
    }

    int t = total_soda - dp[k][total_soda];
    cout << k << " " << t;
}

signed main(){
    faster;

    int t = 1; 
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}