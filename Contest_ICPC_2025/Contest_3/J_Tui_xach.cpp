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

signed main(){
    faster;

    int n, c; cin >> n >> c;
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);

    // if(n == 1){
    //     if(a[1] <= c){
    //         cout << 1;
    //     }
    //     else cout << 0;
    //     return 0;
    // }

    int cnt = 0;
    int i = 1, j = n;
    while(i <= j){
        if(a[i] + a[j] <= c){
            ++cnt;
            ++i;
            --j;
        }
        else{
            ++cnt;
            --j;
        }
    }

    cout << cnt;

    return 0;
}