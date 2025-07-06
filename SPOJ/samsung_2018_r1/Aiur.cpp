#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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

    ll n; cin >> n;
    while(n--){
        ll DZ, AZ, DD, DH, DM, DS, FH, FM, FS;
        cin >> DZ >> AZ >> DD >> DH >> DM >> DS >> FH >> FM >> FS;
        ll AS = (DS + FS);
        ll AM = (DM + FM + AS / 100);
        ll AH = (DH + FH + (AZ - DZ) + AM / 100);
        if(AH < 0){
            DD--;
            AH += 100;
        }
        else if(AH >=100){
            DD += AH / 100;
            AH -= 100 * (AH / 100);
        }
        ll AD = DD;
        cout << AD << " " << AH << " " << AM % 100 << " " << AS % 100<< endl;
    }
    return 0;
}
