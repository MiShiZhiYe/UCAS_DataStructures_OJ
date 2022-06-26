#include <iostream>
#include <set>

using namespace std;

int main() {
    multiset<int> seq;
    int num;
    while (cin >> num) {
        seq.insert(num);
    }

    for (auto i : seq) {
        cout << i << ' ';
    }

    return 0;
}