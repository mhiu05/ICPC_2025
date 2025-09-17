#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;

struct Node {
    int left, right, max;
    int lazy; // 0: empty, 1: occupied, -1: no lazy
} tree[4 * MAXN];

void build(int id, int l, int r) {
    if (l == r) {
        tree[id].left = tree[id].right = tree[id].max = 1;
        tree[id].lazy = -1;
        return;
    }
    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);
    tree[id].left = tree[id].right = tree[id].max = (r - l + 1);
    tree[id].lazy = -1;
}

void pushDown(int id, int l, int r) {
    if (tree[id].lazy == -1) return;
    int mid = (l + r) / 2;
    int leftLen = mid - l + 1;
    int rightLen = r - mid;
    if (tree[id].lazy == 0) {
        tree[2 * id].left = tree[2 * id].right = tree[2 * id].max = leftLen;
        tree[2 * id + 1].left = tree[2 * id + 1].right = tree[2 * id + 1].max = rightLen;
    } else {
        tree[2 * id].left = tree[2 * id].right = tree[2 * id].max = 0;
        tree[2 * id + 1].left = tree[2 * id + 1].right = tree[2 * id + 1].max = 0;
    }
    tree[2 * id].lazy = tree[2 * id + 1].lazy = tree[id].lazy;
    tree[id].lazy = -1;
}

void combine(int id, int l, int r) {
    int mid = (l + r) / 2;
    int leftLen = mid - l + 1;
    int rightLen = r - mid;
    tree[id].left = tree[2 * id].left;
    if (tree[2 * id].left == leftLen) {
        tree[id].left += tree[2 * id + 1].left;
    }
    tree[id].right = tree[2 * id + 1].right;
    if (tree[2 * id + 1].right == rightLen) {
        tree[id].right += tree[2 * id].right;
    }
    tree[id].max = max({tree[2 * id].max, tree[2 * id + 1].max, tree[2 * id].right + tree[2 * id + 1].left});
}

void update(int id, int l, int r, int u, int v, int val) {
    if (v < l || r < u) return;
    if (u <= l && r <= v) {
        if (val == 0) {
            tree[id].left = tree[id].right = tree[id].max = (r - l + 1);
        } else {
            tree[id].left = tree[id].right = tree[id].max = 0;
        }
        tree[id].lazy = val;
        return;
    }
    pushDown(id, l, r);
    int mid = (l + r) / 2;
    update(2 * id, l, mid, u, v, val);
    update(2 * id + 1, mid + 1, r, u, v, val);
    combine(id, l, r);
}

int query(int id, int l, int r, int k) {
    if (tree[id].max < k) return -1;
    if (l == r) return l;
    pushDown(id, l, r);
    int mid = (l + r) / 2;
    if (tree[2 * id].max >= k) {
        return query(2 * id, l, mid, k);
    } else if (tree[2 * id].right + tree[2 * id + 1].left >= k) {
        return mid - tree[2 * id].right + 1;
    } else {
        return query(2 * id + 1, mid + 1, r, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    build(1, 1, N);
    int ans = 0;
    while (M--) {
        char type;
        cin >> type;
        if (type == 'A') {
            int K;
            cin >> K;
            int pos = query(1, 1, N, K);
            if (pos == -1) {
                ans++;
            } else {
                update(1, 1, N, pos, pos + K - 1, 1);
            }
        } else {
            int a, b;
            cin >> a >> b;
            update(1, 1, N, a, b, 0);
        }
    }
    cout << ans << "\n";
    return 0;
}