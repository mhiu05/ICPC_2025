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

// Đề:
// cho a[], n phần tử, 0 <= a[i] <= M, M là 1 số cho trước
// Trong 1 thao tác, có thể chọn k phần tử bất kì thuộc a[] rồi thay a[i] -> (a[i] + 1) mod M
// Tìm số thao tác tối thiểu để biến a[] thành dãy không giảm
// input:                        output:
// 5 3                           0
// 0 0 1 3 4                     

// 5 7                           1
// 0 6 1 3 2

// 10 10                         6
// 5 0 5 9 4 6 4 5 0 0

int check_(int n, vi a){
    FOR(i, 2, n){
        if(a[i] < a[i - 1]) return 0;
    }
    return 1;
}

int check(int n, int m, int M, vi A){
    vi a = A;
    if(a[1] + M >= m) a[1] = 0; 
    FOR(i, 2, n){
        if(a[i] >= a[i - 1]){
            if(a[i] + M >= m){
                if((a[i] + M) % m >= a[i - 1]){
                    a[i] = a[i - 1];
                }
            }
        }
        else{
            if(a[i] + M < a[i - 1]) return 0;
            a[i] = a[i - 1]; 
        }
    }
    return 1;
}

signed main(){
    faster;

    int n, m; cin >> n >> m;
    vi a(n + 1);
    FOR(i, 1, n) cin >> a[i];

    // Nếu dãy là không giảm từ đầu
    if(check_(n, a)) {
        cout << 0;
        return 0;
    }
    
    int l = 0, r = m - 1;
    int ans = m - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(n, m, mid, a)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}