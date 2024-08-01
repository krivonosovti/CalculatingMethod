//
// Created by krivonosovTi on 21.03.2024.
//

#ifndef INTERPOLATIONNEWTON_INTERPOLATIONNEWTON_H
#define INTERPOLATIONNEWTON_INTERPOLATIONNEWTON_H
using  namespace  std;
double divide_difference(vector  <pair <double,double>>&  node, int k);
double newton_polinominal(vector <pair <double,double>>& Table, double x,  vector <double>& div_diff);
double create_Newton_polinomial(vector <pair <double,double>>& Table, double x, double degree);
#endif //INTERPOLATIONNEWTON_INTERPOLATIONNEWTON_H