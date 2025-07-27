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

// Đề: Cho dãy số a[] có n phần tử. Mỗi phần tử sẽ cần được gán cho một màu sắc nào đó sao cho tính chất sau luôn được thỏa mãn:
// với i < j mà a[i] < a[j] thì được tô cùng 1 màu. Xác định xem cần sử dụng ít nhất bao nhiêu màu để có thể tô màu được dãy số đã cho.
// VD a[] = {3,1,4,5,2}: 3, 4, 5 cùng 1 màu, 1, 2 cùng 1 màu => cần tối thiểu 2 màu

// ycbt: Tìm dãy con giảm (không ngặt) không liên tiếp dài nhất O(NlogN)

signed main(){
    faster;

    int n; cin >> n;
    int a[n + 1], b[n + 1];
    FOR(i, 0, n - 1){
        cin >> a[i];
        b[i] = -a[i];
    }

    vi c;
    FOR(i, 0, n - 1){
        auto it = upper_bound(all(c), b[i]);
        if(it == c.end()){
            c.pb(b[i]);
        }
        else *it = b[i];
    }

    cout << c.sz();
    return 0;
}