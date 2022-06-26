#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct node {
    char val;
    node* left;
    node* right;

    node(char theVal = 0, node* theLeft = nullptr, node* theRight = nullptr)
        : val(theVal), right(theRight), left(theLeft) {}
};

void makeTree(node*& t, const string& pre, const string& in, int low, int high) {
    static auto it = pre.cbegin();
    if (it != pre.cend()) {
        auto tar = find(in.cbegin() + low, in.cbegin() + high, *it);
        if (tar == in.cbegin() + high) {
            t = nullptr;
        } else {
            t = new node(*it, nullptr, nullptr);
            it++;
            makeTree(t->left, pre, in, low, tar - in.cbegin());
            makeTree(t->right, pre, in, tar - in.cbegin(), high);
        }
    }
}

void output(node* t) {
    if (t->left)
        output(t->left);
    if (t->right)
        output(t->right);
    if (t)
        cout << t->val;
}

int main() {
    string pre, in;
    node* tree;
    getline(cin, pre);
    getline(cin, in);
    makeTree(tree, pre, in, 0, pre.size());
    output(tree);
    return 0;
}
