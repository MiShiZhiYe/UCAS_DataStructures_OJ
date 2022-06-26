#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node {
    char val;
    node* left;
    node* right;

    node(char theVal = 0, node* theLeft = nullptr, node* theRight = nullptr)
        : val(theVal), left(theLeft), right(theLeft) {}
};

void input(node*& t) {
    char c;
    if ((c = getchar()) == '^')
        t = nullptr;
    else {
        t = new node(c);
        input(t->left);
        input(t->right);
    }
}

bool FindPath(node* p, vector<char>& path, char elem) {
    if (p == nullptr) return false;
    path.push_back(p->val);
    if (p->val == elem) return true;
    if (FindPath(p->left, path, elem)) return true;
    if (FindPath(p->right, path, elem)) return true;
    path.pop_back();
    return false;
}

char FindCloseAncestor(const vector<char>& path1, const vector<char>& path2) {
    auto iter1 = path1.begin();
    auto it_end1 = path1.end();
    auto iter2 = path2.begin();
    auto it_end2 = path2.end();

    char result;

    while (iter1 != it_end1 && iter2 != it_end2) {
        if (*iter1 == *iter2) result = *iter2;
        else break;
        iter1++;
        iter2++;
    }

    return result;
}

int main() {
    node* tree;
    input(tree);
    char a, b;
    cin >> a >> b;

    vector<char> path1, path2;
    FindPath(tree, path1, a);
    FindPath(tree, path2, b);
    char ancestor = FindCloseAncestor(path1, path2);
    if (ancestor == tree->val) cout << ancestor << endl;
    else if (ancestor == a || ancestor == b)
        cout << (path1.size() < path2.size() ? path1.at(path1.size() - 2) : path2.at(path2.size() - 2)) << endl;
    else
        cout << ancestor << endl;

    return 0;
}
