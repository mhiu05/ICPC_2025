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

int scp(int n){
    int can = sqrt(n);
    return can * can == n;
}

signed main(){
    faster;

    int a; cin >> a;

    int check = 0;
    FOR(i, 1, MAXN){
        int X = 2*a*a - i * i;
        if(X > 1e10) continue;
        if(X >= 1 && scp(X) && i != a && sqrt(X) != a && i != sqrt(X)){
            check = 1;
        }
    }
    if(check) cout << "YES";
    else cout << "NO";
    return 0;
}