#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Cre: ChatGPT (Đã AC, chưa hiểu)

// Fenwick Tree 1-indexed
struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1,0) {}
    void update(int i, int delta){
        for(; i<=n; i += i&-i) f[i] += delta;
    }
    // sum[1..i]
    int query(int i) const {
        int s=0;
        for(; i>0; i -= i&-i) s += f[i];
        return s;
    }
    // sum[l..r]
    int query(int l, int r) const {
        if(l>r) return 0;
        return query(r) - query(l-1);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vector<pair<int,int>> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i].first >> a[i].second;
    }
    int ax, ay, bx, by, Q;
    cin >> ax >> ay >> bx >> by >> Q;

    // 1) Tính d1, d2
    struct P{ ll d1, d2; };
    vector<P> pts(N);
    vector<ll> all_d2;
    all_d2.reserve(N);
    for(int i=0;i<N;i++){
        ll dx1 = a[i].first - ax;
        ll dy1 = a[i].second - ay;
        ll dx2 = a[i].first - bx;
        ll dy2 = a[i].second - by;
        pts[i].d1 = dx1*dx1 + dy1*dy1;
        pts[i].d2 = dx2*dx2 + dy2*dy2;
        all_d2.push_back(pts[i].d2);
    }

    // 2) compress d2
    sort(all_d2.begin(), all_d2.end());
    all_d2.erase(unique(all_d2.begin(), all_d2.end()), all_d2.end());
    int M = all_d2.size();
    auto getD2 = [&](ll x){
        return int(upper_bound(all_d2.begin(), all_d2.end(), x) - all_d2.begin());
        // gives # of elements <= x
    };

    // 3) sort điểm theo d1 tăng
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int i, int j){ return pts[i].d1 < pts[j].d1; });

    // 4) đọc truy vấn, giữ cả chỉ số để trả về sau
    struct Qry{
        ll R12, R22;
        int idx;
    };
    vector<Qry> qs(Q);
    for(int i=0;i<Q;i++){
        ll R1, R2;
        cin >> R1 >> R2;
        qs[i] = {R1*R1, R2*R2, i};
    }
    // sort queries tăng R12
    sort(qs.begin(), qs.end(),
         [&](auto &A, auto &B){ return A.R12 < B.R12; });

    // 5) khởi Fenwick với tất cả N điểm
    Fenwick bit(M);
    for(int i=0;i<N;i++){
        int pos = int(lower_bound(all_d2.begin(), all_d2.end(), pts[i].d2)
                      - all_d2.begin()) + 1;
        bit.update(pos, +1);
    }

    vector<int> ans(Q);
    int p = 0; // con trỏ trên order[]
    // duyệt từng query
    for(auto &q: qs){
        // loại bỏ tất cả điểm có d1 <= q.R12
        while(p < N && pts[order[p]].d1 <= q.R12){
            int i = order[p];
            // xóa điểm i khỏi BIT
            int pos = int(lower_bound(all_d2.begin(), all_d2.end(), pts[i].d2)
                          - all_d2.begin()) + 1;
            bit.update(pos, -1);
            p++;
        }
        // bây giờ BIT chỉ chứa những i sao cho d1 > R12
        // bad = # { d2 > R22 } = sum[ pos_R22+1 .. M ]
        int upto = getD2(q.R22);     // số phần tử d2 <= R22
        int bad = bit.query(upto+1, M);
        ans[q.idx] = N - bad;
    }

    // 6) in kết quả
    for(int i=0;i<Q;i++){
        cout << ans[i] << "\n";
    }
    return 0;
}
