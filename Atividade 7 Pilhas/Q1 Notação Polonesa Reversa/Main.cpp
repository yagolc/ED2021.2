#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>
using namespace std;

string expr;
int pos = 0;

string get_token()
{
    string token = "";

    if (pos == expr.size())
    {
        token = "$";
        return token;
    }

    while (expr[pos] == ' ')
        pos++;

    if (expr[pos] == '+' || expr[pos] == '-' || expr[pos] == '/' || expr[pos] == '*')
    {
        token = token + expr[pos];
        pos = pos + 1;
        return token;
    }
    else if (isdigit(expr[pos]))
    {
        while (isdigit(expr[pos]))
        {
            token = token + expr[pos];
            pos = pos + 1;
        }
        return token;
    }

    return token;
}

int main()
{

    // push top pop empty size

    getline(cin, expr);
    stack<int> s;
    string token = get_token();
    int aux = 0;
    int ver = 0;
    while (token != "$")
    {

        if (token == "+")
        {
            for (int i = 0; i < 2; i++)
            {
                aux += s.top();
                s.pop();
                if (ver != 0)
                    i = 3;
                if (i == 1)
                    ver++;
            }
        }

        else if (token == "-")
        {
            for (int i = 0; i < 2; i++)
            {
                aux -= s.top();
                s.pop();
                if (ver != 0)
                    i = 3;
                if (i == 1)
                    ver++;
            }
        }

        else if (token == "*")
        {
            for (int i = 0; i < 2; i++)
            {
                if (i == 0 && ver == 0)
                    aux += s.top();
                else
                {
                    aux *= s.top();
                    ver++;
                }
                s.pop();
                if (ver != 0)
                    i = 3;
            }
        }

        else if (token == "/")
        {
            for (int i = 0; i < 2; i++)
            {
                if (i == 0 && ver == 0)
                    aux += s.top();
                else
                {
                    aux /= s.top();
                    ver++;
                }
                s.pop();
                if (ver != 0)
                    i = 3;
            }
        }
        else
        {
            s.push(atoi(token.c_str()));
        }

        token = get_token();
    }
    cout << aux << "\n";
}