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

// sliding window

int main(){
    faster;

    string s; cin >> s;
    int k, b, m; cin >> k >> b >> m;
        
    // tính B = b^(k - 1)
    ll B = 1;
    FOR(i, 1, k - 1){
        B *= b;
        B %= m;
    }

    ll res = 0;
    FOR(i, 0, k - 1){
        res = b * res + (s[i] - '0');
        res %= m;
    }

    ll ans = res;

    FOR(i, k, s.sz() - 1){
        int new_digit = s[i] - '0';
        int old_digit = s[i - k] - '0';

        res = (res - (old_digit * B) % m + m) % m;

        res = (b * res + new_digit) % m;

        ans += res;
    }
    cout << ans;
    return 0;
}