#include "../view/menu.h"
#include "../util/utility.h"
#include "interface/student.h"

void createStudent(){

  FILE * file;
  size_t ln;
  Student student;

  file = fopen("db/student.txt","ab");

  if(file == NULL){
    printf("Error opening file!");
  }else{
    do{
      header();
      printf("Inserir matricula: ");
      fgets(student.enrollment, MAX_ENR_LEN, stdin);
      ln = strlen(student.enrollment) - 1;
      if (student.enrollment[ln] == '\n')
        student.enrollment[ln] = '\0';

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
      getchar();

      printf("Inserir gênero (M/F): ");
      scanf(" %c", &student.gender);
      getchar();

      fwrite(&student, sizeof(Student), 1, file);
      printf("\n\nDeseja continuar(s/n)? \n");

    } while(getche() == 's');
    fclose(file);
  }
}

void retrieveStudent(){

  FILE * file;
  Student student;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();
    while(fread(&student, sizeof(Student), 1, file) == 1){   
      printf("Matricula: %s\n", student.enrollment);
      printf("Nome: %s\n", student.name);
      printf("CPF: %s\n", student.CPF);
      printf("Data de nascimento: %d/%d/%d\n", 
      student.birthDate.day,
      student.birthDate.month,
      student.birthDate.year
      );
      printf("Inserir gênero (M/F): %c\n", student.gender);
      printf ("***********************************************\n\n");
    }
  }
  fclose(file);
  getch();
}

void retrieveStudentByGender(){

  FILE * file;
  Student student;
  char gender;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{

    header();
    printf("Informe qual o gênero deseja buscar(M/F): ");
    scanf(" %c", &gender);
    printf("\n\n");

    while(fread(&student, sizeof(Student), 1, file) == 1){ 

      if(student.gender == gender){
        printf("Matricula: %s\n", student.enrollment);
        printf("Nome: %s\n", student.name);
        printf("CPF: %s\n", student.CPF);
        printf("Data de nascimento: %d/%d/%d\n", 
        student.birthDate.day,
        student.birthDate.month,
        student.birthDate.year
        );
        printf("Inserir gênero (M/F): %c\n", student.gender);
        printf ("***********************************************\n\n");
      }
    }
  }
  fclose(file);
  getch();
}

void sortStudentByName(){

  FILE * file;
  Student student;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();
    /*while(fread(&student, sizeof(Student), 1, file) == 1){
 
      printf("Matricula: %s\n", student.enrollment);
      printf("Nome: %s\n", student.name);
      printf("CPF: %s\n", student.CPF);
      printf("Data de nascimento: %d/%d/%d\n", 
      student.birthDate.day,
      student.birthDate.month,
      student.birthDate.year
      );
      printf("Inserir gênero (M/F): %c\n", student.gender);
      printf ("***********************************************\n\n");
    
    }
    */
  }
  fclose(file);
  getch();
}

void sortStudentByBirthDate(){

  FILE * file;
  Student student;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();
    /*while(fread(&student, sizeof(Student), 1, file) == 1){
 
      printf("Matricula: %s\n", student.enrollment);
      printf("Nome: %s\n", student.name);
      printf("CPF: %s\n", student.CPF);
      printf("Data de nascimento: %d/%d/%d\n", 
      student.birthDate.day,
      student.birthDate.month,
      student.birthDate.year
      );
      printf("Inserir gênero (M/F): %c\n", student.gender);
      printf ("***********************************************\n\n");
    
    }
    */
  }
  fclose(file);
  getch();
}

void birthdaysOfTheMonth(){

  FILE * file;
  Student student;
  int month;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();
    printf("Informe qual o número do mês deseja buscar: ");
    scanf("%d", &month);
    printf("\n\n");

    while(fread(&student, sizeof(Student), 1, file) == 1){ 

      if(student.birthDate.month == month){
        printf("Matricula: %s\n", student.enrollment);
        printf("Nome: %s\n", student.name);
        printf("CPF: %s\n", student.CPF);
        printf("Data de nascimento: %d/%d/%d\n", 
        student.birthDate.day,
        student.birthDate.month,
        student.birthDate.year
        );
        printf("Inserir gênero (M/F): %c\n", student.gender);
        printf ("***********************************************\n\n");
      }
    }
  }
  fclose(file);
  getch();
}

void updateStudent(){

  FILE * file;
  size_t ln;
  Student student;
  int id, i = 1;

  file = fopen("db/student.txt","rb+");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();    
    printf("\n\n\tLista de alunos!\n");
    printf ("------------------------------------------------\n\n");

    while(fread(&student, sizeof(Student), 1, file) == 1){ 
      printf("ID: %d\n", i);
      printf("Matricula: %s\n", student.enrollment);
      printf("Nome: %s\n", student.name);
      printf("CPF: %s\n", student.CPF);
      printf("Data de nascimento: %d/%d/%d\n", 
      student.birthDate.day,
      student.birthDate.month,
      student.birthDate.year
      );
      printf("Gênero: %c\n", student.gender);
      printf ("***********************************************\n\n");
      i++;
    }

    printf("Informe o ID do aluno que deseja alterar: ");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < i-1) {
      printf("Inserir matricula: ");
      fgets(student.enrollment, MAX_ENR_LEN, stdin);
      ln = strlen(student.enrollment) - 1;
      if (student.enrollment[ln] == '\n')
        student.enrollment[ln] = '\0';

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
      getchar();

      printf("Inserir gênero (M/F): ");
      scanf(" %c", &student.gender);
      getchar();

      fseek(file, id * sizeof(Student), SEEK_SET);
      fwrite(&student, sizeof(Student), 1, file);
    }

  }
  fclose(file);
  getch();
}

void mainStudent(){

  //setlocale(LC_ALL, "Portuguese");

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
      case 8: break;
      case 9: break;
      default: 
        printf("Opção inválida!\n"); 
        getch();
        break;
    }
  }while(option != 9);

}