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

const ll base = 31;
const ll MOD = 1e9 + 7; 
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int n;
string s;
int h[MAXN], rvH[MAXN], mu[MAXN];

int getHash(int l, int r){
    return (h[r] - h[l - 1] * mu[r - l + 1] % MOD + MOD) % MOD;
}

int getRvHash(int l, int r){
    return (rvH[l] - rvH[r + 1] * mu[r - l + 1] % MOD + MOD) % MOD; 
}


signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        s = "." + s;

        vi odd, even;
        FOR(i, 1, n){
            if(i % 2 == 0) even.pb(i);
            else odd.pb(i);
        }

        // precompute
        h[0] = 0;
        mu[0] = 1;
        FOR(i, 1, n){
            h[i] = (h[i - 1] * base + (s[i] - 'a' + 1)) % MOD;
            mu[i] = (mu[i - 1] * base) % MOD;
        }
        rvH[n + 1] = 0;
        FOD(i, n, 1){
            rvH[i] = (rvH[i + 1] * base + (s[i] - 'a' + 1)) % MOD;
        }

        int max_len = 1;

        int l = 0, r = even.sz() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            int check = 0;
            for(int i = 1; i + even[m] - 1 <= n; ++i){
                if(getHash(i, i + even[m] - 1) == getRvHash(i, i + even[m] - 1)){
                    check = 1;
                    break;
                }
            }
            if(check){
                max_len = max(even[m], max_len);
                l = m + 1;
            }
            else r = m - 1;
        }

        l = 0, r = odd.sz() - 1;
        while(l <= r){
            int m = (l + r) / 2;
            int check = 0;
            for(int i = 1; i + odd[m] - 1 <= n; ++i){
                if(getHash(i, i + odd[m] - 1) == getRvHash(i, i + odd[m] - 1)){
                    check = 1;
                    break;
                }
            }
            if(check){
                max_len = max(max_len, odd[m]);
                l = m + 1;
            }
            else r = m - 1;
        }

        cout << max_len << endl;
    }

    return 0;
}