#ifndef EMPLISTSYS_H
#define EMPLISTSYS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
    char name[30];
    char title[30];
    int age;
    int id;
    float salary;
}data;

typedef struct Employee{
    data empData;
    struct Employee* next;
    struct Employee* prev;
}emp_node;

typedef struct linkedList
{
    int size;
    emp_node* head;
    emp_node* tail;
}emp_list;

void clear_input_buffer();
void printDash(int num);

emp_list* listConstractor();
void addEmp(emp_list* empLi);
void empList_DisplayForward(emp_list * empLi);
void empList_DisplayReverse(emp_list * empLi);
void deleteAll(emp_list* empLi);
void empSearch(emp_list * empLi);
void editEmpData(emp_list * empLi);
void delEmpWithID(emp_list * empLi);
//FUNCTION to search if ID in list
int isID_NotInList(emp_list* empLi, int id);

#endif