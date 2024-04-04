//
// Created by krivonosovTi on 21.03.2024.
//

#ifndef INC_3COURSE_TASK_2_ROOT_SEARCH_H
#define INC_3COURSE_TASK_2_ROOT_SEARCH_H
double  six_var_func (double x);
int operation(double(*op)(double), double a);
std::string root_div(double A, double B, int N, double error_rate, int type);
pair<double, double> bisection(double A,  double B, const double error_rate, int &con );
pair<double, double>  pruner (double A,  double B, const double error_rate, int& counter);
pair<double, double> correction (pair <double, double> (*op) (double A, double B, double error_rate, int& counter), double A, double B, double error_rate, int& counter );
#endif //INC_3COURSE_TASK_2_ROOT_SEARCH_H
