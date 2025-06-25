#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> boys_up, boys_down, girls_up, girls_down;

    for (int i = 0; i < n; ++i)
    {
        int h;
        cin >> h;
        if (h > 0)
            boys_up.push_back(h);
        else
            boys_down.push_back(abs(h));
    }

    for (int i = 0; i < n; ++i)
    {
        int h;
        cin >> h;
        if (h > 0)
            girls_up.push_back(h);
        else
            girls_down.push_back(abs(h));
    }

    sort(boys_up.begin(), boys_up.end());
    sort(boys_down.begin(), boys_down.end(), greater<int>());
    sort(girls_up.begin(), girls_up.end(), greater<int>());
    sort(girls_down.begin(), girls_down.end());

    int ans = 0;

    int i = 0, j = 0;
    while (i < boys_up.size() && j < girls_down.size())
    {
        if (boys_up[i] < girls_down[j])
        {
            ++ans;
            ++i;
            ++j;
        }
        else
        {
            ++j;
        }
    }

    i = 0, j = 0;
    while (i < boys_down.size() && j < girls_up.size())
    {
        if (boys_down[i] > girls_up[j])
        {
            ++ans;
            ++i;
            ++j;
        }
        else
        {
            ++j;
        }
    }

    cout << ans << endl;
    return 0;
}