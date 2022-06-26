#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    set<int> seq;
    int num;
    while (ss >> num)
        seq.insert(num);
    
    getline(cin, line);
    stringstream ss1(line);
    ss1 >> num;

    for (auto i = seq.rbegin(); i != seq.rend(); ++i) {
        if (*i >= num) {
            cout << *i << ' ';
        }
    }

    return 0;
}