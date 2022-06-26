#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    vector<int> iv;
    int temp;
    while (cin >> temp)
        iv.push_back(temp);
    sort(iv.begin(), iv.end());
    for (auto& i : iv)
        if (i == -1) continue;
        else cout << i << " ";
    return 0;
}