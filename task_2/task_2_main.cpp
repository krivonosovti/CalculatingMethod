//
// Created by krivonosovTi on 21.03.2024.
//
#include <iostream>
#include "root_search.h"
#include "/Users/krivonosovti/SPbU/3course/basic_function.h"
#include "/Users/krivonosovti/SPbU/3course/task_1/interpolationNewton.h"
#include "reverse_interpolation.h"
using namespace std;

void task2_part1 (double A, double  B, int N, const double error_rate, int type)
{
    cout << "ЧИСЛЕННЫЕ МЕТОДЫ РЕШЕНИЯ НЕЛИНЕЙНЫХ УРАВНЕНИЙ" << endl <<  "Задание 2.1 " << endl;
    cout << "Исходные параметры: [" << A << ';' << B << "]  F(x) = 8cos(x)-x-6  N = "<< N <<"  e = " << error_rate << endl ;

    try{
       cout << "Метод: ";
       if (type == 1)
           cout << "Бисекция"<< endl;
       else
           cout << "Секущих" << endl;
       cout << root_div(A,B,N,error_rate,type);
    }
    catch (exception)
    {
        cout << "N<2";
        return;
    }
}

void task2_part2 () {

    cout << "ЗАДАЧА ОБРАТНОГО ИНТЕРПОЛИРОВАНИЯ" << endl <<  "Задание 2.2 " << endl;

    int NumValInTable, err;
    double a, b, x, degree;
    bool checker;
    vector<pair<double, double>> nodes;
    while (true) {
        checker = false;
        while (!checker) {
            checker = inputData(NumValInTable, a, b, x, reinterpret_cast<double &>(degree), err);
            if (!checker) {
                // cout << "a > b or n>m exeption" << endl << endl;
                cout << "a > b exeption" << endl << endl;
            }
        }

        nodes = buildFunctionValues(a, b, NumValInTable);

        vector_print(nodes);



        double F_x = func(x); //мотонна от на отрезках R+ and R-
        double res = reverse_interpolation_1(nodes, F_x);

        cout << "x = " << x  << "; F(x) = "<< F_x << "; reverse_interpolation( F(x) ) = " << res << "; погрешность = " << abs(x - res) << endl << endl;


        cout << "Для перехода к другому заданию введите -1: ";
        int br;
        cin >> br;
        if (br == -1)
            return;
    }
}

void task2_main() {

        int part;
        cout << "Введите тип задания (mod 2) (1 - поиск корней, 0 - обратная интерполяция) ";
        cin >> part;
        if (part % 2 == 1) {
            double A, B, N, error_rate;
            cout << "    Введите начало интервала: ";
            cin >> A;
            cout << "    Введите конец интервала:";
            cin >> B;
            if (A == B) {
                cout << endl;
                return;
            }
            if (B < A)
                swap(B, A);

            cout << "    Введите размер дробления (>0): ";
            cin >> N;
            if (N <= 0) {
                cout << endl;
                return;
            }

            cout << "    Введите допустимую погрешность: (>0) ";
            cin >> error_rate;
            cout << endl << endl;
            if (error_rate <= 0) {
                cout << endl;
                {
                    cout << endl;
                    return;
                }
            }


            task2_part1(A, B, N, error_rate, 2);
            cout << endl << endl;
            task2_part1(A, B, N, error_rate, 1);
            cout << endl << endl;
        }
        else{
            task2_part2();
            cout << endl;
            return;
        }

        cout << "Для перехода к другому заданию введите -1: ";
        int br;
        cin >> br;
        if (br == -1)
        return;
}