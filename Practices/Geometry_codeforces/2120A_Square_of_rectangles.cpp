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

int scp(int n){
    int can = sqrt(n);
    return can * can == n;
}

signed main(){
    faster;

    int t; cin >> t;
    while(t--){
        int l1, b1, l2, b2, l3, b3; cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

        int total_area = l1 * b1 + l2 * b2 + l3 * b3;
        int edge_len = max({l1, b1});

        if(scp(total_area) && (int)sqrt(total_area) == edge_len){
            if(l1 == edge_len){
                if(l1 == l2){
                    if(l2 == l3 && b1 + b2 + b3 == edge_len){
                        cout << "YES\n";
                    }
                    else cout << "NO\n";
                }
                else{
                    if(b1 + b2 == edge_len && b1 + b3 == edge_len && l2 + l3 == edge_len){
                        cout << "YES\n";
                    }
                    else cout << "NO\n";
                }
            }
            else {
                if(b1 == b2){
                    if(b2 == b3 && l1 + l2 + l3 == edge_len){
                        cout << "YES\n";
                    }
                    else cout << "NO\n";
                }
                else{
                    if(l1 + l2 == edge_len && l1 + l3 == edge_len && b2 + b3 == edge_len){
                        cout << "YES\n";
                    }
                    else cout << "NO\n";
                }
            }
        }
        else cout << "NO\n";
    }

    return 0;
}