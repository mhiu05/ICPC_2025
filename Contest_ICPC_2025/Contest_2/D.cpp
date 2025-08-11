#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define endl '\n'

const int MOD = 1e9 + 7;

int n, m, ans;
int pfx[2000005], sfx[2000005], bst[2000005], lz[2000005];

void build(int o, int l, int r)
{
    lz[o] = -1;
    pfx[o] = sfx[o] = bst[o] = r - l + 1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
}

void apply(int o, int l, int r, int v)
{
    lz[o] = v;
    if (v)
        pfx[o] = sfx[o] = bst[o] = r - l + 1;
    else
        pfx[o] = sfx[o] = bst[o] = 0;
}

void push(int o, int l, int r)
{
    if (lz[o] != -1)
    {
        int m = (l + r) >> 1;
        apply(o << 1, l, m, lz[o]);
        apply(o << 1 | 1, m + 1, r, lz[o]);
        lz[o] = -1;
    }
}

void pull(int o, int l, int r)
{
    int m = (l + r) >> 1, lc = o << 1, rc = o << 1 | 1;
    pfx[o] = pfx[lc] == m - l + 1 ? pfx[lc] + pfx[rc] : pfx[lc];
    sfx[o] = sfx[rc] == r - m ? sfx[rc] + sfx[lc] : sfx[rc];
    bst[o] = max({bst[lc], bst[rc], sfx[lc] + pfx[rc]});
}

void update(int o, int l, int r, int ql, int qr, int v)
{
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr)
    {
        apply(o, l, r, v);
        return;
    }
    push(o, l, r);
    int m = (l + r) >> 1;
    update(o << 1, l, m, ql, qr, v);
    update(o << 1 | 1, m + 1, r, ql, qr, v);
    pull(o, l, r);
}

int query(int o, int l, int r, int k)
{
    if (bst[o] < k) return -1;
    if (l == r) return l;
    push(o, l, r);
    int m = (l + r) >> 1;
    if (bst[o << 1] >= k) return query(o << 1, l, m, k);
    if (sfx[o << 1] + pfx[o << 1 | 1] >= k) return m - sfx[o << 1] + 1;
    return query(o << 1 | 1, m + 1, r, k);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    fill(lz, lz + 4 * n, -1);
    build(1, 1, n);
    while (m--)
    {
        char c;
        cin >> c;
        if (c == 'A')
        {
            int k;
            cin >> k;
            int i = query(1, 1, n, k);
            if (i < 0) ++ans;
            else update(1, 1, n, i, i + k - 1, 0);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            update(1, 1, n, l, r, 1);
        }
    }
    cout << ans;
    return 0;
}
