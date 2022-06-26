#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

enum OpType{ IV, IA, DV, DA };

void InitMatrix(vector<vector<int>>& matrix, int n) {
    vector<vector<int>>().swap(matrix);
    matrix.assign(n, vector<int>(n, 0));
}

OpType GetInst(const string& line, int& operand1, int& operand2) {
    stringstream ss(line);
    string s[3];
    ss >> s[0];
    if (s[0] == "IV" || s[0] == "DV") {
        ss >> s[1];
        operand1 = stoi(s[1]);
        return s[0] == "IV" ? OpType::IV : OpType::DV;
    } else {
        ss >> s[1] >> s[2];
        operand1 = stoi(s[1]);
        operand2 = stoi(s[2]);
        return s[0] == "IA" ? OpType::IA : OpType::DA;
    }
}

void InsertArc(vector<vector<int>>& matrix, int v, int w) {
    matrix[v][w] = matrix[w][v] = 1;
}

void DeleteArc(vector<vector<int>>& matrix, int v, int w) {
    matrix[v][w] = matrix[w][v] = 0;
}

void InsertVex(vector<vector<int>>& matrix, int v) {
    for (auto& vertex : matrix)
        vertex.insert(vertex.begin() + v, 0);
    matrix.insert(matrix.begin() + v, vector<int>(matrix[0].size(), 0));
}

void DeleteVex(vector<vector<int>>& matrix, int v) {
    for (auto& vertex: matrix)
        vertex.erase(vertex.begin() + v);
    matrix.erase(matrix.begin() + v);
}

void output(const vector<vector<int>>& matrix) {
    for (const auto& vertex : matrix) {
        for (auto iter = vertex.cbegin(); iter != vertex.cend(); ++iter) {
            cout << *iter;
            if (iter != vertex.cend() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> m;
    int n;
    cin >> n;
    InitMatrix(m, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }
    getchar();
    string line;
    int n1, n2;
    OpType op;
    while (getline(cin, line)) {
        op = GetInst(line, n1, n2);
        switch (op)
        {
        case IV:
            InsertVex(m, n1);
            break;
        case IA:
            InsertArc(m, n1, n2);
            break;
        case DV:
            DeleteVex(m, n1);
            break;
        case DA:
            DeleteArc(m, n1, n2);
        }
    }
    output(m);

    return 0;
}