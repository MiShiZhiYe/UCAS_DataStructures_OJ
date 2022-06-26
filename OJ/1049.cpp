#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void getLine2Vector(vector<int>& iv) {
    string line;
    getline(cin, line);
    stringstream ss(line);

    int int_num;
    while (ss >> int_num)
        iv.push_back(int_num);
}

void makeGraph(map<int, vector<int>>& graph) {
    vector<int> num_of_vertices;
    vector<int> s;
    vector<int> fst;
    vector<int> lst;

    getLine2Vector(num_of_vertices);
    getLine2Vector(s);
    getLine2Vector(fst);
    getLine2Vector(lst);

    for (int i = 1; i <= num_of_vertices[0]; i++)
        graph[i] = vector<int>();

    for (int i = 1; i < fst.size(); i++)
        for (int j = fst[i]; j < lst[i]; j++)
            graph[i].push_back(s[j]);
}

bool findCycle(map<int, vector<int>>& graph, int current, int target, vector<int>& mark) {
    auto adj = graph[current];
    if (find(adj.begin(), adj.end(), target) != adj.end()) return true;
    else {
        mark[current] = 0;
        for (auto& i : adj) {
            if (mark[i] && findCycle(graph, i, target, mark)) return true;
        }
        mark[current] = 1;
    }
    return false;
}

bool judgeCycle(map<int, vector<int>>& graph) {
    vector<int> mark(graph.size() + 1, 1);
    for (int i = 1; i <= graph.size(); i++)
        if (findCycle(graph, i, i, mark)) return true;
    return false;
}

int main() {
    map<int, vector<int>> graph;
    makeGraph(graph);
    cout << (judgeCycle(graph) ? "yes" : "no") << endl;
    return 0;
}