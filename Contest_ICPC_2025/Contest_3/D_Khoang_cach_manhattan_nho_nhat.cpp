#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
const int INF = 1e18;

using namespace std;

// Biến thể diameter trong metric Manhattan
// Đặt u = x + y, v = x - y. Khi đó d(A, B) = |x_A - x_B| + |y_A - yB| = max(|u_A - u_B|, |v_A - v_B|)
// Khi đó khoảng cách lớn nhất giữa 2 điểm bất kỳ là: D =  max(max(u) - min(u), max(v) - min(v))
// Yêu cầu: Cần xóa đi 1 điểm sao cho D min (Cực tiểu hóa D)


// trả về A[{}] với A[i] là {max, min} của a[] khi xóa a[i]
vector<ii> rmov(vi a, int n){
    vi preMin(n + 1), preMax(n + 1), sufMin(n + 1), sufMax(n + 1);

    preMin[1] = a[1];
    preMax[1] = a[1];
    FOR(i, 2, n){
        preMin[i] = min(preMin[i - 1], a[i]);
        preMax[i] = max(preMax[i - 1], a[i]);
    }

    sufMin[n] = a[n];
    sufMax[n] = a[n];
    FOD(i, n - 1, 1){
        sufMin[i] = min(sufMin[i + 1], a[i]);
        sufMax[i] = max(sufMax[i + 1], a[i]);
    }

    vector<ii> res(n + 1);
    FOR(i, 1, n){
        if(i == 1){
            res[i] = {sufMax[i], sufMin[i]};
        }
        else if(i == n){
            res[i] = {preMax[i], preMin[i]};
        }
        else{
            res[i] = {max(preMax[i - 1], sufMax[i + 1]), min(preMin[i - 1], sufMin[i + 1])};
        }
    }
    return res;
}

signed main(){
    faster;

    int n; cin >> n;
    vi u(n + 1), v(n + 1);
    FOR(i, 1, n){
        int x, y; cin >> x >> y;
        u[i] = x + y;
        v[i] = x - y;
    }

    // tính  min (D =  max(max(u) - min(u), max(v) - min(v)))
    vector<ii> ru = rmov(u, n), rv = rmov(v, n);
    int ans = INF;
    FOR(i, 1, n){
        int du = ru[i].fi - ru[i].sc;
        int dv = rv[i].fi - rv[i].sc;
        ans = min(ans, max(du, dv));
    }
    cout << ans;
    
    return 0;
}