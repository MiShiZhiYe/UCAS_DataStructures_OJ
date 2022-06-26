#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

void getInput(map<int, int>& m) {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int k, beg_pos;
        ss >> k;
        while (ss >> beg_pos) {
            m[beg_pos] = pow(2, k);
        }
    }
}

void mergeMemory(map<int, int>& m) {
    int oldSize = m.size();
    int newSize = -1;
    while (oldSize != newSize) {
        oldSize = newSize;
        auto iter = m.begin();
        for (; iter != m.end(); iter++) {
            auto it = iter;
            it++;
            if (it == m.end()) break;
            int k = log2l(iter->second);
            int n = powl(2, k + 1);
            if (iter->first % n == 0 && iter->first + pow(2, k) == it->first) {
                iter->second += it->second;
                m.erase(it);
            }
        }
        newSize = m.size();
    }
}

void output(const map<int, int>& m) {
    map<int, vector<int>> result;
    for (auto& piece : m) {
        int k = log2l(piece.second);
        result[k].push_back(piece.first);
    }
    for (auto& k : result) {
        cout << k.first << " ";
        for (int i = 0; i < k.second.size() - 1; i++) {
            cout << k.second[i] << " ";
        }
        cout << k.second[k.second.size() - 1] << endl;
    }
}

int main() {
    map<int, int> m;
    getInput(m);
    mergeMemory(m);
    output(m);
    return 0;
}