#include "emplistsys.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printDash(int num) {
    for (int i = 0; i < num; i++)
    {
        printf("-");
    }
}
void printTableShape(){
    printf("+");
    printDash(5);
    printf("+");
    printDash(32);
    printf("+");
    printDash(32);
    printf("+");
    printDash(11);
    printf("+");
    printDash(4);
    printf("+");
    printf("\n");
}

emp_list* listConstractor(){
    emp_list * L = calloc(1,sizeof(emp_list));
    L->head = NULL;
    L->tail = NULL;
    L->size = 0;
    return L;
}


void addEmp(emp_list* empLi){
    //create new node
    system("cls");
    emp_node* newEmp = (emp_node*)malloc(1*sizeof(emp_node));
    if(newEmp == NULL)
    {
        printf("\n\n\n\t\t-------------> Employee Node not created <-------------\n");
        return;
    }
    printDash(90);
    printf("\n\t\t\t----------> Adding Employee <----------\n");
    printDash(90);
    printf("\n");
    //getting empolyee name
    //clear_input_buffer(); // Clear the input buffer before reading the next name
    char buffer[30];
    printf("\t=> Enter the name of employee : ");
    fflush(stdin);
    fgets(buffer, 30, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character from the string
    strncpy(newEmp->empData.name, buffer, 30); // Copy the string to the struct field
    fflush(stdin);
    //getting empolyee age
    printf("\n\t=> Enter the age of employee: ");
    scanf("%d", &newEmp->empData.age);
    while (newEmp->empData.age > 64 || newEmp->empData.age < 16)
    {
        printf("\t=> Invalid Age\n");
        printf("\t=> Enter Another Age from 17 to 64: ");
        scanf("%d", &newEmp->empData.age);
    }
    //getting empolyee ID
    printf("\t=> Enter the ID of employee: ");
    scanf("%d", &newEmp->empData.id);
    // int IDisNotInList = isID_NotInList(empLi, newEmp->empData.id);
    // int ID_Check = ( (newEmp->empData.id < 1) || (newEmp->empData.id > 999) );

    while ((newEmp->empData.id < 1) || (newEmp->empData.id > 999) || !isID_NotInList(empLi, newEmp->empData.id))
    {   
        printf("\t=> Invalid ID\n");
        if (!isID_NotInList(empLi, newEmp->empData.id))
        {
            printf("\t=> There is an Employee has the Same ID\n");
        }
        printf("\t=> Enter Another ID from 1 to 999: ");
        scanf("%d", &newEmp->empData.id);
    }
    //getting empolyee Salary
    printf("\t=> Enter the salary of employee from 100$/m to 20000$/m: ");
    scanf("%f", &newEmp->empData.salary);
    while (newEmp->empData.salary < 100 || newEmp->empData.salary > 20000)
    {
        printf("\t=> Invalid salary\n");
        printf("\t=> Enter Another salary from 100$/m to 20000$/m: ");
        scanf("%f", &newEmp->empData.salary);
    }
    clear_input_buffer(); // Clear the input buffer before reading the next name
    //getting empolyee tilte
    printf("\t=> Enter the title of employee : ");
    fflush(stdin);
    fgets(buffer, 30, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character from the string
    strncpy(newEmp->empData.title, buffer, 30); // Copy the string to the struct field
    fflush(stdin);
    clear_input_buffer(); // Clear the input buffer before reading the next name

    newEmp->next = NULL;
    newEmp->prev = NULL;

    if (empLi->head == NULL)
    {
        empLi->head = newEmp;
        empLi->tail = newEmp;
        empLi->size = 1;
        return;
    }
    
    emp_node * current = empLi->head;
    //to make the current points at the last node
    while (current->next !=NULL)
    {
        current = current->next;
    }
    //now current points at the last node 
    current->next = newEmp;
    newEmp->prev = current;
    current = newEmp;
    empLi->tail = current;
    empLi->size++;

}
//FUNCTION to search if ID in list
int isID_NotInList(emp_list* empLi, int id){
    if(empLi->head == NULL)
    {
        return 1;
    }
    emp_node* current = empLi->head;
    while (current !=NULL)
    {
        if (current->empData.id == id)
        {
            return 0;
        }
        current = current->next;
    }
    return 1;
}

//function to display show ALL employee from first entered to last
void empList_DisplayForward(emp_list * empLi)
{
    system("cls");
    if(empLi->head == NULL)
    {
        printf("\n\n\n\t\t\tTHERE is No employees In the LIST\n");
        printf("\n\n\t\t\t\t The list is Empty \n");
        return;
    }

    emp_node * current = empLi->head;
    //Printing here
    printDash(90);
    printf("\n\t\t\t----------> Employees Data <----------\n");
    printDash(90);
    printf("\n\n");
    printTableShape();
    printf("| ID  |%14s%s%14s|%13s%s%14s|  SALARY   |AGE |\n"," ","NAME"," "," ","TITLE"," ");
    printTableShape();
    
    while (current!=NULL)
    {
        printf("| %-3d ",current->empData.id);
        printf("| %-30s ",current->empData.name);
        printf("| %-30s ",current->empData.title);
        printf("| %-8.2f$ ",current->empData.salary);
        printf("| %-2d |",current->empData.age);
        current = current->next;
        printf("\n");
        printTableShape();
    }
    
}


//function to display show ALL employee from last entered to first
void empList_DisplayReverse(emp_list * empLi)
{
    system("cls");
    if(empLi->head == NULL)
    {
        printf("\n\n\n\t\t\tTHERE is No employees In the LIST\n");
        printf("\t\t\t\t The list is Empty \n");
        return;
    }

    emp_node * current = empLi->tail;
    //Printing here
    printDash(90);
    printf("\n\t\t\t----------> Employees Data <----------\n");
    printDash(90);
    printf("\n\n");
    printTableShape();
    printf("| ID  |%14s%s%14s|%13s%s%14s|  SALARY   |AGE |\n"," ","NAME"," "," ","TITLE"," ");
    printTableShape();
    while (current!=NULL)
    {
        printf("| %-3d ",current->empData.id);
        printf("| %-30s ",current->empData.name);
        printf("| %-30s ",current->empData.title);
        printf("| %-8.2f$ ",current->empData.salary);
        printf("| %-2d |",current->empData.age);
        current = current->prev;
        printf("\n");
        printTableShape();
    }
}

//function to free the employees list
void deleteAll(emp_list* empLi)
{
    system("cls");
    //check if the list is empty 
    if(empLi->head == NULL)
    {
        printf("\n\n\t\t\tTHERE is No employees In the LIST\n");
        printf("\t\t\t\t The list is Empty \n");
        return;
    }

    emp_node* current = empLi->tail;
    while (current!=NULL)
    {
        empLi->tail = empLi->tail->prev;
        free(current);
        empLi->size--;
        current = empLi->tail;
    }
    empLi->head= NULL;
    empLi->tail = NULL;
    printf("\n\n\t\t\t--------------> All List members were DELETED <--------------\n");
}

//function to search for an employee in a Employee list
void empSearch(emp_list * empLi)
{
    unsigned int id = 0;
    system("cls");
    if(empLi->head==NULL)
    {
        printf("\n\n\t\t\t--------------> Empty list <--------------\n\n");
        return;
    }
    int found = 0;
    
    printDash(90);
    printf("\n\t\t\t----------> Employee Data <----------\n");
    printDash(90);
    printf("\n\n");
    if (id == 0)
    {
        printf("\t=>Enter ID to search for: ");
        scanf("%d",&id);
        printDash(90);
    }
    printf("\n\n\t=>The data of Employee you search for with id : %d\n",id);
    emp_node * current = empLi->head;
    while (current!=NULL)
    {
        if(current->empData.id == id)
        {
            found = 1;
            break;
        }
        current = current->next;
    }
    
    if (found == 1)
    {
        // printing Empolyee data
        printf("\n");
        printTableShape();
        printf("| ID  |%14s%s%14s|%13s%s%14s|  SALARY   |AGE |\n"," ","NAME"," "," ","TITLE"," ");
        printTableShape();
        printf("| %-3d ",current->empData.id);
        printf("| %-30s ",current->empData.name);
        printf("| %-30s ",current->empData.title);
        printf("| %-8.2f$ ",current->empData.salary);
        printf("| %-2d |",current->empData.age);
        
        printf("\n");
        printTableShape();
    }else{
        printf("\n\n\n");
        printf("\t\t\t--------------> NOT FOUND <--------------\n");
    }

}

//function to edit node value
void editEmpData(emp_list * empLi)
{
    unsigned int id =0;
    system("cls");
    if(empLi->head==NULL)
    {
        printf("\n\n\t\t\tTHERE is No employees In the LIST\n");
        printf("\t\t\t\t The list is Empty \n");
        return;
    }
    int found =0;
    printf("\t=>Enter ID of Employee to edit his/her data: ");
    scanf("%d",&id);
    printDash(90);
    printf("\n\n");
    emp_node * current = empLi->head;
    while (current!=NULL)
    {
        if(current->empData.id == id)
        {
            found = 1;
            break;
        }
        current = current->next;
    }
    if(found == 0)
    {
        printf("\n\n\n");
        printf("\t\t\t--------------> NOT FOUND <--------------\n");
    }else{
        printf("\t=> Enter the new age of employee: ");
        scanf("%d", &current->empData.age);
        while (current->empData.age > 64 || current->empData.age < 16)
        {
            printf("\t=> Invalid Age\n");
            printf("\t=> Enter Another Age from 17 to 64: ");
            scanf("%d", &current->empData.age);
        }
        printf("\t=> Enter the New salary of employee from 100$ to 20000$: ");
        scanf("%f", &current->empData.salary);
        while (current->empData.salary < 100 || current->empData.salary > 20000)
        {
            printf("\t=> Invalid salary\n");
            printf("\t=> Enter Another salary from 100$ to 20000$: ");
            scanf("%d", &current->empData.salary);
        }
        clear_input_buffer(); // Clear the input buffer before reading the next name
        //getting new empolyee tilte
        char buffer[30];
        printf("\t=> Enter the new title of employee : ");
        fflush(stdin);
        fgets(buffer, 30, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // Remove the newline character from the string
        strncpy(current->empData.title, buffer, 30); // Copy the string to the struct field
        fflush(stdin);
        clear_input_buffer(); // Clear the input buffer before reading the next name
    }
}

//function to delete an Employee with a certain ID 
void delEmpWithID(emp_list * empLi)
{
    unsigned int id=0;
    system("cls");
    if(empLi->head==NULL)
    {
        printf("\n\n\t\t\tTHERE is No employees In the LIST\n");
        printf("\t\t\t\t The list is Empty \n");
        return;
    }
    printf("\t=>Enter ID of Employee to edit his/her data: ");
    scanf("%d",&id);
    printDash(90);
    printf("\n\n");
    emp_node * current = empLi->head;
    //check if the value at the first node 
    if(empLi->head->empData.id == id)
    {
        empLi->head = empLi->head->next;
        empLi->tail = NULL;
        free(current);
        empLi->size--;
        printf("\n\n\t\t\t--------------> Employee with ID %d was DELETED<--------------\n",id);
        return;
    }
    if (empLi->tail->empData.id == id)
    {   current = empLi->tail;
        empLi->tail = current->prev;
        empLi->tail->next = NULL;
        free(current);
        empLi->size--;
        printf("\n\n\t\t\t--------------> Employee with ID %d was DELETED<--------------\n",id);
        return;
    }
    system("cls");
    while (current->next!=NULL)
    {
        if(current->empData.id == id)
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            empLi->size--;
            printf("\n\n\t\t\t--------------> Employee with ID %d was DELETED <--------------\n",id);
            return;
        }
        current = current->next;  
    }

    printf("\n\n\n");
    printf("\t\t\t--------------> NOT FOUND <--------------\n");
    printf("\n\n\t\t\t--------------> DELETING DID NOT OCCURED <--------------\n");

}
