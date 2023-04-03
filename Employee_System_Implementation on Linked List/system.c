#include "system.h"
//----------------------PART2-----------------------------


void startSystem(emp_list* list){
    while (1)
    {
        char opt;
        system("cls");
        printf("\n");
        printDash(30);
        printf("\n%20s Welcom to employee system ^_^\n"," ");
        printf("\t\t\t\t");
        printDash(30);
        printf("\n");
        printf("\t=>Enter 1 for ADDING new Employee.\n");
        printf("\t=>Enter 2 for DELETE ALL Employees.\n");
        printf("\t=>Enter 3 for MODIFY DATA of Employee.\n");
        printf("\t=>Enter 4 for VIEW DATA of an Employee.\n");
        printf("\t=>Enter 5 for VIEW ALL Employee (1st entered to last).\n");
        printf("\t=>Enter 6 for VIEW ALL Employee (reversed printing of 5).\n");
        printf("\t=>Enter 7 for DELETE DATA of an Employee.\n");
        printf("\t=>Enter 8 for EXIT.\n");
        printDash(50);
        printf("\n");
        printf("\t=>Enter the Number of Your Option: ");
        getSpecificInput(&opt);
        operations(&opt, list);
        if (opt == '8')
        {
            break;
        } 
    }
}

void operations(char* opt, emp_list* list){
    switch (*opt)
    {
    case '1':
        addEmp(list);
        break;
    case '2':
        deleteAll(list);
        printf("\n");
        system("pause");
        break;
    case '3':
        editEmpData(list);
        system("pause");
        break;
    case '4':
        empSearch(list);
        system("pause");
        break;
    case '5':
        empList_DisplayForward(list);
        system("pause");
        break;
    case '6':
        empList_DisplayReverse(list);
        system("pause");
        break;
    case '7':
        delEmpWithID(list);
        system("pause");
        break;
    case '8':
        printf("\n\t\t\t ------------> Good By ^_^ <------------\n\n");
        system("pause");
        break;
    
    default:
        printf("\n\n\t\t\t-----------> Wrong Option <-----------\n");
        system("pause");
        break;
    }
}

void getSpecificInput(char* a){
    int count = 0;
    char in;
    while ( (in= getch()) != '\r') // "\r" mean pressing enter
    {
        switch (in) //only values will appear in screan y and n only
        {
        case '1':
            if (count<1)//this condition to enter only one char
            {
                putch(in);//print the ch value
                count++;
                *a = in;
            }
            break;
        case '2':
            if (count<1)//this condition to enter only one char
            {
                putch(in);//print the ch value
                count++;
                *a = in;
            }
            break;
        case '3':
            if (count<1)//this condition to enter only one char
            {
                putch(in);//print the ch value
                count++;
                *a = in;
            }
            break;
        case '4':
            if (count<1)//this condition to enter only one char
            {
                putch(in);//print the ch value
                count++;
                *a = in;
            }
            break;
        case '5':
            if (count<1)//this condition to enter only one char
            {
                putch(in);//print the ch value
                count++;
                *a = in;
            }
            break;
        case '6':
            if (count<1)//this condition to enter only one char
            {
                putch(in);//print the ch value
                count++;
                *a = in;
            }
            break;
        case '7':
            if (count<1)//this condition to enter only one char
            {
                putch(in);//print the ch value
                count++;
                *a = in;
            }
            break;
        case '8':
            if (count<1)//this condition to enter only one char
            {
                putch(in);//print the ch value
                count++;
                *a = in;
            }
            break;
        case '\b': // "\b" means backspace in keyboard
            if(count >0){
                //the next three commands to delete
                putch('\b');
                putch(' ');
                putch('\b');
                count--;
            }
            break;
        }
    }
}