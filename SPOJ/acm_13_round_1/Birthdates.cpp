#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
//#define int long long
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

struct Person {
    string name;
    int day, month;
    string year; 
};
int cmp(Person p1, Person p2) {
    if(p1.year == p2.year) {
        if(p1.month == p2.month) {
            return p1.day < p2.day;
        }
        return p1.month < p2.month;
    }
    return p1.year < p2.year;
}
signed main(){
    faster;
    int n;
    cin >> n;
    Person a[n + 1];
    for(int i = 0; i < n; i++) {
        string s1, s2;
        int d, m;
        cin >> s1 >> d >> m >> s2;
        a[i].name = s1;
        a[i].day = d;
        a[i].month = m;
        a[i].year = s2;
    }
    sort(a, a + n, cmp);
    cout << a[n - 1].name << '\n' << a[0].name;
}