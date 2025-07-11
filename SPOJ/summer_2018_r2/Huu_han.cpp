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

// Phân số p / q có biểu diễn hữu hạn trong cơ số b khi và chỉ khi
// mẫu số q sau khi tối giản chỉ chứa các tsnt là ước của b

signed main(){
    faster;

    int n; cin >> n;
    while(n--){
        ll p, q, b; cin >> p >> q >> b;
        
        if(p == 0 || q == 1){
            cout << "Finite\n";
            continue;
        }

        ll ms = q / __gcd(p, q);

        while(1){
            ms /= __gcd(ms, b);
            if(__gcd(ms, b) == 1) break;
        }

        if(ms == 1) cout << "Finite\n";
        else cout <<"Infinite\n";
    }

    return 0;
}