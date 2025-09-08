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
struct P {
    ll gt;
    int p, k;
};
vector<P> a;

int cmp(P X, P Y){
    return X.gt < Y.gt; 
}

int bs(int n, vector<P>& a) {
    int l = 0, r = a.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid].gt == n) return mid;
        else if(a[mid].gt < n) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
signed main(){
    faster;
    int n;
    cin >> n;
    vi arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<int> s;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            //if(i == j) continue;
            ll t = 3 * arr[i] - arr[j];
            P tmp;
            tmp.gt = t;
            tmp.p = i;
            tmp.k = j;
            a.push_back(tmp);
        }
    }

    sort(all(a), cmp);
    // FOR(i, 0, a.sz() - 1) cout << a[i].gt << " ";
    // cout << endl;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            ll t = arr[i] + arr[j];
            int check = bs(t, a);
            if(check != -1 && a[check].k != i && a[check].k != j) {
                s.insert(a[check].p);
                // cout << i << " " << j << " " << a[check].k << " " << a[check].p << endl;
            }
        }
    }
    cout << s.size();
    return 0;
}