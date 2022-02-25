#include "../util/utility.h"
#include "interface/discipline.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

Discipline registerDiscipline(){

    size_t ln;
    Discipline discipline;

    printf("Inserir codigo: ");
    scanf("%d", &discipline.code);

    printf("Inserir nome: ");
    fgets(discipline.name, MAX_NAME_LEN, stdin);
    ln = strlen(discipline.name) - 1;
    if (discipline.name[ln] == '\n')
      discipline.name[ln] = '\0';

    printf("Inserir semestre: ");
    scanf("%d", &discipline.semester);

    printf("Inserir professor: ");
    // find teacher

    return discipline;
}