#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    map<int, vector<int>> graph;
    string line;
    getline(cin, line);

    int v, adj;
    char c;
    while (cin >> v >> c >> adj) {
        c = getchar();
        auto iter = graph.begin();
        auto it_end = graph.end();

        if ((iter = graph.find(v)) != it_end) {
            auto temp = iter->second;
            temp.push_back(adj);
            sort(temp.begin(), temp.end(), greater<int>());
            graph[v] = temp;
        } else {
            vector<int> temp;
            temp.push_back(adj);
            graph[v] = temp;
        }
        if (graph.find(adj) == it_end) {
            graph[adj] = vector<int>();
        }

        if (c == EOF) break;
    }

    auto iter = graph.begin();
    auto it_end = graph.end();
    for (; iter != it_end; ++iter) {
        cout << iter->first;

        if (iter->second.empty()) {
            cout << endl;
            continue;
        }

        cout << " ";

        for (int i = 0; i < iter->second.size() - 1; i++) {
            cout << iter->second[i] << ",";
        }
        cout << iter->second[iter->second.size() - 1] << endl;
    }

    return 0;
}