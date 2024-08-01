//
// Created by krivonosovTi on 30.05.2024.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double func(double x, double y) {
    return (-y + exp(-x));
}

double exactSol(double x) {
    return exp(-x) * (x + 1);
}

double teylor(double x) { // ошибка
    return(1.0 - x*x/2.0 - 1.0/24.0 * pow(x,4) - 1 / 720.0 * pow(x,6) -1 /40320.0 * pow(x,8));
}

void printResults(double x, double y_teyl, double y_exact, double abs_error) {
    cout << "  " << fixed << setprecision(8) << x << "  |  "
         << fixed << setprecision(10) << y_teyl << "  |  "
         << fixed << setprecision(10) << y_exact << "  |  "
         << fixed << setprecision(10) << abs_error << endl;
}

void task6_main() {
    cout << "Численное решение Задачи Коши для обыкновенного дифференциального уравнения первого порядка" << endl;
    cout << "Исходная Задача Коши: y'(x)= -y(x) + exp(-x), y(0) = 1" << endl;
    cout << "Точное решение:  exp(-x)*(x+1)" << endl;

    int N;
    double h;
    cout << "Введите количество узлов: ";
    cin >> N;
    cout << "Шаг: ";
    cin >> h;

    cout << "     x_k      |     y_тейл     |     y_точн     |  абс.погр. " << endl;

    vector<pair<double, double>> mas;
    vector<double> arr;

//    for (int i = -2; i <= N; ++i) {
////        if (-3 < i && i < 3) {
//            double x = i * h;
//            double y_taylor = teylor(x);
//            mas.push_back(make_pair(x, y_taylor));
//            arr.push_back(h * func(x, y_taylor));
//            printResults(x, y_taylor, exactSol(x), abs(y_taylor - exactSol(x)));
//     //   }
//    }

    for (int i = -2; i <= N; ++i) {
//        if (-3 < i && i < 3) {
        double x = i * h;
        double y_taylor = exactSol(x);
        mas.push_back(make_pair(x, y_taylor));
        arr.push_back(h*exactSol(x));
        printResults(x, y_taylor, exactSol(x), abs(y_taylor - exactSol(x)));
        //   }
    }

    for (int i = 3; i <= N; ++i) {
        mas.push_back(make_pair(i * h, 0));
    }

    cout << "\nЭкстраполяционный метод Адамса 4-го порядка: " << endl;
    for (int i = 5; i < N + 3; ++i) {
        vector<double> newarr(arr.end() - 5, arr.end());
        double delta1 = newarr[4] - newarr[3];
        double delta2 = newarr[4] - 2 * newarr[3] + newarr[2];
        double delta3 = newarr[4] - 3 * newarr[3] + 3 * newarr[2] - newarr[1];
        double delta4 = newarr[4] - 4 * newarr[3] + 6 * newarr[2] - 4 * newarr[1] + newarr[0];
        mas[i].second = mas[i - 1].second + newarr[4] + 0.5 * delta1 + (5.0 / 12) * delta2 + (3.0 / 8) * delta3 + (251.0 / 720) * delta4;
        arr.push_back(h * func(mas[i].first, mas[i].second));
    }
//    for (const auto &m : mas) {
//        cout << "(" << m.first << ", " << m.second << ") \n";
//    }
//    cout << "\n\n";

    cout << "Метод Рунге-Кутта 4-го порядка: " << endl;
    vector<pair<double, double>> masRunge(N + 1);
    masRunge[0] = make_pair(0, 1);
    for (int i = 1; i <= N; ++i) {
        double k1 = h * func(masRunge[i - 1].first, masRunge[i - 1].second);
        double k2 = h * func(masRunge[i - 1].first + h / 2, masRunge[i - 1].second + k1 / 2);
        double k3 = h * func(masRunge[i - 1].first + h / 2, masRunge[i - 1].second + k2 / 2);
        double k4 = h * func(masRunge[i - 1].first + h, masRunge[i - 1].second + k3);
        masRunge[i] = make_pair(i * h, masRunge[i - 1].second + (1.0 / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
    }
//    for (const auto &m : masRunge) {
//        cout << "(" << m.first << ", " << m.second << ") \n" ;
//    }
//    cout << "\n\n";

    cout << "Метод Эйлера: " << endl;
    vector<pair<double, double>> masEil(N + 1);
    masEil[0] = make_pair(0, 1);
    for (int i = 1; i <= N; ++i) {
        masEil[i] = make_pair(i * h, masEil[i - 1].second + h * func(masEil[i - 1].first, masEil[i - 1].second));
    }
//    for (const auto &m : masEil) {
//        cout << "(" << m.first << ", " << m.second << ") \n";
//    }
//    cout << "\n\n";

    cout << "Метод Эйлера I: " << endl;
    vector<pair<double, double>> masEil1(N + 1);
    masEil1[0] = make_pair(0, 1);
    for (int i = 1; i <= N; ++i) {
        masEil1[i] = make_pair(i * h, masEil1[i - 1].second + h * func(masEil1[i - 1].first + h / 2, masEil1[i - 1].second + h / 2 * func(masEil1[i - 1].first, masEil1[i - 1].second)));
    }
//    for (const auto &m : masEil1) {
//        cout << "(" << m.first << ", " << m.second << ") \n";
//    }
//    cout << "\n\n";

    cout << "Метод Эйлера II: " << endl;
    vector<pair<double, double>> masEil2(N + 1);
    masEil2[0] = make_pair(0, 1);
    double euler_midpoint;
    for (int i = 1; i <= N; ++i) {
        euler_midpoint  = masEil2[i-1].second + h * func( masEil2[i-1].first + h/2.0,masEil2[i-1].second + h/2.0 * func(masEil2[i-1].first ,masEil2[i-1].second ));
        masEil2[i] = make_pair(masEil2[i-1].first +h, euler_midpoint);
    }
//    for (const auto &m : masEil2) {
//        cout << "(" << m.first << ", " << m.second << ") \n";
//    }
//    cout << "\n\n";

    cout << "Погрешности в последнем узле в разных методах: " << endl;
    cout << "Метод разложения Тейлора: " << fixed << setprecision(16) << abs(teylor(N * h) - exactSol(N * h)) << endl;
    cout << "Метод Эйлера:             " << fixed << setprecision(16) << abs(masEil[N].second - exactSol(N * h)) << endl;
    cout << "Метод Эйлера I:           " << fixed << setprecision(16) << abs(masEil1[N].second - exactSol(N * h)) << endl;
    cout << "Метод Эйлера II:          " << fixed << setprecision(16) << abs(masEil2[N].second - exactSol(N * h)) << endl;
    cout << "Метод Рунге-Кутта IV:     " << fixed << setprecision(16) << abs(masRunge[N].second - exactSol(N * h)) << endl;
    cout << "Экстрап. метод Адамса IV: " << fixed << setprecision(16) << abs(mas[N+2].second - exactSol(N * h)) << endl;
}
