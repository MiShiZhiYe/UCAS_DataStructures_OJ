#include <iostream>
#include <string>
#include <vector>

using namespace std;

void line2string(string& str) {
    for (auto iter = str.begin(); iter != str.end(); iter++)
        if (*iter == ' ') str.erase(iter);
}

void reverseString(string& str) {
    string result;
    for (auto iter = str.rbegin(); iter != str.rend(); iter++)
        result += *iter;
    str.swap(result);
}

string mergeStr(vector<string>& str) {
    auto result = str[0];
    string oldStr = result;
    string newStr;
    while (oldStr != newStr) {
        oldStr = newStr;
        for (auto iter = result.begin(); iter != result.end(); iter++) {
            if ('0' <= *iter && *iter <= '9') {
                int pos = *iter;
                result.erase(iter);
                result.insert(iter - result.begin(), str[pos - '0']);
            }
        }
        newStr = result;
    }
    return result;
}

int main() {
    int lines;
    cin >> lines;
    getchar();

    vector<string> str;
    string line;
    for (int i = 0; i < lines; i++) {
        getline(cin, line);
        line2string(line);
        reverseString(line);
        str.push_back(line);
    }

    string result = mergeStr(str);
    cout << result << endl;

    return 0;
}