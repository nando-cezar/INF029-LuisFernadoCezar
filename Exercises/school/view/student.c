#include "../util/utility.h"
#include "../util/validation.h"
#include "../model/menu.h"
#include "../model/student.h"

void printStudent(Student student){

  printf("Matricula: %s\n", student.enrollment);
  printf("Nome: %s\n", student.name);
  printf("CPF: %s\n", student.CPF);
  printf("Data de nascimento: %d/%d/%d\n", 
  student.birthDate.day,
  student.birthDate.month,
  student.birthDate.year
  );
  printf("Gênero: %c\n", student.gender);
  printf ("\n***********************************************\n\n");

}

Student insertStudent(Student student){

  size_t ln;
  int verification;

  do{
    printf("Inserir matricula: ");
    fgets(student.enrollment, MAX_ENR_LEN, stdin);
    ln = strlen(student.enrollment) - 1;
    if (student.enrollment[ln] == '\n')
      student.enrollment[ln] = '\0';

    verification = validateEnrollment(student.enrollment);

    if(!verification)
      printf("\nInforme um número de matricula valido!\n\n");

  }while (!verification);
      
      

  do{  

    printf("Inserir nome: ");
    fgets(student.name, MAX_NAME_LEN, stdin);
    ln = strlen(student.name) - 1;
    if (student.name[ln] == '\n')
        student.name[ln] = '\0';
      
    verification = validateName(student.name);

    if(!verification)
      printf("\nInforme nome valido!\n\n");
  
  }while(!verification);

    
  do{

    printf("No padrão (###.###.###-##)\nInserir CPF: ");
    fgets(student.CPF, MAX_CPF_LEN, stdin);
    ln = strlen(student.CPF) - 1;
    if (student.CPF[ln] == '\n')
      student.CPF[ln] = '\0';

    verification = validateCPF(student.CPF);

    if(!verification)
      printf("\nInforme CPF valido!\n\n");
    
  }while(!verification);
   
  do{

    printf("No padrão (## ## ####)\nInserir data de nascimento: ");
    scanf("%d %d %d", 
    &student.birthDate.day, 
    &student.birthDate.month, 
    &student.birthDate.year);   

    getchar();
 
    verification = validateDate(student.birthDate);

    if(!verification){
      printf("\ndigite uma data valida!!!\n\n");
    }

    }while (!verification);

    do{
      printf("Inserir gênero (M/F): ");
      scanf(" %c", &student.gender);
      getchar();
      
      verification = validateGender(student.gender);

      if(!verification){
        printf("\ndigite uma gênero valida!!!\n\n");
      }

    }while(!verification);

  return student;
}

void mainStudent(){

  int option;

  do{
    header();
    printf("1. Inserir estudante;\n");
    printf("2. Listar estudantes;\n");
    printf("3. Listar estudantes por sexo (M/F);\n");
    printf("4. Listar estudantes ordenados por nome;\n");
    printf("5. Listar estudantes ordenados data de nascimento;\n");
    printf("6. Aniversariantes do mês;\n");
    printf("7. Atualizar estudante;\n");
    printf("8. Excluir estudante;\n");
    printf("9. Retornar ao menu principal;\n\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:createStudent();break;
      case 2:retrieveStudent();break;
      case 3:retrieveStudentByGender();break;
      case 4:sortStudentByName();break; //implementing
      case 5:sortStudentByBirthDate();break; //implementing
      case 6:birthdaysOfTheMonth();break;
      case 7:updateStudent();break;
      case 8:deleteStudent();break;
      case 9: break;
      default: 
        printf("Opção inválida!\n"); 
        getchar();
        break;
    }
  }while(option != 9);

}