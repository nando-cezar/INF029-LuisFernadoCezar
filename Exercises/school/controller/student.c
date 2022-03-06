#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/student.h"
#include "../model/menu.h"

void createStudent(){

  FILE *file;
  Student student;
  char alternative;
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
        scanf(" %c", &alternative);
        getchar();
        
        verification = validateAlternative(alternative);

        if(!verification)
          printf("\nInforme alternativa valida!\n\n");
      }while (!verification);

    } while(alternative == 's');
    fclose(file);
  }
}

void retrieveStudent(){

  FILE *file;
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

  FILE *file;
  Student student;
  char gender;
  int verification;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
    
  }else{
    
    do{
      header();
      printf("Informe qual o gênero deseja buscar(M/F): ");
      scanf(" %c", &gender);
      getchar();

      verification = validateGender(gender);

      if(!verification){
        printf("\nInforme gênero válido!!!");
        getchar();
      }

      

    }while(!verification);

    while(fread(&student, sizeof(Student), 1, file) == 1){ 

      if(student.gender == gender){
        printStudent(student);
      }
    }
  }
  fclose(file);
  getchar();
}

void retrieveStudentByName(){
  
  FILE *file;
  Student student, *ptrStudent; 
  int counter = 0, auxiliary = 0, verification = 0;
  char nameSearch[MAX_NAME_LEN], *ret;
  int sizeNameSearch;
 
 
  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{

    do{
      header();
      printf("Informe qual o nome deseja buscar: ");
      fgets(nameSearch, MAX_NAME_LEN, stdin);
      sizeNameSearch = strlen(nameSearch) - 1;
      if (nameSearch[sizeNameSearch] == '\n')
        nameSearch[sizeNameSearch] = '\0';

      if(sizeNameSearch < 3){
        printf("\nDigite no mínimo 3 caracteres.");
        getchar();
      }
    }while(sizeNameSearch < 3);

    counter = structAmount(file, &student, sizeof(Student));
    ptrStudent = (Student*) malloc(counter * sizeof(Student));
   
    while(fread(&ptrStudent[auxiliary],sizeof(ptrStudent[auxiliary]), 1, file) == 1){

      ret = strstr(ptrStudent[auxiliary].name, nameSearch);
      if(ret){
        printStudent(ptrStudent[auxiliary]);
        verification++;
      }   
      auxiliary++;
    }

    if(verification==0) printf("\n\nNão encontrado!");
    else verification = 0;  
  }
  free(ptrStudent);
  fclose(file);
  getchar();
}

void sortStudentByName(){

  FILE *file;
  Student student, auxiliaryStudent, *ptrStudent;
  int counter = 0, auxiliary = 0;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    counter =  structAmount(file, &student, sizeof(Student));   
    ptrStudent = (Student*) malloc(counter * sizeof(Student));
   
    while(fread(&ptrStudent[auxiliary++],sizeof(ptrStudent[auxiliary]), 1, file) == 1);

    for(int i = 0 ; i < counter ; i++){
      for(int j = i+1; j < counter; j++ ){
        if(strcmp(ptrStudent[i].name, ptrStudent[j].name) > 0){
          auxiliaryStudent = ptrStudent[i];
          ptrStudent[i] = ptrStudent[j];
          ptrStudent[j] = auxiliaryStudent;
        }
      }
    }

    header();
    for(int i = 0; i < counter; i++){ 
      printStudent(ptrStudent[i]);
    }
    
  }
  free(ptrStudent);
  fclose(file);
  getchar();
}

void sortStudentByBirthDate(){

  FILE *file;
  Student student, auxiliaryStudent, *ptrStudent;
  int counter = 0, auxiliary = 0;
  int checkerYear, checkerMonth, checkerDay;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{

    counter = structAmount(file, &student, sizeof(Student));   
    ptrStudent = (Student*) malloc(counter * sizeof(Student));

    while(fread(&ptrStudent[auxiliary++], sizeof(ptrStudent[auxiliary]), 1, file) == 1);

    for(int i = 0; i < counter; i++){
      for(int j = i+1; j < counter; j++ ){

        checkerYear = isLarger(ptrStudent[i].birthDate.year, ptrStudent[j].birthDate.year);
        checkerMonth = isLarger(ptrStudent[i].birthDate.month, ptrStudent[j].birthDate.month); 
        checkerDay = isLarger(ptrStudent[i].birthDate.day, ptrStudent[j].birthDate.day);

        if(checkerYear == 1 ||
          (checkerYear == 0 && checkerMonth == 1) ||
          (checkerYear == 0 && checkerMonth == 0 && checkerDay==0))
          {
            auxiliaryStudent = ptrStudent[i];
            ptrStudent[i] = ptrStudent[j];
            ptrStudent[j] = auxiliaryStudent;
        }

      }
    }

    header();
    for(int i = 0; i < counter;i++){ 
      printStudent(ptrStudent[i]);
    }
    
  }
  free(ptrStudent);
  fclose(file);
  getchar();
 
}

void birthdaysOfTheMonthStudent(){

  FILE *file;
  Student student;
  int month;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    header();
    printf("Informe qual o número do mês deseja buscar: ");
    scanf("%d", &month);
    getchar();
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

  FILE *file;
  Student student;
  int id, identity = 1;

  file = fopen("db/student.txt","rb+");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();

    while(fread(&student, sizeof(Student), 1, file) == 1){ 
      printf("ID: %d\n", identity);
      printStudent(student);
      identity++;
    }

    printf("Informe o ID do aluno que deseja alterar: ");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < identity-1) {
      student = insertStudent(student);
      fseek(file, id * sizeof(Student), SEEK_SET);
      fwrite(&student, sizeof(Student), 1, file);
    }

  }
  fclose(file);
  getchar();
}

void deleteStudent(){

  FILE *file;
  size_t fSize, nReg;
  Student student, *ptrStudent;
  int idSelected, sizeArray = 1, indexPtrStudent = 0;

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