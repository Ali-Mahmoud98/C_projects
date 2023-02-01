#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "examsFunc.h"

//when you input header file between "<" and ">" the compiler search for the header file inside the compiler
//is the header file between double quotations then you tell the comipler there is header file created with name entered to include 

void passFunc(char pass[]);
int checkUser(char user[], char pass[]);
void loadExams(char user[]);

int numOfExams=0;

struct exams
{
  int examNum;
  char userCode[20];
  char examCode[20];
  char examDate[11];
  char examName[50];
  int examStatus;
};


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