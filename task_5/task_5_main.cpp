#include <iostream>
#include <vector>
#include <cmath>
#include <boost/math/quadrature/gauss.hpp>

using namespace std;
using namespace boost::math::quadrature;

// Функции
//double mnN5(double x) {
//    return pow(x, 5) - 2 * x + 6;
//}
int accuracy = 15;

double task_5_var6_func(double x) {
   // return (x*log(1 + x));
    return (sqrt(x) * sin(x*x));
}

double mnN(double x, int N) {
    return pow(x, 2 * N - 1) - 2 * x + 6;
}

double Lagrange(double x, int N) {
    if (N == 0) {
        return 1;
    } else if (N == 1) {
        return x;
    } else {
        double P0 = 1;
        double P1 = x;
        for (int i = 2; i <= N; ++i) {
            double P = ((2 * i - 1) * x * P1 - (i - 1) * P0) / i;
            P0 = P1;
            P1 = P;
        }
        return P1;
    }
}

vector<pair<double, double>> find_Root(double a, double b, int N, int L) {
    double h = (b - a) / N;
    double n1 = a;
    double n2 = a + h;
    vector<pair<double, double>> mas;
    while (n2 <= b) {
        if (Lagrange(n1, L) * Lagrange(n2, L) <= 0) {
            mas.push_back(make_pair(n1,n2));
        }
        n1 = n2;
        n2 = n1 + h;
    }
    return mas;
}

double SecondMethod(double a, double b, double eps, int L) {
    double n0 = a;
    double n1 = b;
    double n2 = n1 - (Lagrange(n1, L) * (n1 - n0)) / (Lagrange(n1, L) - Lagrange(n0, L));
    while (abs(n1 - n0) >= eps) {
        n2 = n1 - (Lagrange(n1, L) * (n1 - n0)) / (Lagrange(n1, L) - Lagrange(n0, L));
        n0 = n1;
        n1 = n2;
    }
    return n2;
}

double coef(int i, int N, const vector<double>& z) {
    return (2 * (1 - z[i] * z[i]) / (N * N * pow(Lagrange(z[i], N - 1), 2)));
}

double calculate(int N, double eps) {
    auto mas = find_Root(-1, 1, 1000, N);
    vector<double> z;
    for (const auto& m : mas) {
        z.push_back(SecondMethod(m.first, m.second, eps, N));
    }
    vector<double> lcoef(N);
    for (int i = 0; i < N; ++i) {
        lcoef[i] = coef(i, N, z);
    }
    double res = 0;
    for (int i = 0; i < N; ++i) {
        res += lcoef[i] * mnN(z[i], N);
    }
    return res;
}

void task_5_sab2_main() {
    cout << "Вычисление интегралов при помощи КФ Гаусса" << endl;
    double eps = 1e-12;
    int h = 1;
    cout << "Узлы и Коэффициенты для N узлов (1<=N<=8)" << endl;
    while (h < 9) {
        auto mas = find_Root(-1, 1, 1000, h);
        vector<double> z;
        for (const auto& m : mas) {
            z.push_back(SecondMethod(m.first, m.second, eps, h));
        }
        cout << "Узлы:" << endl;
        double sum1 = 0;
        for (double zi : z) {
            cout << fixed << setprecision(accuracy) << zi << " ";
        }

        cout << endl;
        vector<double> lcoef(h);
        for (int i = 0; i < h; ++i) {
            lcoef[i] = coef(i, h, z);
        }
        cout << "Коэффициенты:" << endl;
        for (double lc : lcoef) {
            cout << fixed << setprecision(accuracy)  << lc << " ";
            sum1+=lc;
        }
        cout << "Сумма = "<< sum1;
        cout << endl << endl;
        h++;
    }

    cout << "Проверка точности для многочленов степени 5,7,9 для N=3,4,5" << endl;
    for (int i = 3; i < 6; ++i) {
        double integral = gauss<double, 15>::integrate([i](double x) { return mnN(x, i); }, -1.0, 1.0);
        cout << fixed << setprecision(accuracy)  << abs (calculate(i, eps) - integral) << endl;
    }
    double r[] = {0,0,0};
    double a = 0, b =1;

    while(true) {
        cout << "Введите интервал интегрирования [a, b] (по умолчанию [-1, 1]) \na = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "\n Введите с новой строки 3 значения - количество узлов для нахождения по КФ Гаусса: " << endl;
        vector<int> uz(3);
        for (int i = 0; i < 3; ++i) {
            cin >> uz[i];
        }
        vector<double> z;
        for (int i = 0; i < 3; ++i) {
            cout << endl;
            auto mas = find_Root(a, b, 1000, uz[i]);
            z.clear();
            for (const auto &m: mas) {
                z.push_back(SecondMethod(m.first, m.second, eps, uz[i]));
            }
            vector<double> lcoef(uz[i]);
            for (int j = 0; j < uz[i]; ++j) {
                lcoef[j] = coef(j, uz[i], z);// * 0.5;
            }
            double res = 0;
            for (int j = 0; j < uz[i]; ++j) {
                res += lcoef[j] * task_5_var6_func(z[j]);
            }
            // Пересчет для интервала [a, b]
//            double res = 0;
//            double x;
//            for (int j = 0; j < uz[i]; ++j) {
//                 x = (b - a) / 2 * z[i] + (b + a) / 2; // Масштабирование узлов
//                res += lcoef[i] * task_5_var6_func(x);
//            }
//            res *= (b - a) / 2; // Масштабирование результата

            //res *= 2;
            cout << "Узлы и Коэффициенты для " << uz[i] << " узлов: " << endl;
            cout << "Узлы:" << endl;
            for (double zi: z) {
                cout<< fixed << setprecision(accuracy) << zi << " ";
            }
            cout << endl << "Коэффициенты:" << endl;
            for (double lc: lcoef) {
                cout << fixed << setprecision(accuracy) << lc << " ";
            }

            r[i] = res;

           cout << endl << "Вычисленный интеграл для " << uz[i] << " узлов: " << res << endl
                << "АБСОЛЮТНАЯ ПОГРЕШНОСТЬ : " << fixed << setprecision(accuracy) << abs( gauss<double, 10>::integrate(task_5_var6_func, a, b) -res ) << endl
                << "Реальное значение: " << fixed << setprecision(accuracy) << abs( gauss<double, 10>::integrate(task_5_var6_func, a, b));

        }
        char check;
        cout << "\nВеведите \'0\' если хотите прекратить выполнение задания 5.2: " << endl <<"Иначе любой символ:"<<endl;
        cin >> check;
        if (check == '0')
            break;
    }
    cout << "\n \n \n";
    cout << "АБСОЛЮТНАЯ ПОГРЕШНОСТЬ : " << fixed << setprecision(accuracy) << abs( gauss<double, 6>::integrate(task_5_var6_func, a, b) -r[0] ) << endl;
    cout << "АБСОЛЮТНАЯ ПОГРЕШНОСТЬ : " << fixed << setprecision(accuracy) << abs( gauss<double, 7>::integrate(task_5_var6_func, a, b) -r[1] ) << endl;
    cout << "АБСОЛЮТНАЯ ПОГРЕШНОСТЬ : " << fixed << setprecision(accuracy) << abs( gauss<double, 8>::integrate(task_5_var6_func, a, b) -r[2] ) << endl;

    cout << endl << "task 5.2 successfully complete \n" ;
}
