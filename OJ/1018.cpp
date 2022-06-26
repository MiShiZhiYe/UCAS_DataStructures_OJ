#include <iostream>
#include <stack>
#include <string>

using namespace std;

class RPN
{
public:
    RPN(string s) { rpnString = str2rpn(s); }

    string str2rpn(string s);
    void output() { cout << rpnString << endl; }
private:
    string rpnString;
    stack<char> optr;
};

string RPN::str2rpn(string s)
{
    string ans;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*' || s[i] == '/')
        {
            if (!optr.empty() && (optr.top() == '*' || optr.top() == '/'))
            {
                ans += optr.top();
                optr.pop();
                optr.push(s[i]);
            }
            else
            {
                optr.push(s[i]);
            }
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            while (!optr.empty() && (optr.top() == '+' || optr.top() == '-' || optr.top() == '*' || optr.top() == '/'))
            {
                ans += optr.top();
                optr.pop();
            }
            optr.push(s[i]);
        }
        else if (s[i] == '(')
        {
            optr.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (optr.top() != '(')
            {
                ans += optr.top();
                optr.pop();
            }
            optr.pop();
        }
        else
        {
            ans += s[i];
        }
    }
    while (!optr.empty())
    {
        ans += optr.top();
        optr.pop();
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    RPN rpnString(s);
    rpnString.output();

    return 0;
}