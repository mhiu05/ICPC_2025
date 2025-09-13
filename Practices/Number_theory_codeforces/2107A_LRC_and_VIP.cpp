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

// Nếu tất cả phần tử bằng nhau thì NO
// Nếu có 1 phần tử khác thì luôn YES
// Chọn phần tử lớn nhất ra 1 tập hợp (A), các phần tử còn lại thuộc tập khác (B)
// gcd(A) = A, gcd(B) < A vì trong B chỉ chứa các số < A
// => Luôn thỏa mãn gcd(A) khác gcd(B)

int check(vi a, int n){
    FOR(i, 1, n - 1){
        if(a[i] != a[i - 1]) return 0;
    }
    return 1;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    FOR(i, 0, n - 1) cin >> a[i];

    if(check(a, n)){
        cout << "NO\n";
        return;
    }
    else{
        cout << "YES\n";
    }

    int mx = *max_element(all(a));
    FOR(i, 0, n - 1){
        if(a[i] == mx) cout << 1 << " ";
        else cout << 2 << " ";
    }
    cout << endl;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        solve();
    }

    return 0;
}