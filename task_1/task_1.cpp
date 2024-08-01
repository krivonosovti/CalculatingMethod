//
// Created by krivonosovTi on 28.02.2024.
//
#include <iostream>
#include <vector>
#include <utility>
#include "interpolationNewton.h"
#include "../basic_function.h"

using namespace  std;

void interpolationByNewton() {
    int NumValInTable, err;
    double a, b, x,degree;
    bool checker;
    vector<pair<double, double>> nodes;

    cout << "Задача 1    ЗАДАЧА АЛГЕБРАИЧЕСКОГО ИНЕРПОЛИРОВАНИЯ" << endl;
    cout << " Вариант 6" << endl << endl;
    while (true)
    {
        checker = false;
        while (!checker) {
            checker =  inputData(NumValInTable,a,b,err);
            if (!checker) {
                // cout << "a > b or n>m exeption" << endl << endl;
                switch (err) {
                    case 1:
                        cout << "m <= 0 exeption"<< endl << endl;
                        break;
                    case 2:
                        cout << "a > b exeption" << endl << endl;
                        break;
                    case 3:
                        cout << "NumValInTable-1 < degree exeption" << endl << endl;
                        break;
                }

            }
        }


        nodes = buildFunctionValues(a, b, NumValInTable);

        vector_print(nodes);
        int check = 1;

        while(check == 1)
        {

            cout << endl << "Точка интерполирования, значение в которой хотим найти x=";
            cin >> x;
            cout << endl << "Введите степень полинома меньше m+1: ";
            cin >> degree;
            if (degree > NumValInTable)
            {
                cout << "Введите степень меньше m+1 \n";
                continue;
            }
            cout << endl;
            cout << endl;

            sortByDistanceFromX(nodes, x);

            vector_print(nodes);
            double result = create_Newton_polinomial(nodes, x, degree);

            cout << "result = " << result<< ". Погрешность = "<< abs(func(x) - result)  <<"." << endl << endl << endl; //fn(x)=|f(x)-PnL(x)|

            cout <<"Хотите ввести новое значение x? Введите 1: \n" ;
            cin >> check;
        }

       // drow_graph(nodes);

        cout << "Для перехода к другому заданию введите -1: ";
        int br;
        cin >> br;
        if (br == -1)
            return;
    }
}