//
// Created by krivonosovTi on 21.03.2024.
//
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double  six_var_func (double x) {
    double result = cos(x);
    result = result * 8.0 - x - 6.0;
    return result;
}

int operation(double(*op)(double), double a)
{
    return op(a);
}

//operation(add, a, b)
void bisection(double A,  double B, const double error_rate) {
    double C = 0;
    while (B-A>2.0*error_rate)
    {
        C = (A+B)/2.0;
        if (operation(six_var_func,A) * operation(six_var_func,C) <= 0)
        {
            B=C;
        }
        else
        {
            A=C;
        }
    }
    double x = (A+B)/2.0;

    cout << x << "  +- " << (B-A)/2.0 << '{' << operation(six_var_func,x)<<" - 0}"<< endl;
}

void pruner (double A,  double B, const double error_rate){

}

void correction (void(*op) (double A, double B, double error_rate), double A, double B, double error_rate ) {
    op(A,B,error_rate);
}

string root_div(double A, double B, int N, double error_rate)
{

    if(N < 2) {
        cout << " N<2 exeption";
        return nullptr;
    }

    string result = " ";
    int counter = 0;
    double H = (B-A)/N;
    double X1 = A, X2 = X1+H, Y1 = operation(six_var_func, X1), Y2 = 0.0; //в operation идет присваивание коругление хуй пойми почему!!!!!!ЫЫ

    while(X2 <= B)
    {
        if(X1 == -8.28);
        Y2 = operation(six_var_func,X2);

        if (Y1*Y2<=0)
        {
            counter++;
            correction(bisection, X1, X2, error_rate);
            result += "["+ to_string(X1) + ' ' + to_string(X2) + "]  ";
        }

            X1 = X2;
            X2 = X1 + H;
            Y1 = Y2;

    }

    result += ' '+to_string(counter);
    return result ;
}

