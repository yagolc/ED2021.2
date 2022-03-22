#include <iostream>
#include <stack>
using namespace std;

template <class T>
class StackMin
{
private:
    stack<T> data;
    stack<T> min;
    int aux = 0;

public:
    void push(T x)
    {
        if (aux == 0)
        {
            min.push(x);
            aux++;
        }
        else if (x < min.top())
        {
            min.push(x);
        }
        data.push(x);
    }

    bool empty()
    {
        return data.empty();
    }

    T top()
    {
        return data.top();
    }

    void pop()
    {
        if (data.top() == min.top())
            min.pop();

        data.pop();
    }

    T getmin()
    {
        return min.top();
    }
};

int main()
{
    int n;
    StackMin<int> s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int op, x;
        cin >> op;

        if (op == 1)
        {
            cin >> x;
            s.push(x);
        }
        else if (op == 2)
        {
            s.pop();
        }
        else
        {
            cout << s.getmin() << endl;
        }
    }
}