#include <iostream>

using namespace std;

int fun(int n)
{
    int ans = 1;

    while (n != 0)
    {
        ans *= n;
        n >>= 1;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << fun(n) << endl;
    return 0;
}