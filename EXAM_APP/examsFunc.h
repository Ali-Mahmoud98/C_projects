//function to input the password and show * instead of password chars
void passFunc(char pass[]){
  char c;
  int i=0;
  while ( (c=getch()) != 13) //13 is ASCII of Enter
  {
    if (c == 0|| c==-32) // this code to ignore function keys and arrows
    {
      c = getch();
      continue;
    }
    if (c == 8) // ASCII if backspace
    {
      if (i>0)
      {
        printf("\b \b"); //cursor move back and replace final char with space
        //then move back without replace with space
        i--;
      }
    }else
    {
      if (c>=32 && c <=126) //range of chars and nums in keyboard
      {
        pass[i] = c;
        printf("*");
        i++;
      }

    }

  }
  pass[i] = '\0'; //to tell compiler this is the end of string

}
//end password function

//checking function
int checkUser(char user[], char pass[]){
  FILE* fp;
  fp = fopen("users.txt","r"); //read data from file users.txt
  char* token;
  int fieldNum=0;
  char line[200];
  char curUser[20];
  char curPass[20];

  while (fgets(line,sizeof(line),fp) != NULL) //if found line the program will retain this line in variable line
  {
    //code will excute after finding line of string
    token = strtok(line,","); //when you find "," in the line-> get the word before "," then put it into token
    while (token != NULL) //looping in same line
    {
      fieldNum++; // if fieldNum==1 then the code red
      switch (fieldNum)
      {
      case 1:
        strcpy(curUser, token);//put the value string of token in curUser
        break;
      case 2:
        strcpy(curPass,token);
        break;
      }
      token = strtok(NULL,",\n");//used null to search from final search point
      //search for "," or "\n"
      //according the file when the program found "\n" then the value of token will be null
    }
    fieldNum =0;
    if ( (strcmp(curUser, user) ==0) && (strcmp(curPass, pass)==0) )
    {
      fclose(fp);
      return 1;
    }


  }
  fclose(fp);
  return 0;
}
//end of checking function

// start:exam code for each user function
void loadExams(char user[]){
  struct exams curRec;
  struct exams resExams[5];
  FILE* fp = fopen("ExamsStatus.txt","r");

  char* token;
  int i=0;
  char line[200];
  int recNum=0;
  int fieldNum=0;

  if (fp!= NULL)
  {
    while (fgets(line,sizeof(line),fp) != NULL)
    {
      recNum++;
      token = strtok(line,",");
      while (token != NULL) //looping in same line
      {
        fieldNum++;
        switch (fieldNum)
        {
          case 1:
            curRec.examNum = atoi(token);
            break;
          case 2:
            strcpy(curRec.userCode, token);
            break;
          case 3:
            strcpy(curRec.examDate, token);
            break;
          case 4:
            strcpy(curRec.examCode, token);
            break;
          case 8:
            curRec.examStatus = atoi(token);
            break;
        }
        token = strtok(NULL,",\n");
      }
      //curRec.examName = getExameName(curRec.examCode);
      if (strcmp(curRec.userCode, user) == 0)
      {
        resExams[i] = curRec;
        i++;
      }
      
      fieldNum =0;
    }
    numOfExams = i;
    printf("\nNumber of exams is %d for user %s",numOfExams,user);
    for (int j = 0; j < i; j++)
    {
      printf("\nThe exam code is: %s and Exam date is: %s with status is %d\n",resExams[j].examCode,resExams[j].examDate,resExams[j].examStatus);
    }
    
    fclose(fp);
  }
  
}
// end:exam code for each user function