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

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

using namespace std;

ll C[65][65];
void sieveCombination(){
    for(int i = 0; i <= 60; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0) C[i][j] = 1;
            else if(i == j) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

string findString(int a, int b, ll k){
    if (a == 0) return string(b, 'b');
    if (b == 0) return string(a, 'a');

    ll X = C[a + b - 1][a - 1];
    if(k <= X) return "a" + findString(a - 1, b, k);
    else return "b" + findString(a, b - 1, k - X);
}

int main(){
    faster;
    sieveCombination();

    ll a, b, k; cin >> a >> b >> k;
    cout << findString(a, b, k);
    return 0;
} 