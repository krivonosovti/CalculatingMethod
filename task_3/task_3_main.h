//
// Created by krivonosovTi on 24.03.2024.
//

#ifndef INC_3COURSE_TASK_3_TASK_3_MAIN_H
#define INC_3COURSE_TASK_3_TASK_3_MAIN_H
using namespace std;

double f1(double x);

double f2(double x);

double f11(double x) ;

double f22(double x) ;

double f111(double x) ;
double f222(double x);

vector<vector<double>> getTable(double a, double h, int m, double (*f)(double));
double FirstDer1(const vector<vector<double>>& mas, int index);

double FirstDer2(const vector<vector<double>>& mas, int index) ;
double SecondDer(const vector<vector<double>>& mas, int index) ;

double RumbFirstDer(const vector<vector<double>>& mas, int index, double (*f)(double)) ;
void glob() ;
void task_3main();
#endif //INC_3COURSE_TASK_3_TASK_3_MAIN_H
