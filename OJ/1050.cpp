#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void getInput(map<int, vector<int>>& graph, int& k, int& sp, int& ep) {
    int num_of_vertices;
    char comma;
    cin >> num_of_vertices >> comma >> k;
    for (int i = 1; i <= num_of_vertices; i++)
        graph[i] = vector<int>();
    getchar();

    cin >> sp >> comma >> ep;
    getchar();
    
    int v, adj;
    char c;
    while (cin >> v >> c >> adj) {
        c = getchar();
        graph[v].push_back(adj);
        sort(graph[v].begin(), graph[v].end());
    }
}

bool findPath(map<int, vector<int>>& graph,
              int k,
              int current,
              int target,
              vector<int>& mark,
              int len = 0)
{
    auto adj = graph[current];
    if (find(adj.begin(), adj.end(), target) != adj.end() && k == len + 1) return true;
    else {
        mark[current] = 0;
        for (auto& i : adj)
            if (mark[i] && findPath(graph, k, i, target, mark, len + 1)) return true;
        mark[current] = 1;
    }
    return false;
}

int main() {
    int k, sp, ep;
    map<int, vector<int>> graph;
    getInput(graph, k, sp, ep);
    vector<int> mark(graph.size() + 1, 1);
    cout << (findPath(graph, k, sp, ep, mark) ? "yes" : "no") << endl;
    return 0;
}