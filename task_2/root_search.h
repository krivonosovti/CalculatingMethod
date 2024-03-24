//
// Created by krivonosovTi on 21.03.2024.
//

#ifndef INC_3COURSE_TASK_1_ROOT_SEARCH_H
#define INC_3COURSE_TASK_1_ROOT_SEARCH_H
double  six_var_func (double x);
int operation(double(*op)(double), double a);
void bisection(double A,  double B, const double error_rate, int& counter);
std::string root_div(double A, double B, int N, double error_rate, int type);
#endif //INC_3COURSE_TASK_1_ROOT_SEARCH_H
