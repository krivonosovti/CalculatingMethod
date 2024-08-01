//
// Created by krivonosovTi on 21.03.2024.
//

#include <iostream>
#include <vector>
#include <utility>
#include "basic_function.h"

using namespace std;
double func(double x){
    return x * x / (1 + x * x); //мотонна от на отрезках R+ and R-
}

double func_test (double x)
{
    return exp(x);
}

double test_func(double x){
    return x * x; //мотонна от на отрезках R+ and R-
}

bool inputData(int &NumValInTable, double &a,double &b, int &err)
{

    cout << "Число значений в таблице m+1=";
    cin >> NumValInTable;
    if (NumValInTable <= 0) {
        err = 1;
        return false;
    }
    cout << "Левый конец интервала из которого выбираются узлы интерполяции a=";
    cin >> a;
    cout << "Правый конец интервала из которого выбираются узлы интерполяции b=";
    cin >> b;

    if (b < a) {
        err = 2;
        return false;
    }

    return  true;
}

vector<pair<double, double>> buildFunctionValues(double a, double b, int numPoints) {
    vector<pair<double, double>> result;

    // Шаг между точкам
    double step = (b - a) / (numPoints - 1);

    for (int i = 0; i < numPoints; ++i) {
        double x = a + i * step;
        double y = func(x);
        result.push_back(make_pair(x, y));
    }
    return result;
}

void vector_print(vector<pair<double, double>>& nodes)
{
    // Выводим значения на экран
    for (const auto& node : nodes) {
        cout << "(" << node.first << ", " << node.second << ")" << endl;
    }
}


void sortByDistanceFromX(vector<pair<double, double>>& nodes, double x) {
  sort(nodes.begin(), nodes.end(), [x](const pair<double, double>& a, const pair<double, double>& b) {
        return abs(a.first - x) < abs(b.first - x);
    });
}


vector<pair<double, double>> buildFunctionValues_2 (double a, double b, int numPoints, double (*func)(double)) {
    vector<pair<double, double>> result;

    // Шаг между точкам
    double step = (b - a) / (numPoints - 1);

    for (int i = 0; i < numPoints; ++i) {
        double x = a + i * step;
        double y = func(x);
        result.push_back(make_pair(x, y));
    }
    return result;
}

