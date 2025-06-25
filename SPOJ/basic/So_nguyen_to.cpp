#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modi = 1e9;
ll modl = 1e18;

int prime(int n){
	for(int i = 2; i <= sqrt(n); ++i){
		if(n % i == 0) return 0;
	}
	return n > 1;
}

int main(){
	int a; cin >> a;
	if(prime(a)) cout << "YES";
	else cout << "NO";
	return 0;
}