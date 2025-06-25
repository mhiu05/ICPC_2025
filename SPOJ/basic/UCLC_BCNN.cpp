#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modi = 1e9;
ll modl = 1e18;

ll lcm(ll a, ll b){
	return a * b / __gcd(a, b);
}

int main(){
	ll x, y; 
	while(cin >> x >> y){
		if(x == 0 && y == 0) return 0;
		else{
			cout << __gcd(x, y) << " " << lcm(x, y) << endl;
		}
	}
	return 0;
}