#ifndef RAIOS_HPP
#define RAIOS_HPP

#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Raios
{

private:
    int n;
    int m;
    vector<int> v1;
    vector<int> v2;
    int res;

public:
    Raios(int N, int M)
    {
        this->n = N;
        this->m = M;
        this->res = 0;
    }

    void add(int x, int y)
    {
        if ((x >= 0 && x <= 500) && (y >= 0 && y <= 500))
        {
            v1.push_back(x);
            v2.push_back(y);
        }

        for (int i = 0; i < v1.size(); i++)
        {
            for (int j = 0; j < v2.size(); j++)
            {
                if ((v1[i] == v1[j] && v2[i] == v2[j]) && i != j)
                {
                    this->res++;
                    v1[i] = 0;
                    v2[i] = 0;
                    j = v2.size() + 1;
                }
            }
        }
    }
    int mesmo_lugar()
    {
        return res;
    }
};

#endif