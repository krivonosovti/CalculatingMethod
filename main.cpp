//
// Created by krivonosovTi on 21.03.2024.
//
#include <iostream>
#include <string>
#include "task_1/task_1.h"
#include "task_6/task6_main.h"
#include "task_5/task_5main.h"
//#include "task_2/task_2.h.txt"
#include "task_3/task_3_main.h"
#include "task_4/task_4main.h"
//#include "task_5/task_5main.h"
using namespace std;

void test()
{
        //interpolationByNewton(); //task1_main
//        task2_main();
//        cout << endl << '\n';
 //       task2_part1 (-100, 100, 1000100,  0.00001);
        //task2_part2();
  //     task_3main();
   // task_5main();
   task_5_sab2_main();
  //task6_main();
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
                //task2_main();
                cout << "Тут в txt файлках какая-то ошибка есть она меня заставила переделывать, но нужно переписать  task2_sab_2"<<endl;
                break;
            case 3:
                task_3main();
                cout << endl;
                break;
            case 4:
                task_4main();
                cout << endl;
                break;
            case 5:
                task_5_sab2_main();
                cout << "5.1 См Python \n";
                break;
            case 6:
                task6_main();
                cout << "5.1 См Python \n";
                break;
            default:
                cout << "Здача пока не решена :(";
                cout << endl << endl;
                break;
        }
    }
}
int main(){
//interface();
test();
 return 0;
}