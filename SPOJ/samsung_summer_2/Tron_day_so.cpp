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

// Chọn ra n(hoặc m) chỗ trong trong n + m chỗ để chèn vào 1 dãy với đúng 1 cách sắp xếp duy nhất ko làm đổi thứ tự
// Dãy còn lại tự động thêm vào m(hoặc n) chỗ còn lại với 1 cách duy nhất 
// Số cách là C[n][n + m]

ll C[205][205];
void combination(){
    for(int i = 0; i <= 200; ++i){
        for(int j = 0; j <= i; ++j){
            if(j == 0 || i == j) C[i][j] = 1;
            else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= mod;
            }
        }
    }
}

int main(){
    faster;

    combination();
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << C[n + m][n] << endl;
    }
    return 0;
}