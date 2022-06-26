#include <iostream>
#include <climits>

using namespace std;

long long fact(long long);

long long fact(long long n)
{
    long long ret = 1;
    for (int i = 1; i <= n; ++i)
    {
        ret *= i;
    }
    return ret;
}

int main()
{
    int n, arrsize;
    cin >> n >> arrsize;

    long long* a = new long long[arrsize];

    if (n > arrsize)
    {
        cout << "-1" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
    {
        a[i] = fact(i) << i;

        if (a[i] > INT_MAX)
        {
            cout << "-1" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << endl;

    return 0;
}