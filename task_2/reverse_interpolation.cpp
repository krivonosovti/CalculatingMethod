//
// Created by krivonosovTi on 27.03.2024.
//


#include <utility>
#include <iostream>
#include "/Users/krivonosovti/SPbU/3course/basic_function.h"
#include "/Users/krivonosovti/SPbU/3course/task_1/interpolationNewton.h"
#include "reverse_interpolation.h"
#include "/Users/krivonosovti/SPbU/3course/task_2/root_search.h"
using namespace std;

double reverse_interpolation_1(vector <pair <double,double>>& Table, double x){

    //мотонна от на отрезках R+ and R-

    for(auto& pair : Table) {
        std::swap(pair.first, pair.second);
    }

    sortByDistance(Table, x);

    cout << endl;

    vector_print(Table);

    return create_Newton_polinomial(Table, x);
}

double reverse_interpolation_2(double A, double B, double N,double error_rate, int type, vector<pair <double, double>>& Table)
{


        if(N < 2) {
            cout << " N<2 exeption";
            return NULL;
        }

        string result = " ";
        int counter = 0;
        int m = 0;
        double H = (B-A)/N;
        double X1 = A, X2 = X1+H, Y1 = operation(create_Newton_polinomial, X1), Y2 = 0.0;
        vector <pair <double,double>> RES;
        while(X2 <= B)
        {
            if(X1 == -8.28);
            Y2 = operation(six_var_func,X2);

            if (Y1*Y2<=0)
            {
                counter++;
                if (type == 1)
                    RES.push_back(correction(bisection, X1, X2, error_rate, m));
                else
                    RES.push_back(correction(pruner, X1, X2, error_rate, m));

                result += "["+ to_string(X1) + ' ' + to_string(X2) + "]  ";
            }

            X1 = X2;
            X2 = X1 + H;
            Y1 = Y2;

        }

        result += ' '+to_string(counter);
        cout << "Колличество шагов: " << m << endl;
        print_result_from_vector (RES);
        if (type == 1)
            cout  << "[ai,bi] = " << abs(X2-X1) << endl;

        return result ;

}