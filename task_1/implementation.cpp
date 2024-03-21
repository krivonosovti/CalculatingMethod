//
// Created by krivonosovTi on 21.03.2024.
//
#include <iostream>
#include <vector>
#include <utility>
#include "interpolationNewton.h"
using namespace std;

//bool inputData(int &NumValInTable, double &a,double &b, double &x,double &degree)
//{
//
//    cout << "Число значений в таблице m+1=";
//    cin >> NumValInTable;
//    cout << "Левый конец интервала из которого выбираются узлы интерполяции a=";
//    cin >> a;
//    cout << "Правый конец интервала из которого выбираются узлы интерполяции b=";
//    cin >> b;
//
//    if (b < a)
//        return false;
//
//    cout << "точка интерполирования, значение в которой хотим найти x=";
//    cin >> x;
//    degree = NumValInTable-1;
////    cout <<"степень интерполяционного многочлена, который будет построен (n<=m) n="
////           "для того, чтобы найти значение в точке x.";
////    cin >> degree;
//    if(NumValInTable-1 < degree)
//        return false;
//    return  true;
//}
//
//vector<pair<double, double>> buildFunctionValues(double a, double b, int numPoints) {
//    vector<pair<double, double>> result;
//
//    // Шаг между точкам
//    double step = (b - a) / (numPoints - 1);
//
//    for (int i = 0; i < numPoints; ++i) {
//        double x = a + i * step;
//        double y = x * x / (1 + x * x);
//        result.push_back(make_pair(x, y));
//    }
//    return result;
//}


double divide_difference(vector  <pair <double,double>>&  node, int k)
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

//void vector_print(vector<pair<double, double>>& nodes)
//{
//    // Выводим значения на экран
//    for (const auto& node : nodes) {
//        cout << "(" << node.first << ", " << node.second << ")" << endl;
//    }
//}

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

double create_Newton_polinomial(vector <pair <double,double>>& Table, double x)
{
    vector <double> div_diff;
    for (int i =1; i< Table.size(); i++)
    {
        div_diff.push_back(divide_difference(Table, i));
    }
    return newton_polinominal(Table, x, div_diff);
}


//
//bool compare(const pair<double, double>& a, const pair<double, double>& b, const double& x) {
//    return abs(a.second - x) < abs(b.second - x);
//}
//
//void sortByDistance(vector<pair<double, double>>& Table, const double& x) {
//    sort(Table.begin(), Table.end(), [&](const pair<double, double>& a, const pair<double, double>& b) {
//        return compare(a, b, x);
//    });
//}
