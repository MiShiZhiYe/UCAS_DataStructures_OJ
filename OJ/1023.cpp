#include <iostream>
#include <stack>

using namespace std;

int main()
{
    char c;
    stack<char> s;
    while ((c = getchar()) != EOF && c !='\n')
        s.push(c);

    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }

    return 0;
}