//
// Created by krivonosovTi on 18.05.2024.
//

#include "task_4main.h"
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

int rate = 15;
// Функция f(x) = sin(x) + 1
double f(double x) {
    return sin(x) + 1;
}

// Антидифференциал функции f(x)
double ff(double x) {
    return -cos(x) + x;
}

// Функция f0(x) = 1
double f0(double x) {
    return 1;
}

// Интеграл функции f0(x)
double f00(double x) {
    return 1 * x;
}

// Интеграл task_4_f1(x) = x + 2
double task_4_f1(double x) {
    return x + 2;
}

// Интеграл функции task_4_f1(x)
double task_4_f11(double x) {
    return (pow(x, 2) / 2) + 2 * x;
}

// Функция f3(x) = x^3 + x^2 - 2x + 1
double f3(double x) {
    return pow(x, 3) + pow(x, 2) - 2 * x + 1;
}

// Антидифференциал функции f3(x)
double f33(double x) {
    return (pow(x, 4) / 4) + (pow(x, 3) / 3) - pow(x, 2) + x;
}

// Метод левых прямоугольников
double Lrect(double (*f)(double), double a, double b) {
    return (b - a) * f(a);
}

// Метод правых прямоугольников
double Rrect(double (*f)(double), double a, double b) {
    return (b - a) * f(b);
}

// Метод средних прямоугольников
double Mrect(double (*f)(double), double a, double b) {
    return (b - a) * f((a + b) / 2);
}

// Метод трапеций
double Trap(double (*f)(double), double a, double b) {
    return (b - a) * (f(b) + f(a)) / 2;
}

// Метод Симпсона
double Simps(double (*f)(double), double a, double b) {
    return (b - a) * (f(a) + 4 * f((a + b) / 2) + f(b)) / 6;
}

// Метод 3/8
double Threight(double (*f)(double), double a, double b) {
    return (b - a) * (f(a) + 3 * f(a + (b - a) / 3) + 3 * f(a + 2 * (b - a) / 3) + f(b)) / 8;
}

void mainFunc_1() {
    // Ввод параметров задачи
    cout << "Введите параметры задачи - пределы интегрирования:" << endl;
    double a, b;
    cout << "А = ";
    cin >> a;
    cout << "B = ";
    cin >> b;

    double (*d)(double);
    double (*h)(double);

    while (true) {
        // Ввод типа функции
        cout << "Введите цифру 0, 1 или 3 - для обработки многочлена соответствующей степени" << endl;
        cout << "Иначе Введите -1, для обработки функции f=sin(x)+1" << endl;
        int o;
        cin >> o;

        // Определение функций в зависимости от выбора пользователя


        if (o == -1) {
            d = f;
            h = ff;
            break;
        } else if (o == 1) {
            d = task_4_f1;
            h = task_4_f11;
            cout << "p_1(x) = x + 2 \n";
            break;
        } else if (o == 0) {
            d = f0;
            h = f00;
            cout << "p_o(x) = 1 \n";
            break;
        } else if (o == 3) {
            d = f3;
            h = f33;
            cout << "p_3(x) = x^3 + x^2 - 2x + 1 \n";
            break;
        } else {
            cout << "Введен неверный символ. " << endl;
        }
    }

    // Вывод результатов вычислений
    cout << "Квадатурная формула   |  Значение   | Абсолютная погрешность" << endl;
    cout << fixed << setprecision(rate);
    cout << "КФ Левого прямоуг.    | " << setw(13) << Lrect(d, a, b) << " | " << abs(Lrect(d, a, b) - h(b) + h(a)) << endl;
    cout << "КФ Правого прямоуг.   | " << setw(13) << Rrect(d, a, b) << " | " << abs(Rrect(d, a, b) - h(b) + h(a)) << endl;
    cout << "КФ Среднего прямоуг.  | " << setw(13) << Mrect(d, a, b) << " | " << abs(Mrect(d, a, b) - h(b) + h(a)) << endl;
    cout << "КФ Трапеции           | " << setw(13) << Trap(d, a, b) << " | " << abs(Trap(d, a, b) - h(b) + h(a)) << endl;
    cout << "КФ Симпсона           | " << setw(13) << Simps(d, a, b) << " | " << abs(Simps(d, a, b) - h(b) + h(a)) << endl;
    cout << "КФ 3/8                | " << setw(13) << Threight(d, a, b) << " | " << abs(Threight(d, a, b) - h(b) + h(a)) << endl;
}

// Составной метод левых прямоугольников
double SostLrect(double (*f)(double), double a, double b, int m) {
    double integ = 0;
    double k = (b - a) / m;
    for (int i = 0; i < m; i++) {
        integ += Lrect(f, a + i * k, a + (i + 1) * k);
    }
    return integ;
}

// Составной метод правых прямоугольников
double SostRrect(double (*f)(double), double a, double b, int m) {
    double integ = 0;
    double k = (b - a) / m;
    for (int i = 0; i < m; i++) {
        integ += Rrect(f, a + i * k, a + (i + 1) * k);
    }
    return integ;
}

// Составной метод средних прямоугольников
double SostMrect(double (*f)(double), double a, double b, int m) {
    double integ = 0;
    double k = (b - a) / m;
    for (int i = 0; i < m; i++) {
        integ += Mrect(f, a + i * k, a + (i + 1) * k);
    }
    return integ;
}

// Составной метод трапеций
double SostTrap(double (*f)(double), double a, double b, int m) {
    double integ = 0;
    double k = (b - a) / m;
    for (int i = 0; i < m; i++) {
        integ += Trap(f, a + i * k, a + (i + 1) * k);
    }
    return integ;
}

// Составной метод Симпсона
double SostSimps(double (*f)(double), double a, double b, int m) {
    double integ = 0;
    double k = (b - a) / m;
    for (int i = 0; i < m; i++) {
        integ += Simps(f, a + i * k, a + (i + 1) * k);
    }
    return integ;
}

void mainFunc_2() {
    // Ввод параметров задачи
    cout << "Задача 4: Приближенное вычисление интеграла по квадратурным формулам" << endl;
    cout << "Введите параметры задачи - пределы интегрирования:" << endl;
    double a, b;
    cout << "А = ";
    cin >> a;
    cout << "B = ";
    cin >> b;

    // Ввод количества промежутков деления
    cout << "Введите количество промежутков деления" << endl;
    int m;
    cout << "M = ";
    cin >> m;

    // Ввод выбора функции
    cout << "Введите номер функции для вычисления интеграла: " << endl;
    cout << "0) f(x) = 4" << endl;
    cout << "1) f(x) = x + 2" << endl;
    cout << "3) f(x) = x^3 + x^2 - 2x + 1" << endl;
    cout << "5) f(x) = sin(x) + 1" << endl;
    int o;
    cin >> o;

    // Определение функций в зависимости от выбора пользователя
    double (*d)(double) = (o == 5) ? f : (o == 1) ? task_4_f1 : (o == 0) ? f0 : f3;
    double (*h)(double) = (o == 5) ? ff : (o == 1) ? task_4_f11 : (o == 0) ? f00 : f33;

    // Вычисление точного значения интеграла
    double exactIntegral = h(b) - h(a);
    cout << "Вычисленный интеграл: J = " << exactIntegral << endl;
    cout << "Составная КФ          |  Значение   | Абс. погрешность | Относ. погрешность |" << endl;
    cout << fixed << setprecision(16);
    cout << "КФ Левого прямоуг.    | " << setw(13) << SostLrect(d, a, b, m)
         << " | " << setw(18) << abs(SostLrect(d, a, b, m) - exactIntegral)
         << " | " << setw(20) << abs((SostLrect(d, a, b, m) - exactIntegral) / exactIntegral) << " |" << endl;
    cout << "КФ Правого прямоуг.   | " << setw(13) << SostRrect(d, a, b, m)
         << " | " << setw(18) << abs(SostRrect(d, a, b, m) - exactIntegral)
         << " | " << setw(20) << abs((SostRrect(d, a, b, m) - exactIntegral) / exactIntegral) << " |" << endl;
    cout << "КФ Среднего прямоуг.  | " << setw(13) << SostMrect(d, a, b, m)
         << " | " << setw(18) << abs(SostMrect(d, a, b, m) - exactIntegral)
         << " | " << setw(20) << abs((SostMrect(d, a, b, m) - exactIntegral) / exactIntegral) << " |" << endl;
    cout << "КФ Трапеции           | " << setw(13) << SostTrap(d, a, b, m)
         << " | " << setw(18) << abs(SostTrap(d, a, b, m) - exactIntegral)
         << " | " << setw(20) << abs((SostTrap(d, a, b, m) - exactIntegral) / exactIntegral) << " |" << endl;
    cout << "КФ Симпсона           | " << setw(13) << SostSimps(d, a, b, m)
         << " | " << setw(18) << abs(SostSimps(d, a, b, m) - exactIntegral)
         << " | " << setw(20) << abs((SostSimps(d, a, b, m) - exactIntegral) / exactIntegral) << " |" << endl;
}


void task_4main() {
    int chose;
    cout << "Задание №4 \n Выберите пункт задания (1/2)" << endl;
    cin >> chose;
    if (chose % 2 == 1) {
        cout << "Задание №4.1 \n Приближённое вычисление интеграла по квадратурным формулам" << endl;
       mainFunc_1();
    }
    else {
        cout << "Задание №4.2 \n Приближённое вычисление интеграла по составным квадратурным формулам" << endl;
        mainFunc_2();
    }
}
