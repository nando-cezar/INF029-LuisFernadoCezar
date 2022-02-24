#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../school/src/util/utility.h"
#include "../school/src/model/interface/teacher.h"

Teacher registerTeacher(){

    size_t ln;
    Teacher teacher;
    
    printf("Inserir matricula: ");
    scanf("%d", &teacher.enrollment);

    printf("Inserir nome: ");
    fgets(teacher.name, MAX_NAME_LEN, stdin);
    ln = strlen(teacher.name) - 1;
    if (teacher.name[ln] == '\n')
      teacher.name[ln] = '\0';

    printf("Inserir CPF: ");
    fgets(teacher.CPF, MAX_CPF_LEN, stdin);
    ln = strlen(teacher.CPF) - 1;
    if (teacher.CPF[ln] == '\n')
      teacher.CPF[ln] = '\0';

    printf("Inserir data de nascimento: ");
    scanf("%d %d %d", 
    &teacher.birthDate.day, 
    &teacher.birthDate.month, 
    &teacher.birthDate.year);   

    printf("Inserir genero (M/F): ");
    scanf(" %c", &teacher.gender);

    return teacher;
}