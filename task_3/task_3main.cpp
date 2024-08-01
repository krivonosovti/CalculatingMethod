#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
int RATE = 15;
int var_mod = 6;
double f1(double x) {
    return x * x / (1 + x * x);
}

double f2(double x) {
    return exp(1.5 * (var_mod % 5 + 1) * x);
}

double f11(double x) {
    return (2*x)/(pow((1+x*x),2)) ;
}

double f22(double x) {
    return 3 * exp(3 * x);
}

double f111(double x) {
    return (2-6*x*x)/(pow((1+x*x),3));
}

double f222(double x) {
    return 9 * exp(3 * x);
}

vector<vector<double>> getTable(double a, double h, int m, double (*f)(double)) {
    cout << "\nИсходная таблично-заданная функция:\n" << endl;
    vector<vector<double>> ch(m, vector<double>(2));
    for (int i = 0; i < m; ++i) {
        ch[i][0] = a + i * h;
        ch[i][1] = f(ch[i][0]);
        cout << "x_" << i << " = " << fixed << setprecision(8) << ch[i][0]
             << ", f(x_" << i << ") = " << ch[i][1] << endl;
    }
    cout << "\n";
    return ch;
}

double FirstDer1(const vector<vector<double>>& mas, int index) {
    if (index == 0) {
        return (-3 * mas[0][1] + 4 * mas[1][1] - mas[2][1]) / (2 * (mas[1][0] - mas[0][0]));
    } else if (index == mas.size() - 1) {
        return (3 * mas[mas.size() - 1][1] - 4 * mas[mas.size() - 2][1] + mas[mas.size() - 3][1]) / (2 * (mas[1][0] - mas[0][0]));
    } else {
        return (mas[index + 1][1] - mas[index - 1][1]) / (2 * (mas[1][0] - mas[0][0]));
    }
}

double FirstDer2(const vector<vector<double>>& mas, int index) {
    if (index == 0 || index == 1) {
        return (-25 * mas[index][1] + 48 * mas[index + 1][1] - 36 * mas[index + 2][1] + 16 * mas[index + 3][1] - 3 * mas[index + 4][1]) / (12 * (mas[1][0] - mas[0][0]));
    } else if (index == mas.size() - 1 || index == mas.size() - 2) {
        return (3 * mas[index - 4][1] - 16 * mas[index - 3][1] + 36 * mas[index - 2][1] - 48 * mas[index - 1][1] + 25 * mas[index][1]) / (12 * (mas[1][0] - mas[0][0]));
    } else {
        return (2 * (mas[index + 1][1] - mas[index - 1][1]) / (3 * (mas[1][0] - mas[0][0])) - (mas[index + 2][1] - mas[index - 2][1]) / (12 * (mas[1][0] - mas[0][0])));
    }
}

double SecondDer(const vector<vector<double>>& mas, int index) {
    if (index == 0) {
        return (2 * mas[0][1] - 5 * mas[1][1] + 4 * mas[2][1] - mas[3][1]) / pow((mas[1][0] - mas[0][0]), 2);
    } else if (index == mas.size() - 1) {
        return (2 * mas[mas.size() - 1][1] - 5 * mas[mas.size() - 2][1] + 4 * mas[mas.size() - 3][1] - mas[mas.size() - 4][1]) / pow((mas[1][0] - mas[0][0]), 2);
    } else {
        return (mas[index + 1][1] - 2 * mas[index][1] + mas[index - 1][1]) / pow((mas[1][0] - mas[0][0]), 2);
    }
}

double RumbFirstDer(const vector<vector<double>>& mas, int index, double (*f)(double)) {
    if (index == 0) {
        return (-3 * mas[0][1] + 4 * f((mas[0][0] + mas[1][0]) / 2) - mas[1][1]) / (mas[1][0] - mas[0][0]);
    } else if (index == mas.size() - 1) {
        return (3 * mas[mas.size() - 1][1] - 4 * f((mas[mas.size() - 2][1] + mas[mas.size() - 1][1]) / 2) + mas[mas.size() - 2][1]) / (mas[1][0] - mas[0][0]);
    } else {
        return (f((mas[index + 1][0] + mas[index][0]) / 2) - f((mas[index - 1][0] + mas[index][0]) / 2)) / (mas[1][0] - mas[0][0]);
    }
}

void glob() {
    cout << "Выберите для какой из функций будут произведены вычисления (1 или 2): ";
    int o;
    cin >> o;
    double (*f)(double) = (o == 1) ? f1 : f2;

    int m;
    cout << "Введите количество узлов не меньше 5: ";
    cin >> m;
    while (m < 5) {
        cout << "Недопустимое значение, введите заново: ";
        cin >> m;
    }

    cout << "Введите Начальное Значение a и Шаг h > 0: ";
    double a, h;
    cin >> a >> h;

    vector<vector<double>> mas = getTable(a, h, m, f);

    cout << "   x_i   |  f(x_i)  | f'(x_i)чд | AbsAcc1  | f'(x_i)чд | AbsAcc2  | f\"(x_i)чд | AbsAcc3  |" << endl;
    if (o == 1) {
        for (int i = 0; i < m; ++i) {
            cout << fixed << setprecision(RATE) << mas[i][0] << " | " << mas[i][1] << " | " << FirstDer1(mas, i) << "  | "
                 << abs(FirstDer1(mas, i) - f11(mas[i][0])) << " | " << FirstDer2(mas, i) << "  | "
                 << abs(FirstDer2(mas, i) - f11(mas[i][0])) << " | " << SecondDer(mas, i) << "  | "
                 << abs(SecondDer(mas, i) - f111(mas[i][0])) << " |" << endl;
        }
    }
    if (o == 2) {
        for (int i = 0; i < m; ++i) {
            cout << fixed << setprecision(RATE) << mas[i][0] << " | " << mas[i][1] << " | " << FirstDer1(mas, i) << "  | "
                 << abs(FirstDer1(mas, i) - f22(mas[i][0])) << " | " << FirstDer2(mas, i) << "  | "
                 << abs(FirstDer2(mas, i) - f22(mas[i][0])) << " | " << SecondDer(mas, i) << "  | "
                 << abs(SecondDer(mas, i) - f222(mas[i][0])) << " |" << endl;
        }
    }
}

void task_3main() {
    cout << " Нахождение производных таблично-заданной функции по формулам численного дифференцирования" << endl;
    cout << " Вариант 6" << endl << endl;
    while (true) {
        glob();
        cout << "Введите 0, если хотите завершить работу" << endl;
        cout << "Введите 1, если хотите перейти к уточнению по Рунге-Ромбергу" << endl;
        cout << "Введите 2, если хотите перейти к другой функции и вводу новых параметров" << endl;
        int p;
        cin >> p;
        if (p == 0) {
            break;
        }
        if (p == 1) {
            cout << "Выберите для какой из функций будут произведены вычисления (1 или 2) f1(x) = x^2/1+x^2    f2(x)= exp(1.5 * (var_mod % 5 + 1) * x): ";
            int o;
            cin >> o;
            double (*f)(double) = (o == 1) ? f1 : f2;

            int m;
            cout << "Введите количество узлов не меньше 5: ";
            cin >> m;
            while (m < 5) {
                cout << "Недопустимое значение, введите заново: ";
                cin >> m;
            }

            cout << "Введите Начальное Значение a и Шаг h > 0: ";
            double a, h;
            cin >> a >> h;

            vector<vector<double>> mas = getTable(a, h, m, f);

            cout << "Введите номер узла x_i для которого нужно уточнить производные: ";
            int n;
            cin >> n;

            double j1 = FirstDer1(mas, n);
            double j2 = RumbFirstDer(mas, n, f);
            double j = (4 * j2 - j1) / 3;

            cout << "     x_i    |   f(x_i)   |    J(h)    |  AbsAcc1  |   J(h/2)   |   AbsAcc2   |     J     |  AbsAcc3  |" << endl;
            if (o == 1) {
                cout << fixed << setprecision(RATE) << mas[n][0] << "  |  " << mas[n][1] << "  |  " << j1 << "  |   "
                     << abs(j1 - f11(mas[n][0])) << "|  " << j2 << "  |   " << abs(j2 - f11(mas[n][0])) << "  | "
                     << j << "  |  " << abs(j - f11(mas[n][0])) << " |" << endl;
            }
            if (o == 2) {
                cout << fixed << setprecision(RATE) << mas[n][0] << "  |  " << mas[n][1] << "  |  " << j1 << "  |   "
                     << abs(j1 - f22(mas[n][0])) << "|  " << j2 << "  |   " << abs(j2 - f22(mas[n][0])) << "  | "
                     << j << "  |  " << abs(j - f22(mas[n][0])) << " |" << endl;
            }
            break;
        } else {
            glob();
            break;
        }
    }
}


