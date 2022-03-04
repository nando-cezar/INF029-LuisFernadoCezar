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

