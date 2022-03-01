#include "../util/utility.h"
#include "../model/discipline.h"

void createDiscipline(){

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

    //return discipline;
}

void mainDiscipline(){

  //header();

  //setlocale(LC_ALL, "Portuguese");
}