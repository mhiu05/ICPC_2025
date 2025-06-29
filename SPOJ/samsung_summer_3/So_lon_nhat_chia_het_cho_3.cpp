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

// dư 1: bỏ 1 dư 1 hoặc 2 dư 2, dư 2: bỏ 1 dư 2 hoặc 2 dư 1

int main(){
    faster;

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1];
        int cnt[MAXN] = {0};
        FOR(i, 1, n){
            cin >> a[i];
            cnt[a[i] % 3]++;
        }
        sort(a + 1, a + n + 1, greater<int>());

        int sum = 0;
        FOR(i, 1, n) sum += a[i];

        if(sum % 3 == 1){
            sort(a + 1, a + n + 1);
            vector<int> v;
            if(cnt[1] >= 1){
                int check = 1;
                FOR(i, 1, n){
                    if(check && a[i] % 3 == 1){
                        check = 0;
                        continue;
                    }
                    v.push_back(a[i]);
                }
                sort(v.begin(), v.end(), greater<int>());
                for(int x : v) cout << x;
                cout << endl;
            }
            else if(cnt[2] >= 2 && n > 2){   
                int check = 0;
                FOR(i, 1, n){
                    if(check < 2 && a[i] % 3 == 2){
                        check++;
                        continue;
                    }
                    v.push_back(a[i]);
                }
                sort(v.begin(), v.end(), greater<int>());
                for(int x : v) cout << x;
                cout << endl;
            }
            else cout << -1 << endl;    
        }
        else if(sum % 3 == 2){
            sort(a + 1, a + n + 1);
            vector<int> v;
            if(cnt[2] >= 1){
                int check = 1;
                FOR(i, 1, n){
                    if(check && a[i] % 3 == 2){
                        check = 0;
                        continue;
                    }
                    v.push_back(a[i]);
                }
                sort(v.begin(), v.end(), greater<int>());
                for(int x : v) cout << x;
                cout << endl;
            }
            else if(cnt[1] >= 2 && n > 2){
                int check = 0;
                FOR(i, 1, n){
                    if(check < 2 && a[i] % 3 == 1){
                        check++;
                        continue;
                    }
                    v.push_back(a[i]);
                }
                sort(v.begin(), v.end(), greater<int>());
                for(int x : v) cout << x;
                cout << endl;
            }
            else cout << -1 << endl;
        }
        else{
            FOR(i, 1, n) cout << a[i];
            cout << endl;
        }
    }

    return 0;
}