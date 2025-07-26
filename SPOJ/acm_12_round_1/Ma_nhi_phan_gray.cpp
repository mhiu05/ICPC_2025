#include <bits/stdc++.h>
#define ll long long
// #define int long long
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

// Công thức chuyển từ nhị phân sang gray: Gray(n) = n ^ (n >> 1)

void print(int gray, int n){
    FOD(i, n - 1, 0){
        cout << ((gray >> i) & 1);
    }
}

signed main(){
    faster;

    int n; cin >> n;
    int k = n;
    FOR(i, 0, (1 << n) - 1){
        int gray = i ^ (i >> 1);
        print(gray, n);
        cout << endl;
    }

    return 0;
}