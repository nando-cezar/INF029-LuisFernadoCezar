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

    file = fopen(STUDENT_PATH,"ab");

    if(file == NULL){
      printf(MESSAGE_ERROR);
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

  size_t nReg;
  Student *ptrStudent;

  ptrStudent = toPointerStudent(&nReg, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    for(int i = 0; i < nReg; i++){ 
      printSummaryStudent(ptrStudent[i]);
    }
    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");
  } 
  getchar();
}

void retrieveStudentWithLessThan3Disciplines(){

  size_t nRegStudent = 0;
  Student *ptrStudent;
  int values[nRegStudent];

  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{
 
    header();

    for(int i = 0; i < nRegStudent; i++){ 
      values[i] = 0;
      for(int j = 0; strcmp(ptrStudent[i].disciplineCode[j], "\0") != 0; j++){
        values[i] += 1;
      }
    }
    for(int i = 0; i < nRegStudent; i++){
      if(values[i] < 3){
        printSummaryStudent(ptrStudent[i]);
      }
    }

    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

Student retrieveDataStudent(char enrollment[]){
 
  Student student, *ptrStudent;
  size_t nRegStudent;

  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    for(int i = 0; i < nRegStudent; i++){ 
      if(strcmp(ptrStudent[i].enrollment, enrollment) == 0){
        student = ptrStudent[i];
      }
    }
  }
  return student;
}

Student retrieveObjectStudent(int *idSelected, int *sizeArray){
 
  Student *ptrStudent;
  size_t nRegStudent;
  int id = 0;

  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    for(int i = 0; i < nRegStudent; i++){ 
      printf("ID: %d\n", *sizeArray);
      printSummaryStudent(ptrStudent[i]);
      (*sizeArray)++;      
    }

    do{
      printf("Informe o ID do estudante que deseja selecionar: ");
      scanf("%d", &id);
      getchar();
      *idSelected = id;
      (*idSelected)--;
    }while(!(*idSelected >= 0 && *idSelected < *sizeArray-1));
    
    return ptrStudent[*idSelected];
  }
}

char* retrieveEnrollmentStudent(){

  Student studentSelected;
  char* enrollment = (char*)malloc(MAX_ENR_LEN * sizeof(char));
  int idSelected, sizeArray = 1;

  studentSelected = retrieveObjectStudent(&idSelected, &sizeArray);
  strcpy(enrollment, studentSelected.enrollment);
  
  return enrollment;
}

void retrieveStudentByGender(){ 

  size_t nReg;
  Student *ptrStudent;
  char gender;
  int verification, count = 0;

  ptrStudent = toPointerStudent(&nReg, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    do{
      header();

      printf("Informe qual o gênero deseja buscar(M/F): ");
      scanf(" %c", &gender);
      getchar();
      
      verification = validateGender(gender);

      if(!verification){
        printf("\nInforme gênero válido!");
        getchar();
      }

      gender = toupper(gender);
      
    }while(!verification);
    
    for(int i = 0; i < nReg; i++){ 
      if(ptrStudent[i].gender == gender){
        printFullStudent(ptrStudent[i]);
        count++;
      }
    }

    if(count == 0){
      printf("Nenhum registro encontrado!\n");
    }

    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void retrieveStudentByName(){
  
  size_t nReg;
  Student *ptrStudent; 
  int verification = 0;
  char nameSearch[MAX_NAME_LEN];
  int sizeNameSearch;
 
  ptrStudent = toPointerStudent(&nReg, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
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

    for(int i = 0; i < nReg; i++){ 
      if(strstr(ptrStudent[i].name, nameSearch))
        printFullStudent(ptrStudent[i]);
        verification++;
    }

    if(verification==0) printf("\nNão encontrado!\n\n");
    else verification = 0;  
    
    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");  
  }
  getchar();
}

void sortStudentByName(){

  size_t nReg;
  Student auxiliaryStudent, *ptrStudent;
  int counter = 0, auxiliary = 0;

  ptrStudent = toPointerStudent(&nReg, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    for(int i = 0 ; i < nReg; i++){
      for(int j = i+1; j < nReg; j++ ){
        if(strcmp(ptrStudent[i].name, ptrStudent[j].name) > 0){
          auxiliaryStudent = ptrStudent[i];
          ptrStudent[i] = ptrStudent[j];
          ptrStudent[j] = auxiliaryStudent;
        }
      }
    }

    header();
    for(int i = 0; i < nReg; i++){ 
      printSummaryStudent(ptrStudent[i]);
    }

    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void sortStudentByBirthDate(){

  size_t nReg;
  Student auxiliaryStudent, *ptrStudent;
  int checkerYear, checkerMonth, checkerDay;

  ptrStudent = toPointerStudent(&nReg, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    for(int i = 0; i < nReg; i++){
      for(int j = i+1; j < nReg; j++ ){

        checkerYear = isLarger(ptrStudent[i].birthDate.year, ptrStudent[j].birthDate.year);
        checkerMonth = isLarger(ptrStudent[i].birthDate.month, ptrStudent[j].birthDate.month); 
        checkerDay = isLarger(ptrStudent[i].birthDate.day, ptrStudent[j].birthDate.day);

        if(checkerYear == 1 ||
          (checkerYear == 0 && checkerMonth == 1) ||
          (checkerYear == 0 && checkerMonth == 0 && checkerDay==1))
          {
            auxiliaryStudent = ptrStudent[i];
            ptrStudent[i] = ptrStudent[j];
            ptrStudent[j] = auxiliaryStudent;
        }
      }
    }

    header();
    for(int i = 0; i < nReg;i++){ 
      printSummaryStudentWithBirthDate(ptrStudent[i]);
    }

    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");   
  }
  getchar();
}

void birthdaysOfTheMonthStudent(){

  size_t nReg;
  Student *ptrStudent;
  int month;

  ptrStudent = toPointerStudent(&nReg, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();
    printf("Informe qual o número do mês deseja buscar: ");
    scanf("%d", &month);
    getchar();

    for(int i = 0; i < nReg; i++){ 
      if(ptrStudent[i].birthDate.month == month)
        printSummaryStudentWithBirthDate(ptrStudent[i]);
    }

    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void updateStudent(){

  Student studentSelected;
  int idSelected = -1, sizeArray = 1;

  studentSelected = retrieveObjectStudent(&idSelected, &sizeArray);

  if(idSelected != -1){
    studentSelected = insertUpdateStudent(studentSelected);
    toFileStudent(&studentSelected, sizeof(Student), STUDENT_PATH,"rb+", idSelected);
  
    printf("Pressione qualquer tecla para voltar...");
  }
 
  getchar();
}

void deleteStudent(){

  size_t nReg;
  Student *ptrStudent, studentSelected;
  int idSelected, sizeArray = 1;
  int quantity = 0;

  ptrStudent = toPointerStudent(&nReg, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    studentSelected = retrieveObjectStudent(&idSelected, &sizeArray);

    for(int i = 0; strcmp(studentSelected.disciplineCode[i], "\0") != 0; i++){
      quantity++;
    }

    if(quantity == 0){

      ptrStudent[idSelected] = ptrStudent[nReg-1];
      ptrStudent = (Student*) realloc(ptrStudent, --sizeArray * sizeof(Student)); 
    
      remove(STUDENT_PATH);

      for(int i = 0; i < nReg-1; i++){
        toFileStudent(&ptrStudent[i], sizeof(Student), STUDENT_PATH,"ab", i);
      }
    }else{
      printf("O estudante se encontra vinculado a uma ou mais disciplinas!\n");
    }
    
    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");    
  }
  getchar();
}

int isExistingStudent(char enrollment[]){
  
  size_t nReg;
  Student *ptrStudent;

  ptrStudent = toPointerStudent(&nReg, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
      printf(MESSAGE_ERROR);

  }else{
    
    for(int i = 0; i < nReg; i++){
      if(strcmp(ptrStudent[i].enrollment, enrollment) == 0){
          free(ptrStudent);
          return 0;
      }
    }
  }
  free(ptrStudent);
  return 1;
}

Student* toPointerStudent(size_t *nReg, size_t size, char filePath[], char mode[]){

  FILE *file;
  Student* pointer = NULL;
  size_t fSize;

  file = fopen(filePath, mode);

  if(file == NULL){
    printf(MESSAGE_ERROR);

  }else{

    fseek(file, 0L, SEEK_END);
    fSize = ftell(file);
    (*nReg) = fSize/size;
    rewind(file);
    
    pointer = (Student*) malloc(fSize);

    for(int i = 0; i < (*nReg); i++){
      fread(&pointer[i], size, 1, file);
    }

    fclose(file);
  }
  return pointer;

}

void toFileStudent(Student *ptrStudent, size_t size, char filePath[], char mode[], int idSelected){

  FILE *file;

  file = fopen(filePath, mode);

  if(file == NULL)
    printf(MESSAGE_ERROR);
  else{

    fseek(file, idSelected * sizeof(Student), SEEK_SET);
    fwrite(ptrStudent, sizeof(Student), 1, file);

    fclose(file);
  }
}