#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <climits>

using namespace std;

void makeGraph(map<int, map<int, int>>& graph, int& source) {
    int num_of_vertices;
    cin >> num_of_vertices >> source;

    for (int i = 1; i <= num_of_vertices; i++)
        graph[i] = map<int, int>();

    getchar();

    int v, adj, wht;
    char c;
    while (cin >> v >> c >> adj >> wht)
        graph[v].insert({adj, wht});
}

map<int, int> Dijkstra(map<int, map<int, int>>& graph, int source) {
    map<int, int> result;
    set<int> out;

    // initialize
    result[source] = 0;
    for (auto& vertex : graph) {
        if (vertex.first != source) {
            out.insert(vertex.first);
        }
    }
    
    while (!out.empty()) {
        int min_vertex = source;
        int min = INT_MAX;

        for (auto& vertex : result) {
            // result 中的某一个 vertex
            for (auto& adj : graph[vertex.first]) {
                if (out.find(adj.first) == out.end())
                    continue;

                // result 中的某一个 vertex 的某一个 adjacent vertex
                // 带权路径长度 = source 到 vertex 的带权路径长度 + vertex 到 adjacent vertex 的带权路径长度
                int length = vertex.second + adj.second;

                if (length < min) {
                    min = length;
                    min_vertex = adj.first;
                }
            }
        }

        result.insert({min_vertex, min});
        out.erase(min_vertex);
    }

    return result;
}

void output(map<int, int>& Dij) {
    vector<int> result;
    for (auto& i : Dij) {
        if (i.second != 0) {
            result.push_back(i.second);
        }
    }
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ",";
    }
    cout << result[result.size() - 1] << endl;
}

int main() {
    int source;
    map<int, map<int, int>> graph;
    makeGraph(graph, source);
    auto dij = Dijkstra(graph, source);
    output(dij);
    return 0;
}