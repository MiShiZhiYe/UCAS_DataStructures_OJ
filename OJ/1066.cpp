#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> flag;
    int num;
    while (cin >> num) {
        flag.insert(num);
    }

    for (auto i : flag) {
        cout << i << ' ';
    }

    return 0;
}