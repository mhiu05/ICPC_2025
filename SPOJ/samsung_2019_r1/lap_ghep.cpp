#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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

int n;
char a[55][55];

bool place(int i, int j) {
    if (a[i][j] != '.' || a[i+1][j] != '.' || a[i+1][j-1] != '.' || a[i+1][j+1] != '.' || a[i+2][j] != '.')
        return false;
    a[i][j] = a[i+1][j] = a[i+1][j-1] = a[i+1][j+1] = a[i+2][j] = '#';
    return true;
}

signed main(){
    faster;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n - 3; i++) {
        for (int j = 1; j <= n - 2; j++) {
            if (a[i][j] == '.') {
                place(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '.') {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";
    return 0;
}
