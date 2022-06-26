#include <iostream>
#include <string>

using namespace std;

int g(int, int);

int g(int m, int n)
{
	return m == 0 ? 0 : g(m - 1, 2 * n) + n;
}

int main()
{
	int m , n;
	char c;
	cin >> m >> c >> n;

	cout << g(m, n) << endl;

	return 0;
}