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

const ll mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

// định lý talet + diện tích tam giác cân chứng minh được:
// h_x = sqrt(x / N) . H

int main(){
    faster;

    int t; cin >> t; 
    while(t--){
        ll N, H; cin >> N >> H;
        for(int i = 1; i <= N - 1; ++i){
            cout << fixed << setprecision(6) << sqrt(1.0 * i / N) * 1.0 * H << " ";
        }
        cout << endl;
    }

    return 0;
}