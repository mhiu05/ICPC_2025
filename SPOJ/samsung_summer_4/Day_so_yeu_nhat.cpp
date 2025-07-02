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

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double EPS = 1e-11;

using namespace std;

// Bài toán tối ưu cực trị minimize max of something (convex function)
// Ternary search (Tìm X): https://wiki.vnoi.info/translate/emaxx/Tim-kiem-tam-phan-Ternary-Search
// Kadane's algorithm: Tìm độ yếu (cực trị)

int n;
int a[MAXN];

// tìm độ yếu
double getVal(double X){
    double b[MAXN];
    FOR(i, 1, n) b[i] = 1.0 * a[i] - X;

    // find max
    double sum1 = 0, max_sum = 0;
    FOR(i, 1, n){
        sum1 = max(0.0, sum1 + b[i]);
        max_sum = max(sum1, max_sum);
    }

    // find min
    double sum2 = 0, min_sum = 0;
    FOR(i, 1, n){
        sum2 = min(0.0, sum2 + b[i]);
        min_sum = min(sum2, min_sum);
    }

    return max(abs(max_sum), abs(min_sum));
}

signed main(){
    faster;

    cin >> n;
    FOR(i, 1, n) cin >> a[i];

    // ternary search
    double l = -10000, r = 10000;

    while(r - l > EPS){
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;

        if(getVal(m1) < getVal(m2)) r = m2;
        else l = m1;
    }

    double best_choice = (l + r) / 2;
    cout << fixed << setprecision(6) << getVal(best_choice);

    return 0;
}