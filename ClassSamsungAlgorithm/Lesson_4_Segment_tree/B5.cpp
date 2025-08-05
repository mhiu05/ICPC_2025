#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll INF = 1e18;

struct Node {
    ll min_val, max_val, min_gap;
    int count;
    Node *left, *right;

    Node() : min_val(INF), max_val(-INF), min_gap(INF), count(0), left(nullptr), right(nullptr) {}
};

void update(Node* node, ll l, ll r, ll pos) {
    if (l == r) {
        node->count++;
        if (node->count == 1) {
            node->min_val = pos;
            node->max_val = pos;
            node->min_gap = INF;
        } else {
            node->min_gap = 0;
        }
        return;
    }

    ll mid = (l + r) / 2;
    if (pos <= mid) {
        if (!node->left) {
            node->left = new Node();
        }
        update(node->left, l, mid, pos);
    } else {
        if (!node->right) {
            node->right = new Node();
        }
        update(node->right, mid+1, r, pos);
    }

    ll min_val_left = INF, max_val_left = -INF, min_gap_left = INF;
    if (node->left) {
        min_val_left = node->left->min_val;
        max_val_left = node->left->max_val;
        min_gap_left = node->left->min_gap;
    }

    ll min_val_right = INF, max_val_right = -INF, min_gap_right = INF;
    if (node->right) {
        min_val_right = node->right->min_val;
        max_val_right = node->right->max_val;
        min_gap_right = node->right->min_gap;
    }

    node->min_val = min(min_val_left, min_val_right);
    node->max_val = max(max_val_left, max_val_right);
    node->min_gap = min(min_gap_left, min_gap_right);

    if (max_val_left != -INF && min_val_right != INF) {
        node->min_gap = min(node->min_gap, min_val_right - max_val_left);
    }
}

Node query(Node* node, ll l, ll r, ll ql, ll qr) {
    if (!node || qr < l || r < ql) {
        return Node();
    }
    if (ql <= l && r <= qr) {
        return *node;
    }

    ll mid = (l + r) / 2;
    Node left_node = (node->left) ? query(node->left, l, mid, ql, qr) : Node();
    Node right_node = (node->right) ? query(node->right, mid+1, r, ql, qr) : Node();

    Node res;
    if (left_node.min_val == INF && right_node.min_val == INF) {
        return Node();
    } else if (left_node.min_val == INF) {
        res = right_node;
    } else if (right_node.min_val == INF) {
        res = left_node;
    } else {
        res.min_val = min(left_node.min_val, right_node.min_val);
        res.max_val = max(left_node.max_val, right_node.max_val);
        res.min_gap = min(left_node.min_gap, right_node.min_gap);
        if (left_node.max_val != -INF && right_node.min_val != INF) {
            res.min_gap = min(res.min_gap, right_node.min_val - left_node.max_val);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    const ll MAX_COORD = 1000000000;
    Node* root = new Node();

    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        update(root, 0, MAX_COORD, a);
    }

    for (int i = 0; i < M; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            ll P;
            cin >> P;
            update(root, 0, MAX_COORD, P);
        } else {
            ll L, R;
            cin >> L >> R;
            Node res = query(root, 0, MAX_COORD, L, R);
            if (res.min_gap == INF) {
                cout << -1 << '\n';
            } else {
                cout << res.min_gap << '\n';
            }
        }
    }

    return 0;
}