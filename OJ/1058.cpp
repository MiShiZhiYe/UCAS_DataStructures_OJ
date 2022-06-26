#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    vector<string> lines;
    while (getline(cin, line)) {
        lines.push_back(line);
    }

    vector<vector<int> > tree;
    for (auto it = lines.begin(); it != lines.end(); ++it) {
        int val;
        int line1;
        int line2;
        stringstream ss(*it);
        ss >> val >> line1 >> line2;

        vector<int> node;
        node.push_back(val);
        node.push_back(line1);
        node.push_back(line2);

        tree.push_back(node);
    }

    for (auto it = tree.begin(); it != tree.end(); ++it) {
        auto val = (*it).at(0);
        auto line1 = (*it).at(1);
        auto line2 = (*it).at(2);

        if (line1 != -1 && val <= tree.at(line1).at(0)) {
            cout << 0 << endl;
            return 0;
        }

        if (line2 != -1 && tree.at(line2).at(0) <= val) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}