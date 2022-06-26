#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<int> seq;
    int number;
    while (cin >> number)
        seq.insert(number);
    for (auto& i : seq)
        cout << i << ' ';
    return 0;
}