#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

void getInput(map<int, int>& m) {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        int flag;
        int beg_pos, mSize;
        if (ss >> flag >> beg_pos >> mSize) {
            if (mSize != 0)
                m.insert({ beg_pos, mSize });
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
            if (it != m.end() && iter->first + iter->second == it->first) {
                iter->second += it->second;
                m.erase(it);
            }
        }
        newSize = m.size();
    }
}

void output(map<int, int>& m) {
    auto iter = m.begin();
    auto it_end = m.end();
    for (; iter != it_end; iter++) {
        cout << 0 << " " << iter->first << " " << iter->second << endl;
    }
}

int main() {
    map<int, int> m;
    getInput(m);
    mergeMemory(m);
    output(m);
    return 0;
}