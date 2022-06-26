#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a;
    int num;
    while (cin >> num) {
        a.push_back(num);
    }
    vector<int> c(a.size(), 0);
    for (int i = 1; i < c.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] <= a[i])
                c[i]++;
            else
                c[j]++;
        } 
    }

    for (auto i : c) {
        cout << i << ' ';
    }

    return 0;
}