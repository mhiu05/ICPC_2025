#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modi = 1e9;
ll modl = 1e18;


int main(){
	ll n;
	while(cin >> n){
		if(n == 0) return 0;
		else{
			ll kq = 1;
			for(int i = 1; i <= n; ++i){
				kq *= i;
			}
			cout << kq << endl;
		}
	}
	return 0;
}