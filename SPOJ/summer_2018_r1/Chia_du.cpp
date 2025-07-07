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

void Find(int n, set<int> &se){
    FOR(i, 1, sqrt(n)){
        if(n % i == 0){
            se.insert(i);
            if(i != n / i) se.insert(n / i);
        }
    }
}

int check1(int a[],int b[], int n){
    FOR(i, 1, n){
        if(b[i] > a[i]) return 0;
    }
    return 1;
}

int check2(int a[], int b[], int n){
    FOR(i, 1, n){
        if(b[i] != a[i]) return 0;
    }
    return 1;
}

int check(int b[], int x, int n){
    FOR(i, 1, n){
        if(b[i] >= x) return 0;
    }
    return 1;
}

signed main(){
    faster;

    int n; cin >> n;
    int a[n + 1], b[n + 1];
    set<int> se;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    if(!check1(a, b, n)){
        cout << -1 << endl;
        return 0;
    }
    if(check2(a, b, n)){
        cout << *max_element(a + 1, a + n + 1) + 1 << endl;
        return 0;
    }

    int k = a[1] - b[1];
    FOR(i, 2, n){
        if(a[i] > b[i])k = __gcd(k, a[i] - b[i]);
    }

    Find(k, se);
    for(int x : se){
        bool ok = true;
        FOR(i, 1, n){
            if(a[i] % x != b[i]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
