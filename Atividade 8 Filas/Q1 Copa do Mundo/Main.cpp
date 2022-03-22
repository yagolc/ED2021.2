#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    string times = "ABCDEFGHIJKLMNOP";
    queue<char> tabela;

    for (int i = 0; i < 16; i++)
    {
        tabela.push(times[i]);
    }

    for (int i = 0, m = 0, n = 0; i < 15; i++)
    {
        cin >> m >> n;

        if (m > n)
        {
            char aux = tabela.front();
            tabela.pop();
            tabela.pop();
            tabela.push(aux);
        }
        else
        {
            tabela.pop();
            char aux = tabela.front();
            tabela.pop();
            tabela.push(aux);
        }
    }
    cout << tabela.front() << endl;
}