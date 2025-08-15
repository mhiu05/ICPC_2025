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

// điều kiện cần và đủ: Một đa giác có N cạnh có tính chất: 
// độ dài của cạnh dài nhất phải nhỏ hơn tổng của N-1 cạnh còn lại.

signed main(){
    faster;

    int n; cin >> n;
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];

    sort(a + 1, a + n + 1);

    int sum = 0;
    FOR(i, 1, n - 1){
        sum += a[i];
    }

    if(sum > a[n]) cout << "Yes";
    else cout << "No";

    return 0;
}