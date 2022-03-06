#include "../util/utility.h"
#include "../model/discipline.h"
#include "../model/menu.h"

void printDiscipline(Discipline discipline){

  printf("\n");
  printf("Código:   \t\t %s\n", discipline.code);
  printf("Nome:     \t\t %s\n", discipline.name);
  printf("Semestre: \t %d\n", discipline.semester);
  printf ("\n***********************************************\n\n");

}

Discipline insertDiscipline(Discipline discipline){
  
  size_t ln;
  int verification;

  //.code
  printf("Insira o código da disciplina: ");
  fgets(discipline.code, MAX_ENR_LEN, stdin);
  ln = strlen(discipline.code) - 1;
  if (discipline.code[ln] == '\n')
    discipline.code[ln] = '\0';
  textToUpper(discipline.code, strlen(discipline.code));

  
  //.name
  printf("Insira o nome da disciplina: ");
  fgets(discipline.name, MAX_NAME_LEN, stdin);
  ln = strlen(discipline.name) - 1;
  if (discipline.name[ln] == '\n')
    discipline.name[ln] = '\0';
  textToUpper(discipline.name, strlen(discipline.name));


  //.semester
  printf("Insira o semestre: ");
  scanf("%d", &discipline.semester);
  getchar();

  return discipline;
}

void mainDiscipline(){

  int option;

  setlocale(LC_ALL, "Portuguese");

  do{
    header();
    printf("1. Inserir disciplina;\n");
    printf("2. Inserir aluno na disciplina;\n");
    printf("3. Listar disciplinas;\n");
    printf("4. Listar disciplina e seus alunos;\n");
    printf("5. Listar disciplinas com mais de 40 alunos;\n");
    printf("6. Atualizar disciplina;\n");
    printf("7. Excluir disciplina;\n");
    printf("8. Remover aluno da disciplina;\n");
    
    printf("9. Retornar ao menu principal;\n\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();


    switch (option){
    case 1: createDiscipline(); break;
    case 2: break;
    case 3: retrieveDiscipline(); break;
    case 4: break;
    case 5: break;
    case 6: break;
    case 7: deleteDiscipline(); break;
    case 8: break;
    case 9: break;
    default:
      printf("Opção inválida!\n"); 
      getchar();
      break;
    }
  }while(option != 9);

}


