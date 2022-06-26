#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    char c;
    bool is_comment = false;
    while ((c = getchar()) != EOF)
    {
        if (is_comment == true)
        {
            if (c == '*')
            {
                c = getchar();
                if (c == '/')
                {
                    is_comment = false;
                }
            }
        }
        else
        {
            if (c == '/')
            {
                c = getchar();
                if (c == '*')
                {
                    is_comment = true;
                }
                else
                {
                    s += '/';
                    s += c;
                }
            }
            else
            {
                s += c;
            }
        }
    }
    cout << s << endl;
    return 0;
}