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

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

void solve(int a[], int n){
    vector<int> L(n + 1), R(n + 1);
    stack<int> st1;
    FOD(i, n, 1){
        while(!st1.empty() && a[i] <= a[st1.top()]) st1.pop();

        if(st1.empty()) R[i] = n + 1;
        else R[i] = st1.top();

        st1.push(i);
    }

    stack<int> st2;
    FOR(i, 1, n){
        while(!st2.empty() && a[i] <= a[st2.top()]) st2.pop();

        if(st2.empty()) L[i] = 0;
        else L[i] = st2.top();

        st2.push(i);
    }

    ll ans = 0;
    FOR(i, 1, n){
        ans = max(1ll * a[i] * (R[i] - L[i] - 1), ans);
    }
    cout << ans << endl;
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1];
        FOR(i, 1, n) cin >> a[i];
        solve(a, n);
    }

    return 0;
}