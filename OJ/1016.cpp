#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    stack<char> s;
    vector<int> ans;

    string str;
    bool push = false;
    while (cin >> str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                s.push('(');
            }
            else if (str[i] == ')')
            {
                if (s.empty())
                {
                    ans.push_back(0);
                    push = true;
                    stack<char>().swap(s);
                    break;
                }
                else
                {
                    s.pop();
                }
            }
        }

        if (!push)
        {
            if (s.empty())
            {
                ans.push_back(1);
            }
            else
            {
                ans.push_back(0);
                stack<char>().swap(s);
            }
        }
        else
        {
            push = false;
        }
    }


    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}