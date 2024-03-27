//
// Created by krivonosovTi on 21.03.2024.
//

#ifndef INC_3COURSE_TASK_1_BASIC_FUNCTION_H
#define INC_3COURSE_TASK_1_BASIC_FUNCTION_H
using namespace std;
double func(double x);
bool inputData(int &NumValInTable, double &a,double &b, double &x,double &degree, int &err);
vector<pair<double, double>> buildFunctionValues(double a, double b, int numPoints);
void vector_print(vector<pair<double, double>>& nodes);
bool compare(const pair<double, double>& a, const pair<double, double>& b, const double& x) ;
void sortByDistance(vector<pair<double, double>>& Table, const double& x);

#endif //INC_3COURSE_TASK_1_BASIC_FUNCTION_H
