//
// Created by krivonosovTi on 21.03.2024.
//
#include <iostream>
#include <string>
#include "task_1/task_1.h"
#include "task_2/task_2.h"
using namespace std;

void test()
{
        //interpolationByNewton();
        //task2_part1(-9, 1,1000,0.0000001,1);
        cout << endl << '\n';
        task2_part1(-9, 1,1000,0.00001,2);
        //task2_part2();
}

void interface()
{
    int task_num;

    while(true) {
        cout << "Номер задания: ";
        cin >> task_num;
        if (!task_num)
            return;
        switch (task_num) {
            case 1:
                interpolationByNewton();
                cout << endl;
                break;
            case 2:
                task2_main();
                cout << endl;
                break;
            default:
                cout << "Здача пока не решена :(";
                cout << endl << endl;
                break;
            }
    }
}
int main(){
interface();

 return 0;
}