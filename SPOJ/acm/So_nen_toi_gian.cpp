#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n = 0; cin >> n;
        int tmp = 0; 
        while(n>0) {
           tmp = tmp + n % 10; 
           n /= 10;
           if(n == 0 && tmp > 9) {
            n = tmp;
            tmp = 0;    
           }
        }
        cout << tmp << endl;
    }
}