#include "../../util/utility.h"
#include "../function/function.h"
#include "../../model/student.h"

int isLarger(int numberOne, int numberTwo){

  if(numberOne == numberTwo) return 0;

  else if(numberOne > numberTwo) return 1;
  
  else return -1;
}

size_t structAmount(FILE *file, void *obj, size_t size){

  int counter = 0;

  while(fread(obj, size, 1, file) == 1){
      counter++;
  }
  rewind(file);

  return counter;
}
 
void textToUpper(char *string){ 

  for (int i = 0; i < strlen(string); i++){
    if (isalpha(string[i])){
      string[i] = toupper(string[i]);
    }
  }
}

char charToUpper(char ch){ 
  return toupper(ch);
}

int verifyNumber(char *string){
  int len = strlen(string);

  for (int i = 0; i < len; i++){
    if (isalpha(string[i]))
      return 0;
  }
  return 1;
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

void toPointer(void *pointer, size_t *nReg, size_t size, FILE *file){
  
  size_t fSize = 0;

  fseek(file, 0L, SEEK_END);
  fSize = ftell(file);
  (*nReg) = fSize/size;
  rewind(file);
  
  pointer = (void*) malloc(fSize);

  while(fread(&pointer, size, 1, file) == 1);

  fclose(file);
}