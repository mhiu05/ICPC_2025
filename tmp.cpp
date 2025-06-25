#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define int long long
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>

const int MAX = 1e6+2;
const int MOD = 1e9+7;
const int inf = INT_MAX;
using namespace std;
int BASE;
struct matrix{
	int a[2][2];
};
matrix A={{{1,1},{1,0}}};
matrix I={{{1,0},{0,1}}};
int multiply (int a, int b){
	a = a % BASE;
	b = b % BASE;
	if (b == 0)
		return 0;
	if (b == 1)
		return a;
	int x = multiply(a,b/2);
	int y = x + x;
	if (b%2) y += a;
	return y % BASE;
}
matrix multiply_mt(matrix x, matrix y){
	matrix res={{{0,0},{0,0}}};
	FOR(i,0,1){
		FOR(j,0,1){
			FOR(k,0,1){
				res.a[i][j] = (res.a[i][j] + multiply(x.a[i][k],y.a[k][j])) % BASE; 
			}
		}
	}
	return res;
}
matrix pow_matrix(matrix x, int k){
	if (k == 0) return I;
	matrix y = pow_matrix (x,k/2);
	if (k%2)
		return multiply_mt(multiply_mt(y,y),x);
	else
		return multiply_mt(y,y);
}
void solve(){
	int n;
	matrix f ={{{1,0},{1,0}}};
	cin >> n >> BASE;
	f = multiply_mt(pow_matrix(A,n-1),f);
	cout << f.a[0][0] << endl;
}
signed main(){
//	freopen ("INP.txt", "r", stdin);
//	freopen ("OUT.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}