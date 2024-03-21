//
// Created by krivonosovTi on 21.03.2024.
//
#include <iostream>
#include <cmath>

using namespace std;

double  six_var_func (double x) {
    double result = 8 * cos(x) - x - 6;
    return x;
}

int operation(double(*op)(double), double a)
{
    return op(a);
}

//operation(add, a, b)
void bisection(double A,  double B, const double error_rate) {
    double C = (A+B)/2;
    while (B-A<=2*error_rate)
    {
        if (operation(six_var_func,A) * operation(six_var_func,B) > 0)
        {
            A=C;
        }
        else
        {
            B=C;
        }
    }
    double x = (A+B)/2;

    cout << x << "+-" << (B-A)/2 << '|' << operation(six_var_func,x)<<" - 0" << '|'<<endl;
}


