#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/student.h"
#include "../model/teacher.h"
#include "../model/discipline.h"
#include "../model/menu.h"

void printDiscipline(Discipline discipline, Teacher teacher){

  printf("\n");
  printf("Código:   \t %s\n", discipline.code);
  printf("Nome:     \t %s\n", discipline.name);
  printf("Semestre: \t %d\n", discipline.semester);
  printf("Professor: \t %s (%s)\n", teacher.name, teacher.enrollment);
  printf ("***********************************************\n");

}

void printSummaryDiscipline(Discipline discipline, Teacher teacher){

  printf("\n");
  printf(
    "Código: %s - Nome: %s - Prefessor: %s (%s)\n", 
    discipline.code, 
    discipline.name, 
    teacher.name, 
    teacher.enrollment
  );
  printf ("***********************************************\n");

}

Discipline insertDiscipline(Discipline discipline){
  
  size_t ln;
  int verification;

  //.code
  do{
    printf("Inserir o código da disciplina: ");
    fgets(discipline.code, MAX_ENR_LEN, stdin);
    removeBreakLine(discipline.code);
    
    verification = isExistingDiscipline(discipline.code);

    if(!verification)
      printf("\nO código informado já existe!\n");
    else{
      removeSpace(discipline.code);
      textToUpper(discipline.code);
    }

  }while(!verification);
  //.name
  printf("Inserir o nome da disciplina: ");
  fgets(discipline.name, MAX_NAME_LEN, stdin);
  removeBreakLine(discipline.name);
  textToUpper(discipline.name);

  //.semester
  printf("Inserir o semestre: ");
  scanf("%d", &discipline.semester);
  getchar();

  //.teacher
  printf("Selecione o professor desejado... \n");

  return discipline;
}

void mainDiscipline(){

  int option;

  setlocale(LC_ALL, "Portuguese");

  do{
    header();
    printf("1. Inserir disciplina;\n"); // OK
    printf("2. Inserir aluno na disciplina;\n"); // OK
    printf("3. Listar disciplinas;\n"); // OK
    printf("4. Listar disciplina e seus alunos;\n"); // OK
    printf("5. Listar disciplinas com mais de 40 alunos;\n");
    printf("6. Atualizar disciplina;\n"); // OK
    printf("7. Excluir disciplina;\n"); // OK
    printf("8. Remover aluno da disciplina;\n"); // Em desenvolvimento
    printf("9. Retornar ao menu principal;\n"); // OK
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();


    switch (option){
    case 1: createDiscipline(); break;
    case 2: insertStudentInDiscipline(); break;
    case 3: retrieveDiscipline(); break;
    case 4: retrieveDisciplineWithStudent(); break;
    case 5: break;
    case 6: updateDiscipline(); break;
    case 7: deleteDiscipline(); break;
    case 8: deleteStudentInDiscipline(); break;
    case 9: break;
    default:
      printf("Opção inválida!\n"); 
      getchar();
      break;
    }
  }while(option != 9);

}


 