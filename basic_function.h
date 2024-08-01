//
// Created by krivonosovTi on 21.03.2024.
//

#ifndef INC_3COURSE_TASK_1_BASIC_FUNCTION_H
#define INC_3COURSE_TASK_1_BASIC_FUNCTION_H
using namespace std;
double main_func(double x);
double func(double x);
bool inputData(int &NumValInTable, double &a,double &b, int &err);
vector<pair<double, double>> buildFunctionValues(double a, double b, int numPoints);
void vector_print(vector<pair<double, double>>& nodes);
void sortByDistanceFromX(vector<pair<double, double>>& nodes, double x);
vector<pair<double, double>> buildFunctionValues_2 (double a, double b, int numPoints, double (*func)(double));
#endif //INC_3COURSE_TASK_1_BASIC_FUNCTION_H
