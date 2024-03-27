//
// Created by krivonosovTi on 23.03.2024.
//

#include "reverse_interpolation.h"
#include "/Users/krivonosovti/SPbU/3course/task_1/implementation.cpp"
#include "/Users/krivonosovti/SPbU/3course/basic_function.h"
#include <iostream>
using namespace std;


double reverse_interpolation_1(vector <pair <double,double>>& Table, double x){

    for(auto& pair : Table) {
        std::swap(pair.first, pair.second);
    }
    sortByDistance(Table, x);
    cout << endl;

    vector_print(Table);

    return create_Newton_polinomial(Table, x);
}

double reverse_interpolation_2()
{
     return 0;
     //create_Newton_polinomial( )
}
