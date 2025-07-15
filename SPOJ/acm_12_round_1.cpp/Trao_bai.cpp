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
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

signed main(){
    faster;

    int m, k; cin >> m >> k;
    string s; cin >> s;

    deque<int> dq;
    FOD(i, m - 1, 0) dq.push_front(i);

    FOR(i, 0, s.sz() - 2){
        if(s[i] == 'A'){
            int a = dq.front(); dq.pop_front();
            dq.push_back(a);
        }
        else{
            int a = dq.front(); dq.pop_front();
            int b = dq.front(); dq.pop_front();
            dq.push_front(a);
            dq.push_back(b);
        }
    }

    FOR(i, 1, k - 1) dq.pop_front();
    FOR(i, 1, 3){
        int a = dq.front(); dq.pop_front();
        cout << a << " ";
    }

    return 0;
}