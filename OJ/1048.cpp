// #include <iostream>
// #include <vector>
// #include <map>
// #include <string>
// #include <algorithm>
// #include <sstream>

// using namespace std;

// void makeGraph(map<int, vector<int>>& graph) {
//     string line;
//     getline(cin, line);
//     if (line[0] == '\n') return;
//     line += '\n';
//     stringstream ss(line);

//     int v, adj;
//     char c;
//     while (ss >> v >> c >> adj) {
//         auto iter = graph.begin();
//         auto it_end = graph.end();

//         if ((iter = graph.find(v)) != it_end) {
//             auto temp = iter->second;
//             temp.push_back(adj);
//             sort(temp.begin(), temp.end());
//             graph[v] = temp;
//         } else {
//             vector<int> temp;
//             temp.push_back(adj);
//             graph[v] = temp;
//         }

//         ss >> c;
//         if (c == '\n') break;
//     }
// }

// bool findPath(map<int, vector<int>>& graph, vector<int>& mark, int current, int target) {
//     if (current == target) return true;
//     mark[current] = 0;
//     for (auto& adj : graph[current]) {
//         if (mark[adj] && findPath(graph, mark, adj, target)) return true;
//     }
//     mark[current] = 1;
//     return false;
// }

// int main() {
//     map<int, vector<int>> graph;
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++) graph[i] = vector<int>();
//     makeGraph(graph);
//     vector<int> mark(graph.size(), 1);

//     int start, target;
//     cin >> start;
//     getchar();
//     cin >> target;
//     cout << (findPath(graph, mark, start, target) ? "yes" : "no") << endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int e = 0, ListNode *theNext = nullptr) :
        val(e), next(theNext) {}
};
using LinkList = ListNode*;

LinkList* InitGraph(int n) {
    LinkList* graph = new LinkList[n + 1];
    fill(graph, graph + n + 1, nullptr);
    return graph;
}

void GetArc(const string& str, int& head, int& tail) {
    auto iter = str.cbegin();
    string temp;
    while (*iter != '-') {
        temp += *iter;
        iter++;
    }
    head = stoi(temp);
    string().swap(temp);
    while (++iter != str.cend()) {
        temp += *iter;
    }
    tail = stoi(temp);
}

void InsertArc(int head, int tail, LinkList* graph) {
    graph[head] = new ListNode(tail, graph[head]);
}

bool DFS(int current, int target, LinkList* graph, bool* mark) {
    if (current == target) {
        return true;
    }
    for (ListNode *p = graph[current]; p != nullptr; p = p->next) {
        if (!mark[p->val]) {
            mark[p->val] = true;
            if (DFS(p->val, target, graph, mark)) {
                return true;
            }
        }
    }
    return false;
}

bool FindPath(int current, int target, LinkList* graph, int n) {
    bool* mark = new bool[n + 1];
    fill(mark, mark + n + 1, false);
    mark[current] = true;
    bool flag = DFS(current, target, graph, mark);
    delete[] mark;
    return flag;
}

int main() {
    int nv;
    int start, target;
    int head, tail;
    string line, tmp;
    LinkList *graph = nullptr;

    getline(cin, line);
    nv = stoi(line);
    graph = InitGraph(nv);

    getline(cin, line);
    stringstream ss(line);
    while (getline(ss, tmp, ',')) {
        GetArc(tmp, head, tail);
        InsertArc(head, tail, graph);
    }

    cin >> start;
    getchar();
    cin >> target;
    cout << (FindPath(start, target, graph, nv) ? "yes" : "no") << endl;

    return 0;
}