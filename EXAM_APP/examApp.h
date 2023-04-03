#ifndef EXAM_APP_H_
#define EXAM_APP_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct exams
{
  int examNum;
  char userCode[20];
  char examCode[20];
  char examDate[11];
  char examName[50];
  int examStatus;
};

void passFunc(char pass[]);
int checkUser(char user[], char pass[]);
void loadExams(char user[]);


#endif
