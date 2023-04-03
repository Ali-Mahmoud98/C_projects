# include "system.h"

void main(){
    emp_list* list = listConstractor();
    startSystem(list);
    free(list);
}

