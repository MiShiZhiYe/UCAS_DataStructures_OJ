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

    getline(cin, line);
    stringstream ss1(line);

    while (ss1 >> num) {
        if (seq.find(num) != seq.end()) {
            cout << 1 << ' ';
        } else {
            cout << 0 << ' ';
        }
    }

    return 0;
}