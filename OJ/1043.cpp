#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

void InputVector(vector<int>& vec, const string& input) {
    int temp;
    stringstream ss(input);
    while (ss >> temp)
        vec.push_back(temp);
}

void Insert(const int p,
            vector<int>& left, vector<int>& right,
            const vector<int>& left2, const vector<int>& right2) {
    int tmp = left[p];
    while (left.size() < left2[0]) {
        left.push_back(0);
        right.push_back(0);
    }
    left[p] = left2[0];
    auto lit = left2.cbegin() + 1;
    auto rit = right2.cbegin() + 1;
    while (lit != left2.cend() && rit != right2.cend()) {
        left.push_back(*lit);
        right.push_back(*rit);
        lit++;
        rit++;
    }
    right[left2[0]] = tmp;
}

void output(const vector<int>& left, const vector<int>& right) {
    stack<int> s;
    int p = 1;
    while (p != 0 || !s.empty()) {
        if (p != 0) {
            s.push(p);
            p = left[p];
        } else {
            p = s.top();
            cout << p << " ";
            s.pop();
            p = right[p];
        }
    }
    cout << endl;
}

int main() {
    int pos;
    vector<int> left, right, left2, right2;
    string line;

    getline(cin, line);
    InputVector(left, line);
    getline(cin, line);
    InputVector(right, line);

    getline(cin, line);
    pos = stoi(line);

    getline(cin, line);
    InputVector(left2, line);
    getline(cin, line);
    InputVector(right2, line);

    Insert(pos, left, right, left2, right2);

    output(left, right);

    return 0;
}