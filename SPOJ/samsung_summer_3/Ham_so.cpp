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

// s[i] = |a[i] - a[i + 1]| với 1 <= i <= n - 1
// kadane's algorithms trên s1[], s2[] với s1[] = -s[i] khi i lẻ, s2[] = -s[i] khi i chẵn

ll kadane(ll s[], ll n){
    ll max_val = LLONG_MIN;
    ll sum = 0;
    FOR(i, 1, n - 1){
        sum = max(s[i], sum + s[i]);
        max_val = max(max_val, sum);
    }
    return max_val;
}

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n + 1];
        FOR(i, 1, n) cin >> a[i];

        ll s1[n], s2[n];

        FOR(i, 1, n - 1){
            int tmp = abs(a[i] - a[i + 1]);
            if(i % 2 == 0) {
                s1[i] = tmp;
                s2[i] = -tmp;
            }
            else {
                s1[i] = -tmp;
                s2[i] = tmp;
            }
        }

        cout << max(kadane(s1, n), kadane(s2, n)) << endl;
    }

    return 0;
}