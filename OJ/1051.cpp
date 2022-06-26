#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void makeGraph(map<int, vector<int>>& graph) {
    int num_of_vertices;
    cin >> num_of_vertices;
    for (int i = 1; i <= num_of_vertices; i++)
        graph[i] = vector<int>();
    getchar();

    int v, adj;
    char c;
    while (cin >> v >> c >> adj) {
        c = getchar();
        graph[v].push_back(adj);
        sort(graph[v].begin(), graph[v].end());
    }
}

void getPath(map<int, vector<int>>& graph, int current, int& length, vector<int>& mark, int len) {
    length = len < length ? length : len;
    mark[current] = 0;
    auto vertex = graph[current];
    for (auto& adj : vertex) {
        if (mark[adj])
            getPath(graph, adj, length, mark, len + 1);
    }
    mark[current] = 1;
}

int main() {
    map<int, vector<int>> graph;
    makeGraph(graph);

    vector<int> length(graph.size() + 1, 0);
    vector<int> mark(graph.size() + 1, 1);
    for (int i = 1; i <= graph.size(); i++)
        getPath(graph, i, length[i], mark, 0);

    for (int i = 1; i < length.size() - 1; i++) cout << length[i] << ",";
    cout << length[length.size() - 1] << endl;

    return 0;
}