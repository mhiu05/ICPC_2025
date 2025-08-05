#include <bits/stdc++.h>
#define ll long long
#define int long long
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FOD(i, a, b) for (int i = (a); i >= (b); i--)
#define all(x) x.begin(), x.end()
#define pb push_back
#define sz(x) ((int)x.size())
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define fi first
#define se second
#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;

const int MAXN = 1e6 + 5;

struct Node {
    int open, close, matched;

    Node() : open(0), close(0), matched(0) {}
    Node(char c) {
        if (c == '(') {
            open = 1;
            close = 0;
        } else {
            open = 0;
            close = 1;
        }
        matched = 0;
    }
};

Node st[4 * MAXN];
string s;

Node merge(Node left, Node right) {
    Node res;
    int new_matches = min(left.open, right.close);
    res.matched = left.matched + right.matched + new_matches;
    res.open = left.open + right.open - new_matches;
    res.close = left.close + right.close - new_matches;
    return res;
}

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = Node(s[l]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = merge(st[id * 2], st[id * 2 + 1]);
}

Node query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        return Node();
    }
    if (u <= l && r <= v) {
        return st[id];
    }
    int mid = (l + r) / 2;
    Node left = query(id * 2, l, mid, u, v);
    Node right = query(id * 2 + 1, mid + 1, r, u, v);
    return merge(left, right);
}

signed main() {
    faster;
    cin >> s;
    int n = s.size();
    s = " " + s;
    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        Node res = query(1, 1, n, l, r);
        cout << res.matched * 2 << '\n';
    }

    return 0;
}