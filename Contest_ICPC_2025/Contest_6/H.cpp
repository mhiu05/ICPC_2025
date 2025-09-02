#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool can_achieve_distance(const vector<pii>& points, int max_dist) {
    set<int> y_values;
    int i = 0;
    
    for (const auto& point : points) {
        int x = point.first;
        int y = point.second;
        
        while (i < points.size() && points[i].first + max_dist <= x) {
            y_values.insert(points[i].second);
            i++;
        }
        
        auto it_upper = y_values.lower_bound(y + max_dist);
        if (it_upper != y_values.end()) {
            return true;
        }
        
        auto it_lower = y_values.upper_bound(y - max_dist);
        if (it_lower != y_values.begin()) {
            return true;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pii> points(n);
    
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    sort(points.begin(), points.end());
    
    int left = 0;
    int right = 1e9 + 1;
    
    while (right - left > 1) {
        int mid = left + (right - left) / 2;
        
        if (can_achieve_distance(points, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    
    cout << left << endl;
    
    return 0;
}