#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

void judgeInfo(map<int, int>& graph, int& count, vector<string>& result) {
    string line;
    getline(cin, line);
    stringstream ss(line);

    char op;
    int v1, v2;
    ss >> op >> v1 >> v2;

    if (op == 'A') {
        if (graph[v1] == 0 || graph[v2] == 0) {
            result.push_back("不确定");
        } else if (graph[v1] != graph[v2] && graph[v1] + graph[v2] != 0) {
            result.push_back("不确定");
        } else if (graph[v1] == graph[v2]) {
            result.push_back("是同一个团伙所为");
        } else { // graph[v1] + graph[v2] == 0
            result.push_back("不是同一个团伙所为");
        }
    } else { // op == 'D'
        if (graph[v1] == 0 && graph[v2] == 0) {
            graph[v1] = count;
            graph[v2] = -count;
            count++;
        } else if (graph[v1] == 0) { // graph[v2] != 0
            graph[v1] = -graph[v2];
        } else if (graph[v2] == 0) { // graph[v1] != 0
            graph[v2] = -graph[v1];
        } else { // graph[v1] != 0 && graph[v2] != 0
            int n1 = graph[v1];
            int n2 = graph[v2];

            int n1_abs = abs(n1);
            int n2_abs = abs(n2);

            if (n1_abs < n2_abs) {
                for (auto& vertex : graph) {
                    vertex.second = (vertex.second == n2 ? -n1 : vertex.second);
                    vertex.second = (vertex.second == -n2 ? n1 : vertex.second);
                }
            } else { // n1_abs > n2_abs
                for (auto& vertex : graph) {
                    vertex.second = (vertex.second == n1 ? -n2 : vertex.second);
                    vertex.second = (vertex.second == -n1 ? n2 : vertex.second);
                }
            }
        }
    }
}

void judgeSystem() {
    string line;
    getline(cin, line);
    stringstream ss(line);

    // N: 案件的数量    M: 信息的数量
    int N, M;
    ss >> N >> M;

    map<int, int> graph;
    for (int i = 1; i <= N; i++)
        graph[i] = 0;

    int count = 1;
    vector<string> result;
    for (int i = 0; i < M; i++)
        judgeInfo(graph, count, result);

    for (auto& str : result)
        cout << str << endl;
}

int main() {
    int n;
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> n;

    for (int i = 0; i < n; i++)
        judgeSystem();

    return 0;
}