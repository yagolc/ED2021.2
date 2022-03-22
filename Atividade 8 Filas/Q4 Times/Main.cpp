#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Estudante
{
public:
    string nome;
    int h;
    Estudante() {}
    Estudante(string nome, int h) : nome(nome), h(h) {}
};

bool comp(const Estudante e1, const Estudante e2)
{
    return e1.h > e2.h;
}

int main()
{
    int n, t;

    cin >> n >> t;

    vector<Estudante> v;

    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].nome >> v[i].h;
    }

    // Ordena os estudantes em ordem decrescente
    sort(v.begin(), v.end(), comp);

    vector<string> nome;
    for (int i = 0, j = 0; i < t;)
    {
        nome.push_back(v[j].nome);
        j += t;
        if (j >= n)
        {
            i++;
            j = i;
            sort(nome.begin(), nome.end());
            for (int k = 0; k < nome.size(); k++)
            {
                if (k == 0)
                    cout << "Time " << i << endl;
                cout << nome[k] << endl;
            }
            nome.erase(nome.begin(), nome.end());
            cout << endl;
            if (i == t)
                cout << endl;
        }
    }
}