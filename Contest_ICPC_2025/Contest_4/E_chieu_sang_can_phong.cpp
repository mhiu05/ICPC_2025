// #include <bits/stdc++.h>
// using namespace std;

// struct Point {
//     double x, y;
// };

// using Polygon = vector<Point>;

// double cross(const Point& a, const Point& b, const Point& c) {
//     return (b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x);
// }

// double area(const Polygon& poly) {
//     double s = 0;
//     int n = poly.size();
//     for(int i=0;i<n;i++){
//         int j=(i+1)%n;
//         s += poly[i].x*poly[j].y - poly[i].y*poly[j].x;
//     }
//     return fabs(s)/2.0;
// }

// // cắt poly bởi nửa mặt phẳng (A,B) giữ bên trái
// Polygon cutPolygon(const Polygon& poly, Point A, Point B){
//     Polygon newPoly;
//     int n=poly.size();
//     for(int i=0;i<n;i++){
//         Point C=poly[i];
//         Point D=poly[(i+1)%n];
//         double c1=cross(A,B,C);
//         double c2=cross(A,B,D);
//         if(c1>=-1e-9) newPoly.push_back(C);
//         if(c1*c2< -1e-9){
//             double t=fabs(c1)/(fabs(c1)+fabs(c2));
//             Point I{ C.x+(D.x-C.x)*t, C.y+(D.y-C.y)*t };
//             newPoly.push_back(I);
//         }
//     }
//     return newPoly;
// }

// // giao 2 đa giác lồi
// Polygon intersectPoly(const Polygon& P, const Polygon& Q){
//     Polygon res=P;
//     int m=Q.size();
//     for(int i=0;i<m;i++){
//         res=cutPolygon(res,Q[i],Q[(i+1)%m]);
//         if(res.empty()) break;
//     }
//     return res;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T; cin>>T;
//     cout<<fixed<<setprecision(5);
//     while(T--){
//         int N,W,L;
//         cin>>N>>W>>L;
//         vector<int> glass(W);
//         for(int i=0;i<W;i++) cin>>glass[i];
//         vector<Point> lights(L);
//         for(int i=0;i<L;i++) cin>>lights[i].x>>lights[i].y;
//         Polygon room(N);
//         for(int i=0;i<N;i++) cin>>room[i].x>>room[i].y;

//         vector<Polygon> polys;
//         double BIG=1e6;

//         for(auto li:lights){
//             for(auto g:glass){
//                 int u=g-1, v=g%N;
//                 Point A=room[u], B=room[v];

//                 // kéo dài tia
//                 Point A2{ A.x + (A.x-li.x)*BIG, A.y + (A.y-li.y)*BIG };
//                 Point B2{ B.x + (B.x-li.x)*BIG, B.y + (B.y-li.y)*BIG };

//                 Polygon beam = {A,B,B2,A2};

//                 Polygon inter = intersectPoly(room, beam);
//                 if(!inter.empty()) polys.push_back(inter);
//             }
//         }

//         // inclusion-exclusion để tính hợp
//         int M=polys.size();
//         double total=0;
//         for(int mask=1; mask < (1<<M); mask++){
//             Polygon cur=polys[__builtin_ctz(mask)];
//             for(int j=__builtin_ctz(mask)+1;j<M;j++){
//                 if(mask>>j &1){
//                     cur=intersectPoly(cur, polys[j]);
//                     if(cur.empty()) break;
//                 }
//             }
//             double a=area(cur);
//             if(__builtin_popcount(mask)%2==1) total+=a;
//             else total-=a;
//         }
//         cout<<total<<"\n";
//     }
// }

#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,a,b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pf push_front
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

signed main(){
    faster;

    cout << "No Solution";   

    return 0;
}