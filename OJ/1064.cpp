#include <iostream>
#include <set>

using namespace std;

int main()
{
    multiset<int> seq;
    int n;
    int number;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> number;
        seq.insert(number);
    }
    for (auto& i : seq)
        cout << i << ' ';
    return 0;
}