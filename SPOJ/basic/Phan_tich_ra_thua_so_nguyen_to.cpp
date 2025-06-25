#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modi = 1e9;
ll modl = 1e18;

void tsnt(int n){
	for(int i = 2; i <= sqrt(n); ++i){
		if(n % i == 0){
			int dem = 0;
			while(n % i == 0){
				++dem;
				n /= i;
			}
			cout << i << " " << dem << endl;
		}
	}
	if (n != 1) cout << n << " 1" << endl; 
}
int main(){
	int a; cin >> a;
	tsnt(a);
	return 0;
}