#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int modi = 1e9;
ll modl = 1e18;

int scp(ll n){
	ll can = sqrt(n);
	if(can * can == n) return 1;
	else return 0;
}

ll tongUoc(ll n){
	if(n == 1) return 1;
	ll sum = 1;
	for(ll i = 2; i < sqrt(n); ++i){
		if(n % i == 0){
			sum = sum + i + n / i;
		}
	}
	if(scp(n)) sum += sqrt(n);
	sum += n;
	return sum;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int t; scanf("%d", &t);
	ll n; 
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", tongUoc(n));
	}
	return 0;
}