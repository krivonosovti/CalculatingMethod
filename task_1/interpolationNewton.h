//
// Created by krivonosovTi on 21.03.2024.
//

#ifndef INTERPOLATIONNEWTON_INTERPOLATIONNEWTON_H
#define INTERPOLATIONNEWTON_INTERPOLATIONNEWTON_H
using  namespace  std;
bool inputData(int &NumValInTable, double &a,double &b, double &x,double &degree);
vector<pair<double, double>> buildFunctionValues(double a, double b, int numPoints);
double divide_difference(vector  <pair <double,double>>&  node, int k);
void vector_print(vector<pair<double, double>>& nodes);
double newton_polinominal(vector <pair <double,double>>& Table, double x,  vector <double>& div_diff);
double create_Newton_polinomial(vector <pair <double,double>>& Table, double x);
bool compare(const pair<double, double>& a, const pair<double, double>& b, const double& x);
void sortByDistance(vector<pair<double, double>>& Table, const double& x);
#endif //INTERPOLATIONNEWTON_INTERPOLATIONNEWTON_H