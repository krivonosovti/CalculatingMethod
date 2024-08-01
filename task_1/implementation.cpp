//
// Created by krivonosovTi on 21.03.2024.
//
#include <iostream>
#include <vector>
#include <utility>
#include "interpolationNewton.h"

using namespace std;
double divide_difference(vector  <pair <double,double>>&  node, int k)  // https://studfile.net/preview/3075823/page:3/
{
    double result =0;
    for (int j = 0; j <=k; j++)
    {
        double mul =1;
        for (int i = 0; i <=k; i++)
        {
            if (i != j)
                mul *= node[j].first - node[i].first;
        }
        result += node[j].second/mul;

    }
    return result;
}

double newton_polinominal(vector <pair <double,double>>& Table, double x,  vector <double>& div_diff)
{
    double result = Table[0].second;
    for (int k= 1; k < Table.size(); k++)
    {
        double mul = 1;
        for (int j = 0; j<k; j++)
            mul *= (x-Table[j].first);
        result += div_diff[k-1]*mul;
    }
    return result;
}

double create_Newton_polinomial(vector <pair <double,double>>& Table, double x, double degree)
{
    vector <double> div_diff;
    for (int i =1; i<= degree; i++)
    {
        div_diff.push_back(divide_difference(Table, i));
    }
    return newton_polinominal(Table, x, div_diff);
}
