#include "examApp.h"

void main(void){

  char user[20];
  char pass[20];

  printf("Enter your user code: ");
  scanf("%s", user);
  printf("Enter your password: ");
  passFunc(pass);
  printf("user code : %s\t password : %s\n",user,pass); //used to check password function

  if(checkUser(user, pass) == 1){
    loadExams(user);
  }else
  {
    printf("Invalid user code or password\n");
  }

}