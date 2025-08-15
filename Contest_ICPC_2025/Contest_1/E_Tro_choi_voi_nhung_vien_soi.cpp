#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz size
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int,int>
#define fi first 
#define sc second
#define faster ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const double EPS = 1e-10;
const int INF = 1e9;

using namespace std;

// Đề: Người 1: A, người 2: B
// 1: Có n viên sỏi, mỗi lượt người chơi có thể bốc 1 <= x <= n viên, A đi trước, B đi sau, luân phiên
// 2: Mỗi lượt người chơi bốc ít nhất 1 và nhiều nhất 2 lần viên sỏi người trước vừa bốc, lượt đầu A có thể bốc bao nhiêu tùy ý
// 3: Người chơi nào lấy viên sỏi cuối cùng là win

// Biến thể nim game

ll F[93];
void fibonacci(){
    F[0] = 0; F[1] = 1;
    FOR(i, 2, 92){
        F[i] = F[i - 1] + F[i - 2];
    }
}

int check(int n){
    FOR(i, 0, 92){
        if(n == F[i]){
            return 1;
        }
    }
    return 0;
}

signed main(){
    faster;
    fibonacci();

    int n; cin >> n;
    
    while(!check(n)){
        int idx = -1;
        FOD(i, 92, 0){
            if(n > F[i]){
                idx = i;
                break;
            }
        }
        n -= F[idx];
    }
    cout << n;

    return 0;
}