#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
    int exp;
    int coef;
    int symbol;
    node* next;

    node(int theExp, int theCoef, int theSymbol, node* theNext)
    {
        this->exp = theExp;
        this->coef = theCoef;
        this->symbol = theSymbol;
        this->next = theNext;
    }
};

struct list
{
    node* head;
    int size;

    list(vector<int>& theExp, vector<int>& theCoef, vector<int>& theSymbol);
    void derivation();
    void print();
};

list::list(vector<int>& theExp, vector<int>& theCoef, vector<int>& theSymbol)
{
    this->size = 0;
    this->head = new node(0, 0, 0, nullptr);

    node* p = this->head;
    p->next = this->head;

    for (int i = 0; i < theExp.size(); i++)
    {
        while (p->next != head && theExp[i] < p->next->exp)
        {
            p = p->next;
        }

        if (p->next == this->head)
        {
            node* temp = new node(theExp[i], theCoef[i], theSymbol[i], this->head);
            p->next = temp;
            this->size++;
        }
        else if (p->next->exp == theExp[i])
        {
            int a = p->next->symbol * p->next->coef + theSymbol[i] * theCoef[i];
            if (a < 0)
            {
                p->next->symbol = -1;
                p->next->coef = -a;
            }
            else if (0 < a)
            {
                p->next->symbol = 1;
                p->next->coef = a;
            }
            else
            {
                p->next = p->next->next;
                this->size--;
            }
        }
        else
        {
            node* temp = new node(theExp[i], theCoef[i], theSymbol[i], p->next);
            p->next = temp;
            this->size++;
        }

        p = this->head;
    }
}

void list::derivation()
{
    node* p = this->head;
    while (p->next != this->head)
    {
        if (p->next->exp == 0)
        {
            p->next = this->head;
            this->size--;
            break;
        }

        p->next->coef = p->next->coef * p->next->exp;
        p->next->exp--;
        p = p->next;
    }
}

void list::print()
{
    node* p = this->head;
    if (this->size == 0)
    {
        cout << 0 << ' ';
        return;
    }
    for (int i = 0; i < this->size; i++)
    {
        if (p->next->symbol == -1)
        {
            cout << '-' << ' ';
        }
        else // p->next->symbol == 1
        {
            if (i != 0)
            {
                cout << '+' << ' ';
            }
        }

        cout << p->next->coef;

        if (p->next->exp > 1)
        {
            cout << "x^" << p->next->exp << ' ';
        }
        else if (p->next->exp == 1)
        {
            cout << 'x' << ' ';
        }
        else
        {
            cout << ' ';
        }

        p = p->next;
    }
}

void input(vector<int>& theExp, vector<int>& theCoef, vector<int>& theSymbol)
{
    string s;
    getline(cin, s);

    bool carry_coef = false;
    bool carry_exp = false;

    int coef = 0;
    int exp = 0;

    for (int i = 0; i < s.size(); i++)
    {
        // s[i] == [0 - 9]
        if ('0' <= s[i] && s[i] <= '9')
        {
            if (carry_coef)
            {
                coef = 10 * coef + int{ s[i] - '0' };
                if (i == s.size() - 1)
                {
                    theCoef.push_back(coef);
                    carry_coef = false;
                    coef = 0;
                    theExp.push_back(0);
                }
            }
            else if (carry_exp)
            {
                exp = 10 * exp + int{ s[i] - '0' };
                if (i == s.size() - 1)
                {
                    theExp.push_back(exp);
                    carry_exp = false;
                    exp = 0;
                }
            }
            else
            {
                carry_coef = true;
                coef = int{ s[i] - '0' };
                if (i == s.size() - 1)
                {
                    theCoef.push_back(coef);
                    carry_coef = false;
                    coef = 0;
                    theExp.push_back(0);
                }
            }
        }
        else if (s[i] == '-')
        {
            if (carry_coef)
            {
                theCoef.push_back(coef);
                carry_coef = false;
                coef = 0;
                theExp.push_back(0);
            }
            else if (carry_exp)
            {
                theExp.push_back(exp);
                carry_exp = false;
                exp = 0;
            }
            theSymbol.push_back(-1);
        }
        else if (s[i] == '+')
        {
            if (carry_coef)
            {
                theCoef.push_back(coef);
                carry_coef = false;
                coef = 0;
                theExp.push_back(0);
            }
            else if (carry_exp)
            {
                theExp.push_back(exp);
                carry_exp = false;
                exp = 0;
            }
            theSymbol.push_back(1);
        }
        else if (s[i] == 'x')
        {
            if (carry_coef)
            {
                theCoef.push_back(coef);
                carry_coef = false;
                coef = 0;
            }
            else
            {
                theCoef.push_back(1);
            }

            if (i == s.size() - 1 || s[i + 1] == ' ')
            {
                theExp.push_back(1);
            }
        }
        else if (s[i] == '^')
        {
            carry_exp = true;
        }
        else // s[i] == ' '
        {
            continue;
        }
    }
    if (theSymbol.size() < theExp.size())
        theSymbol.insert(theSymbol.begin(), 1);
}

int main()
{
    vector<int> exp;
    vector<int> coef;
    vector<int> symbol;

    input(exp, coef, symbol);

    list L(exp, coef, symbol);
    L.derivation();
    L.print();

    return 0;
}