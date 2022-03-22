#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int n, valor;
    vector<int> A;
    stack<int> indices;
    cin >> n;
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> valor;
        A.push_back(valor);
        indices.push(i);
    }

    for (int j = indices.top(), i = 0; i < n; j++)
    {
        if (A[j] > A[i])
        {
            i++;
            indices.pop();
            cout << j << " ";
            j = indices.top();
        }
        else if (j >= (n - 1))
        {
            indices.pop();
            if (j > (n - 1))
                cout << "-1" << endl;
            else
            {
                cout << "-1"
                     << " ";
                j = indices.top();
            }
            i++;
        }
    }
}