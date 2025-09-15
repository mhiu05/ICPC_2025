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
const int INF = 1e9;

using namespace std;

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        FOR(i, 1, n){
            int x; cin >> x;
            pq.push(x);
        }

        while(pq.size() > 1){
            int x = pq.top(); 
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push(x + y - 1);
        }

        cout << pq.top() << endl;
    }

    return 0;
}