#include <bits/stdc++.h>
#define ll long long
// #define int long long
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
const int MAXN = 101;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// d[i][j]: kiểm tra chuỗi s[0....i] với p[0....j] 
int d[MAXN][MAXN];
void init(int n, int m){
    FOR(i, 0, n - 1){
        FOR(j, 0, m - 1){
            d[i][j] = -1;
        }
    }
}

int check(string s, string p, int i, int j){
    int i1 = i, j1 = j;

    // Nếu duyệt hết string p
    if(j < 0) return 1;

    // Nếu duyệt hết string s
    if(i < 0){
        while(j >= 0 && p[j] == '*') --j;
        if(j < 0) return 1;
        else return 0;
    }

    if(d[i1][j1] != -1) return d[i1][j1];
    
    if(p[j] == '*'){
        --j;
        if(j < 0) return 1;
        else{
            while(i >= 0 && s[i] != p[j]){
                --i;
            }
            if(i < 0){
                while(j >= 0 && p[j] == '*') --j;
                if(j < 0) return 1;
                else return 0;
            }
            else{
                // check(s, p, i - 1, j - 1): '*' tương ứng với 1 kí tự
                // check(s, p, i - 1, j + 1); tiếp tục xét p gồm cả '*' để '*' tương ứng với nhiều kí tự
                d[i1][j1] = max(check(s, p, i - 1, j - 1), check(s, p, i - 1, j + 1));
                return d[i1][j1];
            }
        }
    }
    else if(p[j] == s[i]){
        d[i1][j1] = check(s, p, i - 1, j - 1);
        return d[i1][j1];
    }
    else{
        d[i1][j1] = 0;
        return d[i1][j1];
    }
}

signed main(){
    faster;

    string p; cin >> p;
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        init(s.sz(), p.sz());
        if(check(s, p, s.sz() - 1, p.sz() - 1)) cout << s << endl;
    }

    return 0;
}