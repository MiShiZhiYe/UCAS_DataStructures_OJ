#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    char c;
    bool flag = false;

    while ((c = getchar()) != '@')
    {
        if (!flag)
        {
            if (c != '&')
            {
                s.push(c);
            }
            else
            {
                flag = true;
            }
        }
        else
        {
            if (s.empty())
            {
                cout << 0 << endl;
                break;
            }
            else if (c != s.top())
            {
                cout << 0 << endl;
                break;
            }
            else
            {
                s.pop();
            }
        }
    }

    if (c == '@' && s.empty())
    {
        cout << 1 << endl;
    }

    return 0;
}