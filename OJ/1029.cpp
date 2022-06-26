#include <iostream>
using namespace std;

void strCmp(string s, string& ss, int& index) {
    int max = 0;
    index = -1;
    for (int i = 0; i < s.size() - 1; i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                int length = 1;
                for (int k = 1; s[i + k] == s[j + k]; k++) {
                    length++;
                }
                if (max < length) {
                    index = i;
                    max = length;
                }
                j = j + length;
            }
        }
    }
    for (int i = index; i < index + max; i++) {
        ss += s[i];
    }
}

void print(string& s, int& index) {
    if (index == -1) {
        cout << -1 << endl;
    } else {
        cout << s << ' ' << index << endl;
    }
}

int main() {
    string str;
    cin >> str;

    string subStr;
    int index;

    strCmp(str, subStr, index);
    print(subStr, index);

    return 0;
}