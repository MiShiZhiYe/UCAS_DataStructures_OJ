#include <iostream>
#include <string>
#include <vector>

using namespace std;

void outputNode(const string& str, int pos) {
    for (int i = 0; i < pos; i++)
        cout << "-";
    cout << str << endl;
}

void output(int index, int depth,
            const vector<int>& child,
            const vector<int>& sibling,
            const vector<string>& value) {
    outputNode(value[index], depth);
    int i = child[index];
    while (i != -1) {
        output(i, depth + 1, child, sibling, value);
        i = sibling[i];
    }
} 

int main() {
    vector<string> val(1);
    vector<int> child(1);
    vector<int> sibling(1);

    string str;
    int ci, si;
    while (cin >> str >> ci >> si) {
        val.push_back(str);
        child.push_back(ci);
        sibling.push_back(si);
    }

    output(1, 0, child, sibling, val);

    return 0;
}
