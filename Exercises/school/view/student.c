#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/student.h"
#include "../model/menu.h"

void printStudent(Student student){

  printf("\n");
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
      printf("\nInforme um número de matricula válido!\n\n");

  }while (!verification);
      
  do{  

    printf("Inserir nome: ");
    fgets(student.name, MAX_NAME_LEN, stdin);
    ln = strlen(student.name) - 1;
    if (student.name[ln] == '\n')
        student.name[ln] = '\0';
      
    verification = validateName(student.name);

    if(!verification)
      printf("\nInforme nome válido!\n\n");
    else  
      textToUpper(student.name, strlen(student.name));
  
  }while(!verification);

  do{

    printf("No padrão (###.###.###-##)\nInserir CPF: ");
    fgets(student.CPF, MAX_CPF_LEN, stdin);
    ln = strlen(student.CPF) - 1;
    if (student.CPF[ln] == '\n')
      student.CPF[ln] = '\0';

    verification = validateCPF(student.CPF);

    if(!verification)
      printf("\nInforme CPF válido!\n\n");
    
  }while(!verification);
   
  do{

    printf("No padrão (## ## ####)\nInserir data de nascimento: ");
    scanf("%d %d %d", 
    &student.birthDate.day, 
    &student.birthDate.month, 
    &student.birthDate.year);   

    getchar();
 
    verification = validateDate(student.birthDate);

    if(!verification)
      printf("\nInforme data válida!\n\n");

  }while (!verification);

  do{
    printf("Inserir gênero (M/F): ");
    scanf(" %c", &student.gender);
    getchar();
    
    verification = validateGender(student.gender);

    if(!verification)
      printf("\nInforme gênero válido!\n\n");

  }while(!verification);

  return student;
}

void mainStudent(){

  int option;

  setlocale(LC_ALL, "Portuguese");

  do{
    header();
    printf("1. Inserir estudante;\n");
    printf("2. Listar estudantes;\n");
    printf("3. Pesquisar estudantes por sexo (M/F);\n");
    printf("4. Pesquisar estudantes por nome;\n");
    printf("5. Listar estudantes ordenados por nome;\n");
    printf("6. Listar estudantes ordenados data de nascimento;\n");
    printf("7. Aniversariantes do mês;\n");
    printf("8. Atualizar estudante;\n");
    printf("9. Excluir estudante;\n");
    printf("10.Retornar ao menu principal;\n\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:  createStudent();break;
      case 2:  retrieveStudent();break;
      case 3:  retrieveStudentByGender();break;
      case 4:  retrieveStudentByName();break;
      case 5:  sortStudentByName();break;
      case 6:  sortStudentByBirthDate();break; 
      case 7:  birthdaysOfTheMonthStudent();break;
      case 8:  updateStudent();break;
      case 9:  deleteStudent();break;
      case 10: break;
      default: 
        printf("Opção inválida!\n"); 
        getchar();
        break;
    }
  }while(option != 10);

}