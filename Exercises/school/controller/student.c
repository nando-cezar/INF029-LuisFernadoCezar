#include "../util/utility.h"
#include "../util/validation.h"
#include "../model/menu.h"
#include "../model/student.h"

void createStudent(){

  FILE * file;
  Student student;
  char c;
  int verification;

  file = fopen("db/student.txt","ab");

  if(file == NULL){
    printf("Error opening file!");
  }else{
    do{
      header();
      student = insertStudent(student);
      fwrite(&student, sizeof(Student), 1, file);

      do{
        printf("\n\nDeseja continuar(s/n)? ");
        scanf(" %c", &c);
        getchar();
        
        verification = validateAlternative(c);

        if(!verification)
          printf("\nInforme alternativa valida!\n\n");
      }while (!verification);

    } while(c == 's');
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
      printStudent(student);
    }
  }
  fclose(file);
  getchar();
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
        printStudent(student);
      }
    }
  }
  fclose(file);
  getchar();
}

void sortStudentByName(){

  FILE * file;
  Student student;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();
    /* implementing */
  }
  fclose(file);
  getchar();
}

void sortStudentByBirthDate(){

  FILE * file;
  Student student;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();
    /* implementing */
  }
  fclose(file);
  getchar();
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
        printStudent(student);
      }
    }
  }
  fclose(file);
  getchar();
}

void updateStudent(){

  FILE * file;
  Student student;
  int id, i = 1;

  file = fopen("db/student.txt","rb+");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();

    while(fread(&student, sizeof(Student), 1, file) == 1){ 
      printf("ID: %d\n", i);
      printStudent(student);
      i++;
    }

    printf("Informe o ID do aluno que deseja alterar: ");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < i-1) {
      student = insertStudent(student);
      fseek(file, id * sizeof(Student), SEEK_SET);
      fwrite(&student, sizeof(Student), 1, file);
    }

  }
  fclose(file);
  getchar();
}

void deleteStudent(){

  FILE * file;
  size_t fSize, nReg;
  Student student;
  Student * ptrStudent;
  int idSelected, sizeArray = 1;
  int indexPtrStudent = 0;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{

    fseek(file, 0L, SEEK_END);
    fSize = ftell(file);
    nReg = fSize/sizeof(Student);
    ptrStudent = (Student *) malloc(fSize);

    if(ptrStudent == NULL){
      printf("Error opening array!");
    }else{

      header();
      fseek(file, 0L, SEEK_SET);
      while(fread(&student, sizeof(Student), 1, file) == 1){ 
        printf("ID: %d\n", sizeArray);
        printStudent(student);
        ptrStudent[indexPtrStudent] = student;
        indexPtrStudent++;
        sizeArray++;
      }

      printf("Informe o ID do aluno que deseja excluir: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;

      if(idSelected >= 0 && idSelected < sizeArray-1) {

        ptrStudent[idSelected] = ptrStudent[nReg-1];
        ptrStudent = (Student*) realloc(ptrStudent, --sizeArray * sizeof(Student)); 
      
        fclose(file);
        remove("db/student.txt");
        file = fopen("db/student.txt","ab");

        for(int j = 0; j < nReg-1; j++){
          strcpy(student.enrollment, ptrStudent[j].enrollment);
          strcpy(student.name, ptrStudent[j].name);
          strcpy(student.CPF, ptrStudent[j].CPF);
          student.birthDate.day = ptrStudent[j].birthDate.day;
          student.birthDate.month = ptrStudent[j].birthDate.month;
          student.birthDate.year = ptrStudent[j].birthDate.year;
          student.gender = ptrStudent[j].gender;

          fwrite(&student, sizeof(Student), 1, file);
        }
      }else{
        printf("Invalide code!");
      }

    }
  }
  fclose(file);
  getchar();
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