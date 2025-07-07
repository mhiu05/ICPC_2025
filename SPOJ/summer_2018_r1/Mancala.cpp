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

    vi a(15);
    FOR(i, 1, 14) cin >> a[i];

    ll total_max = 0;
    FOR(i, 1, 14){
        vi b = a;
        int k = a[i];
        if(k != 0){
            int r = k % 14;
            b[i] = 0;
            FOR(j, 1, 14){
                b[j] += k / 14;
            }
            
            int pos = i;
            FOR(t, 1, r){
                pos++;
                if (pos > 14) pos = 1;
                b[pos]++;
            }
            
            // FOR(j, 1, 14) cout << b[j] << " ";
            // cout << endl;
            
            ll sum = 0;
            FOR(j, 1, 14){
                if(b[j] % 2 == 0){
                    sum += b[j];
                }
            }
            total_max = max(total_max, sum);
        }
    }
    cout << total_max;
    return 0;
}
