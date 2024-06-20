#include<iostream>
#include"./Headers/Task.h"
#include<fstream>


int main(){

    Task task1("hw","2024-8-8","desc");
    task1.list_task();

    Task task2("hw2","2024-9-9","desc2");
    task2.list_task();

    return 0;
}