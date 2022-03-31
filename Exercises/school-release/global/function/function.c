#include "../../util/utility.h"
#include "../function/function.h"
#include "../../model/student.h"
#include "../../model/teacher.h"

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

  for (int i = 0, j = 0; i < strlen(string); i++){
    if (!isspace(string[i])){
      array[j] = string[i];
      j++;
    }
  }

  strcpy(string, array);
  free(array);
}

void removeZero(char* string){
  
  if(string[0] == '0' ){
    
    char *array = (char*) calloc(strlen(string), sizeof(char));
    int validation = 0;

    for (int i = 0, j = 0; i < strlen(string); i++){

      if ( string[i] != '0' || validation){
        array[j] = string[i];
        j++;
        validation =1;
      }
    }

    strcpy(string, array);
    free(array);

  }

}