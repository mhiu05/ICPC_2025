#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

void solve(int a[], int b[], int n){
    int cnt = 0;
    FOD(i, n, 1){
        if(a[i] != b[i + cnt]){
            ++cnt;
        }
    }
    cout << cnt << endl;
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 5], b[n + 5];
        FOR(i, 1, n) cin >> a[i];
        FOR(i, 1, n) cin >> b[i];
        solve(a, b, n);
    }

    return 0;
}