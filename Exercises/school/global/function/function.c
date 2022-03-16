#include "../../util/utility.h"
#include "../function/function.h"
#include "../../model/student.h"

int isLarger(int numberOne, int numberTwo){

  if(numberOne == numberTwo) return 0;

  else if(numberOne > numberTwo) return 1;
  
  else return -1;
}
 
void textToUpper(char *string){ 

  for (int i = 0; i < strlen(string); i++){
    if (isalpha(string[i])){
      string[i] = toupper(string[i]);
    }
  }
}

void removeBreakLine(char *string){
  
  size_t index = strlen(string) - 1;
  if (string[index] == '\n')
    string[index] = '\0';
}

void removeSpace(char *string){

  char *array = (char*) calloc(strlen(string), sizeof(char));

  for (int i = 0, j = 0; i < strlen(string); i++, j++){
    if (!isspace(string[i])){
      array[j] = string[i];
    }
  }

  strcpy(string, array);
  free(array);
}
