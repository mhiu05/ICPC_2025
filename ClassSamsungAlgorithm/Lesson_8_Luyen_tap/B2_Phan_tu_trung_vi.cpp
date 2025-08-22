#include <iostream>
#include <set>
#include <functional>
using namespace std;

multiset<int, greater<int>> left_half; // nửa đầu, lớn nhất ở đầu
multiset<int> right_half;             // nửa sau, nhỏ nhất ở đầu

void balance() {
    while (left_half.size() > right_half.size() + 1) {
        auto it = left_half.begin();
        right_half.insert(*it);
        left_half.erase(it);
    }
    while (right_half.size() > left_half.size()) {
        auto it = right_half.begin();
        left_half.insert(*it);
        right_half.erase(it);
    }
}

void add(int x) {
    if (left_half.empty() || x <= *left_half.begin()) {
        left_half.insert(x);
    } else {
        right_half.insert(x);
    }
    balance();
}

void del(int x) {
    auto it = left_half.find(x);
    if (it != left_half.end()) {
        left_half.erase(it);
    } else {
        right_half.erase(right_half.find(x));
    }
    balance();
}

void print() {
    if (left_half.size() == 0) {
        return; // không có phần tử
    }
    if (left_half.size() == right_half.size()) {
        cout << (*left_half.begin() + *right_half.begin()) / 2 << endl;
    } else {
        cout << *left_half.begin() << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;
    while (Q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "add") {
            int x;
            cin >> x;
            add(x);
        } else if (cmd == "del") {
            int x;
            cin >> x;
            del(x);
        } else if (cmd == "print") {
            print();
        }
    }
    return 0;
}