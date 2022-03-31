#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/teacher.h"
#include "../model/student.h"
#include "../model/menu.h"

void printFullTeacher(Teacher teacher){

  printf("\n");
  printf("Matricula: \t\t %s\n", teacher.enrollment);
  printf("Nome: \t\t\t %s\n", teacher.name);
  printf("CPF: \t\t\t %s\n", teacher.CPF);
  printf("Data de nascimento: \t %02d/%02d/%d\n", 
  teacher.birthDate.day,
  teacher.birthDate.month,
  teacher.birthDate.year
  );
  printf("Gênero: \t\t %c\n", teacher.gender);
  printf ("***********************************************\n");

}

void printSummaryTeacher(Teacher teacher){

  printf("\n");
  printf("Matricula: %s - Nome: %s\n", teacher.enrollment, teacher.name);
  printf ("***********************************************\n");

}

void printSummaryTeacherWithBirthDate(Teacher teacher){

  printf("\n");
  printf("%02d/%02d/%d | Matricula: %s - Nome: %s \n", 
  teacher.birthDate.day,
  teacher.birthDate.month,
  teacher.birthDate.year,
  teacher.enrollment, 
  teacher.name
  );
  printf ("***********************************************\n");
}

Teacher insertCreateTeacher(Teacher teacher){

  size_t ln;
  int verification, verificationTeacher;

  do{

    do{
      printf("Inserir matricula: ");
      fgets(teacher.enrollment, MAX_ENR_LEN, stdin);
      removeBreakLine(teacher.enrollment);
      removeZero(teacher.enrollment);

      verification = validateEnrollment(teacher.enrollment);

    if(!verification)
      printf("\nInforme um número de matricula válido!\n");

    }while(!verification);

    verificationTeacher = isExistingTeacher(teacher.enrollment);

    if(!verificationTeacher)
      printf("\nO número de matricula já existe!\n");
    else{
      removeSpace(teacher.enrollment);
      textToUpper(teacher.enrollment);
    }

  }while (!verificationTeacher);
      
  do{  

    printf("Inserir nome: ");
    fgets(teacher.name, MAX_NAME_LEN, stdin);
    removeBreakLine(teacher.name);
      
    verification = validateName(teacher.name);

    if(!verification)
      printf("\nInforme nome válido!\n");
    else  
      textToUpper(teacher.name);
  
  }while(!verification);
    
  do{

    printf("\nNo padrão (###.###.###-##)\nInserir CPF: ");
    fgets(teacher.CPF, MAX_CPF_LEN, stdin);
    removeBreakLine(teacher.CPF);

    verification = validateCPF(teacher.CPF);

    if(!verification)
      printf("\nInforme CPF válido!");
      getchar();
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
      printf("\nInforme data válida!\n");
    }

  }while (!verification);
 
  do{
    printf("Inserir gênero (M/F): ");
    scanf(" %c", &teacher.gender);
    getchar();
    
    verification = validateGender(teacher.gender);

    if(!verification)
      printf("\nInforme gênero válido!!!\n");
    else  
      teacher.gender = toupper(teacher.gender);

  }while(!verification);

  for (int i = 0; i < MAX_DISC; i++)
    strcpy(teacher.disciplineCode[i], "\0");

  return teacher;
}

Teacher insertUpdateTeacher(Teacher teacher){

  size_t ln;
  int verification;
      
  do{  

    printf("Inserir nome: ");
    fgets(teacher.name, MAX_NAME_LEN, stdin);
    removeBreakLine(teacher.name);
      
    verification = validateName(teacher.name);

    if(!verification)
      printf("\nInforme nome válido!\n");
    else  
      textToUpper(teacher.name);
  
  }while(!verification);
    
  do{

    printf("\nNo padrão (###.###.###-##)\nInserir CPF: ");
    fgets(teacher.CPF, MAX_CPF_LEN, stdin);
    removeBreakLine(teacher.CPF);

    verification = validateCPF(teacher.CPF);

    if(!verification)
      printf("\nInforme CPF válido!");
      getchar();
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
      printf("\nInforme data válida!\n");
    }

  }while (!verification);
 
  do{
    printf("Inserir gênero (M/F): ");
    scanf(" %c", &teacher.gender);
    getchar();
    
    verification = validateGender(teacher.gender);

    if(!verification)
      printf("\nInforme gênero válido!!!\n");
    else  
      teacher.gender = toupper(teacher.gender);

  }while(!verification);

  return teacher;
}

void mainTeacher(){

  int option;

  setlocale(LC_ALL, "Portuguese");

  do{
    header();
    printf("1. Inserir professor;\n");
    printf("2. Listar professores;\n");
    printf("3. Pesquisar professores por sexo (M/F);\n");
    printf("4. Pesquisar professores por nome;\n");
    printf("5. Listar professores ordenados por nome;\n");
    printf("6. Listar professores ordenados data de nascimento;\n");
    printf("7. Aniversariantes do mês;\n");
    printf("8. Atualizar professor;\n");
    printf("9. Excluir professor;\n");
    printf("10. Retornar ao menu principal;\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:  createTeacher();break;
      case 2:  retrieveTeacher();break;
      case 3:  retrieveTeacherByGender();break;
      case 4:  retrieveTeacherByName(); break;
      case 5:  sortTeacherByName();break;
      case 6:  sortTeacherByBirthDate();break;
      case 7:  birthdaysOfTheMonthTeacher();break;
      case 8:  updateTeacher();break;
      case 9:  deleteTeacher();break;
      case 10: break;
      default: 
        printf("Opção inválida!\n"); 
        getchar();
        break;
    }
  }while(option != 10);

}