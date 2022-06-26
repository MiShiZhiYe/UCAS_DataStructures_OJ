#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    set<int> seq;
    int num;
    while (ss >> num) {
        seq.insert(num);
    }

    int a;
    int b;
    cin >> a;
    cin >> b;

    for (auto it = seq.begin(); it != seq.end(); ++it) {
        if (a < *it && *it < b) {
            cout << *it << ' ';
        }
    }

    return 0;
}