//
// Created by krivonosovTi on 21.03.2024.
//

#include <iostream>
#include <vector>
#include <utility>
#include "basic_function.h"
//#include "/Users/krivonosovti/SPbU/3course/winbgim/graphics.h"

using namespace std;
double main_func(double x){
    return x * x / (1 + x * x); //мотонна от на отрезках R+ and R-
}

double func(double x){
    return x * x; //мотонна от на отрезках R+ and R-
}

bool inputData(int &NumValInTable, double &a,double &b, double &x,double &degree, int &err)
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

    cout << "точка интерполирования, значение в которой хотим найти x=";
    cin >> x;
    degree = NumValInTable-1;
//    cout <<"степень интерполяционного многочлена, который будет построен (n<=m) n="
//           "для того, чтобы найти значение в точке x.";
//    cin >> degree;
    if(NumValInTable-1 < degree) {
        err = 3;
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


bool compare(const pair<double, double>& a, const pair<double, double>& b, const double& x) {
    return abs(a.second - x) < abs(b.second - x);
}

void sortByDistance(vector<pair<double, double>>& Table, const double& x) {
    sort(Table.begin(), Table.end(), [&](const pair<double, double>& a, const pair<double, double>& b) {
        return compare(a, b, x);
    });
}

//
//void drow_graph(vector<pair <double,double>>& func) //vector<pair <double,double>>& polimominal)
//{
//    int width = 100, height = 100;
//    char* title="Граффик функция/полином";
//    int left=0,  top=0;
//    bool dbuf=false,  closeall=true;
//    int window = initwindow( width, height, title, left, top, dbuf, closeall);
//    int size = func.size();
//
//    for (int i =0; i  < size - 1; i++)
//    {
//        line( (int) func[i].first, (int) func[i].second,(int) func[i+1].first, (int) func[i+1].second);
//       // line( (int) polimominal[i].first, (int) polimominal[i].second,(int) polimominal[i+1].first, (int) polimominal[i+1].second);
//    }
//}