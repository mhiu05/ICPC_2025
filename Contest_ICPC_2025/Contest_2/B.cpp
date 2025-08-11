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
const int MAXN = 2e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

signed main(){
    faster;

    deque<int> dq;
    int n; cin >> n;
    int a[MAXN];
    FOR(i, 1, n){
        cin >> a[i];
        if(i % 2 == 0) dq.push_front(a[i]);
        else dq.push_back(a[i]);
    }

    if(n % 2 == 0){
        while(!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
    else{
        while(!dq.empty()){
            cout << dq.back() << " ";
            dq.pop_back();
        }
    }
    return 0;
}