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

    int x, y; cin >> x >> y;
    cout << y * (y + 1) / 2 + (x - 1) * y + (x - 2) * (x - 1) / 2 << endl;

    int z; cin >> z;

    if (z == 1) {
        cout << "1 1" << endl;
        return 0;
    }

    int l = 1, r = 2e9;
    int k = 0;
    while(l <= r){
        int m = (l + r) / 2;
        if(m * (m - 1) / 2 < z){
            l = m + 1;
            k = m;
        }
        else{
            r = m - 1;
        }
    }
    int j = z - k * (k - 1) / 2;
    int i = k - j + 1;
    cout << i << " " << j;
    return 0;
}