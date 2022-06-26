#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

void output(int index, const vector<string>& value,
                   const vector<int>& left, const vector<int>& right) {
    stack<int> s;
    int p = index;
    while (p != -1 || !s.empty()) {
        if (p != -1) {
            cout << value[p] << " ";
            s.push(p);
            p = left[p];
        } else {
            p = s.top();
            s.pop();
            p = right[p];
        }
    }
    cout << endl;
}

int main() {
    vector<string> val(1);
    vector<int> left(1, 0);
    vector<int> right(1, 0);

    string str;
    int li, ri;
    while (cin >> str >> li >> ri) {
        val.push_back(str);
        left.push_back(li);
        right.push_back(ri);
    }

    output(1, val, left, right);
    return 0;
}