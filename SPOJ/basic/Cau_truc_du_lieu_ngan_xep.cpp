#include <bits/stdc++.h>
#define endl "\n"

using namespace std;

using ll = long long;

void faster()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int mod = 1e9 + 7;
const int MAXN = 1e5 + 5;

int main()
{
    faster();
    string s;
    stack<int> st;
    while (cin >> s)
    {
        if (s == "init")
        {
            while (!st.empty())
                st.pop();
        }
        else if (s == "push")
        {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (s == "pop")
        {
            if (!st.empty())
                st.pop();
        }
        else if (s == "top")
        {
            if (st.empty())
                cout << -1 << endl;
            else
                cout << st.top() << endl;
        }
        else if (s == "size")
        {
            cout << st.size() << endl;
        }
        else if (s == "empty")
        {
            if (st.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else
        {
            break;
        }
    }
    return 0;
}