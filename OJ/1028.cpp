#include <iostream>
#include <string>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    string a, b;
  	getchar();
    for (int i = 0; i < m; i++)
        a += getchar();
    getchar();
    for (int i = 0; i < n; i++)
        b += getchar();
    int p = a.find(b);
    if (0 <= p && p < m)
        cout << p << endl;
    else
        cout << -1 << endl;
    return 0;
}