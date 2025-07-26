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

int a[MAXN], n;
int bit[MAXN];

// số phần tử <= p
int getSum(int p){
    int idx = p, ans = 0;
    while(idx > 0){
        ans += bit[idx];
        idx -= (idx & (-idx));
    }
    return ans;
}

void update(int u, int k){
    int idx = u;
    while(idx <= n){
        bit[idx] += k;
        idx += (idx & (-idx));
    }
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        cin >> n;
        FOR(i, 1, n) cin >> a[i];

        vi left_greater(n + 1, 0), right_less(n + 1, 0);

        memset(bit, 0, sizeof(bit));
        FOR(i, 1, n){
            left_greater[i] = getSum(n) - getSum(a[i]);
            update(a[i], 1);
        }

        memset(bit, 0, sizeof(bit));
        FOD(i, n, 1){
            right_less[i] = getSum(a[i] - 1);
            update(a[i], 1);
        }

        int ans = 0;
        FOR(i, 1, n){
            ans += left_greater[i] * right_less[i];
        }
        cout << ans << endl;
        
    }
    return 0;
}