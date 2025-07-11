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

    string a, b; cin >> a >> b;

    // ít nhất 1 lần :)
    if(b == a){
        cout << "No";
        return 0;
    }

    while(b.sz() > a.sz()){
        if(b.front() == 'A') b = b.substr(1);
        else{
            b = b.substr(1);
            reverse(b.begin(), b.end());
        }    
    }

    if(b == a) cout << "Yes";
    else cout << "No";

    return 0;
}