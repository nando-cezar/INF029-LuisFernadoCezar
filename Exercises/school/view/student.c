#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/student.h"
#include "../model/menu.h"

void printStudent(Student student){

  printf("\n");
  printf("Matricula: \t\t %s\n", student.enrollment);
  printf("Nome: \t\t\t %s\n", student.name);
  printf("CPF: \t\t\t %s\n", student.CPF);
  printf("Data de nascimento: \t %d/%d/%d\n", 
  student.birthDate.day,
  student.birthDate.month,
  student.birthDate.year
  );
  printf("Gênero: \t\t %c\n", student.gender);
  if(strcmp(student.disciplineCode[0], "\0") != 0)
    printf("Disciplinas: \n");
  for(int i = 0; strcmp(student.disciplineCode[i], "\0") != 0; i++){
    printf("%d. %s\n", i+1, student.disciplineCode[i]);
  }
  printf ("***********************************************\n");

}

void printSummaryStudent(Student student){

  printf("\n");
  printf("Matricula: %s - Nome: %s\n", student.enrollment, student.name);
  printf ("***********************************************\n");

}

Student insertCreateStudent(Student student){

  size_t ln;
  int verification, verificationStudent;

  do{
    printf("Inserir matricula: ");
    fgets(student.enrollment, MAX_ENR_LEN, stdin);
    removeBreakLine(student.enrollment);
    removeZero(student.enrollment);

    verification = validateEnrollment(student.enrollment);
    verificationStudent = isExistingStudent(student.enrollment);

    if(!verification)
      printf("\nInforme um número de matricula válido!\n");
    else if(!verificationStudent)
      printf("\nO número de matricula já existe!\n");
    else{
      removeSpace(student.enrollment);
      textToUpper(student.enrollment);
    }

  }while (!verification || !verificationStudent);
      
  do{  

    printf("Inserir nome: ");
    fgets(student.name, MAX_NAME_LEN, stdin);
    removeBreakLine(student.name);
      
    verification = validateName(student.name);

    if(!verification)
      printf("\nInforme nome válido!\n");
    else
      textToUpper(student.name);
  
  }while(!verification);

  do{

    printf("No padrão (###.###.###-##)\nInserir CPF: ");
    fgets(student.CPF, MAX_CPF_LEN, stdin);
    removeBreakLine(student.CPF);

    verification = validateCPF(student.CPF);

    if(!verification)
      printf("\nInforme CPF válido!\n");
    
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
      printf("\nInforme data válida!\n");

  }while (!verification);

  do{
    printf("Inserir gênero (M/F): ");
    scanf(" %c", &student.gender);
    getchar();
    
    verification = validateGender(student.gender);

    if(!verification)
      printf("\nInforme gênero válido!\n");
    else
      student.gender = toupper(student.gender);

  }while(!verification);

  for (int i = 0; i < MAX_DISC; i++)
    strcpy(student.disciplineCode[i], "\0");

  return student;
}

Student insertUpdateStudent(Student student){

  size_t ln;
  int verification;
      
  do{  

    printf("Inserir nome: ");
    fgets(student.name, MAX_NAME_LEN, stdin);
    removeBreakLine(student.name);
      
    verification = validateName(student.name);

    if(!verification)
      printf("\nInforme nome válido!\n");
    else  
      textToUpper(student.name);
  
  }while(!verification);

  do{

    printf("No padrão (###.###.###-##)\nInserir CPF: ");
    fgets(student.CPF, MAX_CPF_LEN, stdin);
    removeBreakLine(student.CPF);

    verification = validateCPF(student.CPF);

    if(!verification)
      printf("\nInforme CPF válido!\n");
    
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
      printf("\nInforme data válida!\n");

  }while (!verification);

  do{
    printf("Inserir gênero (M/F): ");
    scanf(" %c", &student.gender);
    getchar();
    
    verification = validateGender(student.gender);

    if(!verification)
      printf("\nInforme gênero válido!\n");
    else
      student.gender = toupper(student.gender);

  }while(!verification);

  return student;
}

void mainStudent(){

  int option;

  setlocale(LC_ALL, "Portuguese");

  do{
    header();
    printf("1. Inserir estudante;\n"); //OK
    printf("2. Listar estudantes;\n"); //OK
    printf("3. Pesquisar estudantes por sexo (M/F);\n"); //OK
    printf("4. Pesquisar estudantes por nome;\n"); //OK
    printf("5. Listar estudantes ordenados por nome;\n"); //OK
    printf("6. Listar estudantes ordenados data de nascimento;\n"); //OK
    printf("7. Aniversariantes do mês;\n"); //OK
    printf("8. Atualizar estudante;\n"); //OK
    printf("9. Excluir estudante;\n"); //OK
    printf("10.Retornar ao menu principal;\n"); //OK
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