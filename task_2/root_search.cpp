//
// Created by krivonosovTi on 21.03.2024.
//
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;


double  six_var_func (double x) {
    double result = cos(x);
    result = result * 8.0 - x - 6.0;
    return result;
}

double operation(double(*op)(double), double a)
{
    return op(a);
}

//operation(add, a, b)
pair<double, double> bisection(double A,  double B, const double error_rate, int &con ){
    double C = 0;
    int counter = 0;
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
        counter++;
    }
    double x = (A+B)/2.0;
    con = counter;

    return make_pair((double )x,(double) (B-A)/2.0);
}

pair<double, double>  pruner (double A,  double B, const double error_rate, int& counter){  //тут херня какая-то
    double X1 = A, C = B - A, X2 = INT_MAX, Yc;
    while (abs(X2 - C) > error_rate) {
        Yc = operation(six_var_func, C);
        X2 = C - ((C - X1)/(Yc - operation(six_var_func, X1))) * Yc;
        counter += 1;
    }

    return make_pair((double) X2, (double ) error_rate);
}

pair<double, double> correction (pair <double, double> (*op) (double A, double B, double error_rate, int& counter), double A, double B, double error_rate, int& counter ) {
   return op(A,B,error_rate, counter);
}

void print_result_from_vector(vector <pair <double,double>> RES){
    for (int i = 0; i < RES.size(); i++)
        cout << RES[i].first << "  +- " << RES[i].second << '{' << operation(six_var_func,RES[i].first)<<" - 0}"<< endl;
}


string root_div(double A, double B, int N, double error_rate, int type)
{

    if(N < 2) {
        cout << " N<2 exeption";
        return nullptr;
    }

    string result = " ";
    int counter = 0;
    int m = 0;
    double H = (B-A)/N;
    double X1 = A, X2 = X1+H, Y1 = operation(six_var_func, X1), Y2 = 0.0; //в operation идет присваивание коругление хуй пойми почему!!!!!!ЫЫ
    vector <pair <double,double>> RES;
    while(X2 <= B)
    {
        if(X1 == -8.28);
        Y2 = operation(six_var_func,X2);

        if (Y1*Y2<=0)
        {
            counter++;
            if (type == 1)
                RES.push_back(correction(bisection, X1, X2, error_rate, m));
            else
                RES.push_back(correction(pruner, X1, X2, error_rate, m));

            result += "["+ to_string(X1) + ' ' + to_string(X2) + "]  ";
        }

            X1 = X2;
            X2 = X1 + H;
            Y1 = Y2;

    }

    result += ' '+to_string(counter);
    cout << "колличество шагов: " << m << endl;
    print_result_from_vector (RES);

    return result ;
}

