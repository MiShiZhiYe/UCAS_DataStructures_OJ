#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool IsComplete(int idx, const vector<int>& left, const vector<int>& right) {
    queue<int> q;
    q.push(idx);

    while (!q.empty()) {
        idx = q.front();
        if (left[idx] != -1 && right[idx] != -1) {
            q.pop();
            q.push(left[idx]);
            q.push(right[idx]);
        }

        if (left[idx] == -1 && right[idx] != -1)
            return false;

        if (right[idx] == -1) {
            if (left[idx] != -1)
                q.push(left[idx]);

            q.pop();

            while (!q.empty()) {
                idx = q.front();

                if (left[idx] == -1 && right[idx] == -1)
                    q.pop();
                else
                    return false;
            }

            return true;
        }
    }
    
    return true;
}

int main() {
    string str;
    vector<int> left(1);
    vector<int> right(1);

    int li, ri;
    while (cin >> str >> li >> ri) {
        left.push_back(li);
        right.push_back(ri);
    }

    cout << (IsComplete(1, left, right) ? "Yes" : "No") << endl;

    return 0;
}
