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

// Chỉ cần xét 1 <= k <= k_max = (d - 1) / (c - b)
// ans = k_max - số k bị cấm
// Số k bị cấm là:
// a + b.k <= m.d <= a + c.k
// => Tìm k theo m: (m.d - a) / c <= k <= (m.d - a) / b
// Với m: (a + b) / d <= m <= (a + c.k_max) / d


signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        
        int k_max = (d - 1) / (c - b);

        int ans = 0;

        int m_l = (a + b + d - 1) / d, m_r = (a + c * k_max) / d;

        if(m_l > m_r){
            ans += k_max;
            cout << ans << endl;
            continue;
        }

        vector<ii> v; // chứa đoạn bị cấm
        FOR(m, m_l, m_r){
            if (m * d < a) continue;
            int k_l = (m * d - a + c - 1) / c, k_r = (m * d - a) / b;
            int l = max(1LL, k_l), r = min(k_max, k_r);
            if(l <= r){
                v.pb({l, r});
            }
        }

        // gộp các khoảng bị cấm
        sort(all(v));
        int banned = 0;
        int cur_l = -1, cur_r = -1;
        for(auto it : v){
            int l = it.fi, r = it.sc;
            if(cur_l == -1){
                cur_l = l;
                cur_r = r;
            }
            else{
                if(l <= cur_r + 1){
                    cur_r = max(r, cur_r);
                }
                else{
                    banned += cur_r - cur_l + 1;
                    cur_l = l;
                    cur_r = r;
                }
            }
        }

        if(cur_l != -1){
            banned += cur_r - cur_l + 1;
        }

        ans += k_max - banned;
        cout << ans << endl;
    }

    return 0;
}