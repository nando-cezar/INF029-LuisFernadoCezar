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
    
  do{

    file = fopen("db/student.txt","ab");

    if(file == NULL){
      printf("Error opening file!");
      getchar();
    }else{

      header();
      student = insertCreateStudent(student);
      fwrite(&student, sizeof(Student), 1, file);
      fclose(file);
      do{
        printf("\n\nDeseja continuar(s/n)? ");
        scanf(" %c", &alternative);
        getchar();
        
        verification = validateAlternative(alternative);

        if(!verification)
          printf("\nInforme alternativa valida!\n\n");
          
      }while(!verification);
    }
  }while(alternative == 's');
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
    fclose(file);
    printf("Pressione qualquer tecla para voltar..."); 
  }
  getchar();
}

char* retrieveStudentSelected(){

  FILE *file;
  Student student;
  char* enrollment = (char*)malloc(MAX_ENR_LEN * sizeof(char)); 
  int idSelected, sizeArray = 1;
 
  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{

    header();
    while(fread(&student, sizeof(Student), 1, file) == 1){ 
      printf("ID: %d\n", sizeArray);
      printSummaryStudent(student);
      sizeArray++;
    }

    do{
      printf("Informe o ID do estudante que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    fseek(file, idSelected * sizeof(Student), SEEK_SET);
    if(fread(&student, sizeof(Student), 1, file) == 1){ 
      strcpy(enrollment, student.enrollment);
    }
    fclose(file);
    return enrollment;
  }
}

void retrieveStudentByGender(){ 

  FILE *file;
  Student student;
  char gender;
  int verification, count = 0;

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

      gender = charToUpper(gender);

    }while(!verification);

    while(fread(&student, sizeof(Student), 1, file) == 1){ 
      if(student.gender == gender){
        printStudent(student);
        count++;
      }
    }

    if(count == 0){
      printf("Nenhum regstro encontrado!");
      getchar();
    }
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void retrieveStudentByName(){
  
  FILE *file;
  Student student; 
  int verification = 0;
  char nameSearch[MAX_NAME_LEN];
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
      
      textToUpper(nameSearch);

      if(sizeNameSearch < 3){
        printf("\nDigite no mínimo 3 caracteres.");
        getchar();
      }
    }while(sizeNameSearch < 3);
   
    while(fread(&student,sizeof(Student), 1, file) == 1){
      if(strstr(student.name, nameSearch)){
        printStudent(student);
        verification++;
      }  
    }

    if(verification==0) printf("\nNão encontrado!\n\n");
    else verification = 0;  

    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
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
    free(ptrStudent);
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
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
   
    counter =  structAmount(file, &student, sizeof(Student));   
    ptrStudent = (Student*) malloc(counter * sizeof(Student));
   
    while(fread(&ptrStudent[auxiliary++],sizeof(ptrStudent[auxiliary]), 1, file) == 1);

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
    for(int i = 0; i < counter; i++){ 
      printStudent(ptrStudent[i]);
    }

    free(ptrStudent);
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
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

    while(fread(&student, sizeof(Student), 1, file) == 1){ 

      if(student.birthDate.month == month){
        printStudent(student);
      }
    }
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void updateStudent(){

  FILE *file;
  Student student, studentUpdated;
  int idSelected, sizeArray = 1;

  file = fopen("db/student.txt","rb+");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();

    while(fread(&student, sizeof(Student), 1, file) == 1){ 
      printf("ID: %d\n", sizeArray);
      printStudent(student);
      sizeArray++;
    }

    do{
      printf("Informe o ID do aluno que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));
    
    fseek(file, idSelected * sizeof(Student), SEEK_SET); 
    if(fread(&student, sizeof(Student), 1, file) == 1){
      strcpy(studentUpdated.enrollment, student.enrollment);
      studentUpdated = insertUpdateStudent(student);
    }
    
    fseek(file, idSelected * sizeof(Student), SEEK_SET); 
    fwrite(&studentUpdated, sizeof(Student), 1, file);
    
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
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

      do{
        printf("Informe o ID do estudante que deseja selecionar: ");
        scanf("%d", &idSelected);
        getchar();
        idSelected--;
      }while(!(idSelected >= 0 && idSelected < sizeArray-1));

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
      free(ptrStudent);
      fclose(file);
      printf("Pressione qualquer tecla para voltar...");  
    }
  }
  getchar();
}

int isExistingStudent(char enrollment[]){
  
  FILE *file;
  Student student;

  file = fopen("db/student.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    while(fread(&student,sizeof(student), 1, file) == 1){
        if(strcmp(student.enrollment, enrollment) == 0){
          fclose(file);
          return 0;
        }
    }
  }
  fclose(file);
  return 1;
}