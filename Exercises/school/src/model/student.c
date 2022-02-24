#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "student.h"

Student registerStudent(){

    size_t ln;
    Student student;

    printf("Inserir matricula: ");
    scanf("%d", &student.enrollment);

    printf("Inserir nome: ");
    fgets(student.name, MAX_NAME_LEN, stdin);
    ln = strlen(student.name) - 1;
    if (student.name[ln] == '\n')
      student.name[ln] = '\0';

    printf("Inserir CPF: ");
    fgets(student.CPF, MAX_CPF_LEN, stdin);
    ln = strlen(student.CPF) - 1;
    if (student.CPF[ln] == '\n')
      student.CPF[ln] = '\0';

    printf("Inserir data de nascimento: ");
    scanf("%d %d %d", 
    &student.birthDate.day, 
    &student.birthDate.month, 
    &student.birthDate.year);   

    printf("Inserir genero (M/F): ");
    scanf(" %c", &student.gender);

    return student;
}