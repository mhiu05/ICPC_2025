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
const int MAXN = 2005;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

int n, m, x; 
int a[MAXN], b[MAXN];

// Chưa AC

// pre_a lưu tổng nhỏ nhất độ dài i trong a[]
vi pre_a(MAXN, INF), pre_b(MAXN, INF);
void presolve(){
    FOR(i, 1, n){
        int sum = 0;
        FOR(j, i, n){
            sum += a[j];
            int len = j - i + 1;
            pre_a[len] = min(pre_a[len], sum);
        }
    }

    FOR(i, 1, m){
        int sum = 0;
        FOR(j, i, m){
            sum += b[j];
            int len = j - i + 1;
            pre_b[len] = min(pre_b[len], sum);
        }
    }
}

signed main(){
    faster;

    cin >> n >> m;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, m) cin >> b[i];
    cin >> x;

    presolve();

    int max_len = 0;
    FOR(len_a, 1, n){
        FOR(len_b, 1, m){
            if(pre_a[len_a] * pre_b[len_b] <= x){
                max_len = max(max_len, len_a * len_b);
            }
        }
    }
    cout << max_len;
    return 0;
}
