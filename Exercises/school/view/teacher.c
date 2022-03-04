#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../model/teacher.h"
#include "../model/menu.h"

void printTeacher(Teacher teacher){

  printf("Matricula: %s\n", teacher.enrollment);
  printf("Nome: %s\n", teacher.name);
  printf("CPF: %s\n", teacher.CPF);
  printf("Data de nascimento: %d/%d/%d\n", 
  teacher.birthDate.day,
  teacher.birthDate.month,
  teacher.birthDate.year
  );
  printf("Gênero: %c\n", teacher.gender);
  printf ("\n***********************************************\n\n");

}

Teacher insertTeacher(Teacher teacher){

  size_t ln;
  int verification;

  do{
    printf("Inserir matricula: ");
    fgets(teacher.enrollment, MAX_ENR_LEN, stdin);
    ln = strlen(teacher.enrollment) - 1;
    if (teacher.enrollment[ln] == '\n')
      teacher.enrollment[ln] = '\0';

    verification = validateEnrollment(teacher.enrollment);

    if(!verification)
      printf("\nInforme um número de matricula valido!\n\n");

  }while (!verification);
      
      

  do{  

    printf("Inserir nome: ");
    fgets(teacher.name, MAX_NAME_LEN, stdin);
    ln = strlen(teacher.name) - 1;
    if (teacher.name[ln] == '\n')
        teacher.name[ln] = '\0';
      
    verification = validateName(teacher.name);

    if(!verification)
      printf("\nInforme nome valido!\n\n");
  
  }while(!verification);

    
  do{

    printf("No padrão (###.###.###-##)\nInserir CPF: ");
    fgets(teacher.CPF, MAX_CPF_LEN, stdin);
    ln = strlen(teacher.CPF) - 1;
    if (teacher.CPF[ln] == '\n')
      teacher.CPF[ln] = '\0';

    verification = validateCPF(teacher.CPF);

    if(!verification)
      printf("\nInforme CPF valido!\n\n");
    
  }while(!verification);
   
  do{

    printf("No padrão (## ## ####)\nInserir data de nascimento: ");
    scanf("%d %d %d", 
    &teacher.birthDate.day, 
    &teacher.birthDate.month, 
    &teacher.birthDate.year);   

    getchar();
 
    verification = validateDate(teacher.birthDate);

    if(!verification){
      printf("\ndigite uma data valida!!!\n\n");
    }

    }while (!verification);

    do{
      printf("Inserir gênero (M/F): ");
      scanf(" %c", &teacher.gender);
      getchar();
      
      verification = validateGender(teacher.gender);

      if(!verification){
        printf("\ndigite uma gênero valida!!!\n\n");
      }

    }while(!verification);

  return teacher;
}

void mainTeacher(){

  int option;

  do{
    header();
    printf("1. Inserir professor;\n");
    printf("2. Listar professores;\n");
    printf("3. Listar professores por sexo (M/F);\n");
    printf("4. Listar professores ordenados por nome;\n");
    printf("5. Listar professores ordenados data de nascimento;\n");
    printf("6. Aniversariantes do mês;\n");
    printf("7. Atualizar professor;\n");
    printf("8. Excluir professor;\n");
    printf("9. Retornar ao menu principal;\n\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:createTeacher();break;
      case 2:retrieveTeacher();break;
      case 3:retrieveTeacherByGender();break;
      case 4:sortTeacherByName();break;
      case 5:sortTeacherByBirthDate();break;
      case 6:birthdaysOfTheMonthTeacher();break;
      case 7:updateTeacher();break;
      case 8:deleteTeacher();break;
      case 9: break;
      default: 
        printf("Opção inválida!\n"); 
        getchar();
        break;
    }
  }while(option != 9);

}