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

// Trạng thái thua: |X + Y| <= 1, thắng: |X + Y| > 1.
// Chứng minh từ được: |X + Y| <= 1 dù chọn thế nào cũng ra |X + Y| > 1
//                     |X + Y| > 1 có thể chọn để thành |X + Y| <= 1


signed main(){
    faster;

    int a, b; cin >> a >> b;
    if(abs(a - b) <= 1) cout << "Bob";
    else cout << "Alice";

    return 0;
}