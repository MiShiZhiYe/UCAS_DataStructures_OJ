#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    char c;

    cin >> s >> c;

    int old_length = s.size();
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == c)
        {
            s.erase(it);
        }
    }

    int new_length = s.size();
    do
    {
        old_length = s.size();
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (*it == '(' && *(it + 1) == ',')
            {
                s.erase(it + 1);
            }
            else if (*it == ',' && *(it + 1) == ')')
            {
                s.erase(it);
            }
            else if (*it == '(' && *(it + 1) == ')')
            {
                s.erase(it + 1);
                s.erase(it);
            }
            else if (*it == ',' && *(it + 1) == ',')
            {
                s.erase(it);
            }
            if (s.empty())
            {
                break;
            }
        }
        new_length = s.size();
    }while (old_length != new_length);

    if (s.size() <= 2)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << s << endl;
    }

    return 0;
}