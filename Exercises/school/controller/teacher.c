#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/teacher.h"
#include "../model/menu.h"
 
void createTeacher(){

  FILE *file;
  Teacher teacher;
  char alternative;
  int verification;

  do{

    file = fopen(TEACHER_PATH,"ab");

    if(file == NULL){
      printf(MESSAGE_ERROR);
      getchar();
    }else{

      header();
      teacher = insertCreateTeacher(teacher);
      fwrite(&teacher, sizeof(Teacher), 1, file);    
      fclose(file);
      
      do{
        printf("\n\nDeseja continuar(s/n)? ");
        scanf(" %c", &alternative);
        getchar();
        
        verification = validateAlternative(alternative);

        if(!verification)
          printf("\nInforme alternativa valida!\n\n");
      }while (!verification);
    }
  } while(alternative == 's');
}

void retrieveTeacher(){

  size_t nReg;
  Teacher *ptrTeacher;

  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    for(int i = 0; i < nReg; i++){ 
      printTeacher(ptrTeacher[i]);
    }
    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");
  } 
  getchar();
}

char* retrieveTeacherSelected(){

  FILE *file;
  size_t nReg;
  Teacher *ptrTeacher;
  char* enrollment = (char*)malloc(MAX_ENR_LEN * sizeof(char));
  int idSelected, sizeArray = 1;

  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    for(int i = 0; i < nReg; i++){ 
      printf("ID: %d\n", sizeArray);
      printSummaryTeacher(ptrTeacher[i]);
      sizeArray++; 
    }

    do{
      printf("Informe o ID do professor que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    strcpy(enrollment, ptrTeacher[idSelected].enrollment);
    
    free(ptrTeacher);
    return enrollment;
  }
}

void retrieveTeacherByGender(){

  size_t nReg;
  Teacher *ptrTeacher;
  char gender;
  int verification, count = 0;

  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
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
    
    for(int i = 0; i < nReg; i++){ 
      if(ptrTeacher[i].gender == gender){
        printTeacher(ptrTeacher[i]);
        count++;
      }
    }

    if(count == 0){
      printf("Nenhum registro encontrado!");
      getchar();
    }

    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void retrieveTeacherByName(){

  size_t nReg;
  Teacher *ptrTeacher; 
  int verification = 0;
  char nameSearch[MAX_NAME_LEN];
  int sizeNameSearch;
 
  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
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
      if(strstr(ptrTeacher[i].name, nameSearch))
        printTeacher(ptrTeacher[i]);
        verification++;
    }

    if(verification==0) printf("\nNão encontrado!\n\n");
    else verification = 0;  
    
    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");  
  }
  getchar();
}

void sortTeacherByName(){

  size_t nReg;
  Teacher auxiliaryTeacher, *ptrTeacher;
  int counter = 0, auxiliary = 0;

  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    for(int i = 0 ; i < nReg; i++){
      for(int j = i+1; j < nReg; j++ ){
        if(strcmp(ptrTeacher[i].name, ptrTeacher[j].name) > 0){
          auxiliaryTeacher = ptrTeacher[i];
          ptrTeacher[i] = ptrTeacher[j];
          ptrTeacher[j] = auxiliaryTeacher;
        }
      }
    }

    header();
    for(int i = 0; i < nReg; i++){ 
      printTeacher(ptrTeacher[i]);
    }

    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void sortTeacherByBirthDate(){

  size_t nReg;
  Teacher auxiliaryTeacher, *ptrTeacher;
  int checkerYear, checkerMonth, checkerDay;

  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    for(int i = 0; i < nReg; i++){
      for(int j = i+1; j < nReg; j++ ){

        checkerYear = isLarger(ptrTeacher[i].birthDate.year, ptrTeacher[j].birthDate.year);
        checkerMonth = isLarger(ptrTeacher[i].birthDate.month, ptrTeacher[j].birthDate.month); 
        checkerDay = isLarger(ptrTeacher[i].birthDate.day, ptrTeacher[j].birthDate.day);

        if(checkerYear == 1 ||
          (checkerYear == 0 && checkerMonth == 1) ||
          (checkerYear == 0 && checkerMonth == 0 && checkerDay==0))
          {
            auxiliaryTeacher = ptrTeacher[i];
            ptrTeacher[i] = ptrTeacher[j];
            ptrTeacher[j] = auxiliaryTeacher;
        }
      }
    }

    header();
    for(int i = 0; i < nReg;i++){ 
      printTeacher(ptrTeacher[i]);
    }

    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");   
  }
  getchar();
}

void birthdaysOfTheMonthTeacher(){

  size_t nReg;
  Teacher *ptrTeacher;
  int month;

  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();
    printf("Informe qual o número do mês deseja buscar: ");
    scanf("%d", &month);
    getchar();

    for(int i = 0; i < nReg; i++){ 
      if(ptrTeacher[i].birthDate.month == month)
        printTeacher(ptrTeacher[i]);
    }

    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void updateTeacher(){

  FILE *file;
  size_t nReg;
  Teacher teacher, *ptrTeacher;
  int idSelected, sizeArray = 1;

  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    for(int i = 0; i < nReg; i++){ 
      printf("ID: %d\n", sizeArray);
      printTeacher(ptrTeacher[i]);
      sizeArray++; 
    }

    do{
      printf("Informe o ID do professor que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    ptrTeacher[idSelected] = insertUpdateTeacher(ptrTeacher[idSelected]);

    toFileTeacher(&ptrTeacher[idSelected], sizeof(Teacher), TEACHER_PATH,"rb+", idSelected);

    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void deleteTeacher(){

  size_t fSize, nReg;
  Teacher teacher, *ptrTeacher;
  int idSelected, sizeArray = 1;

  ptrTeacher = toPointerTeacher(&nReg, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    for(int i = 0; i < nReg; i++){ 
      printf("ID: %d\n", sizeArray);
      printSummaryTeacher(ptrTeacher[i]);
      sizeArray++; 
    }

    do{
      printf("Informe o ID do professor que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    ptrTeacher[idSelected] = ptrTeacher[nReg-1];
    ptrTeacher = (Teacher*) realloc(ptrTeacher, --sizeArray * sizeof(Teacher)); 
  
    remove(TEACHER_PATH);

    for(int i = 0; i < nReg-1; i++){
      toFileTeacher(&ptrTeacher[i], sizeof(Teacher), TEACHER_PATH,"ab", i);
    }
    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");    
  }
  getchar();
}

int isExistingTeacher(char enrollment[]){


  FILE *file;
  Teacher teacher;

  file = fopen(TEACHER_PATH,"rb");

  if(file == NULL){
      printf(MESSAGE_ERROR);

  }else{
    rewind(file);
    while(fread(&teacher,sizeof(teacher), 1, file) == 1){
        if(strcmp(teacher.enrollment, enrollment) == 0){
            fclose(file);
            return 0;
        }
    }
  }
  fclose(file);
  return 1;
}

Teacher* toPointerTeacher(size_t *nReg, size_t size, char filePath[], char mode[]){

  FILE *file;
  Teacher* pointer = NULL;
  size_t fSize;

  file = fopen(filePath, mode);

  if(file == NULL){
    printf(MESSAGE_ERROR);

  }else{

    fseek(file, 0L, SEEK_END);
    fSize = ftell(file);
    (*nReg) = fSize/size;
    rewind(file);

    pointer = (Teacher*) malloc(fSize);

    for(int i = 0; i < (*nReg); i++){
      fread(&pointer[i], size, 1, file);
    }

    fclose(file);
  }
  return pointer;
}

void toFileTeacher(Teacher *ptrTeacher, size_t size, char filePath[], char mode[], int idSelected){

  FILE *file;

  file = fopen(filePath, mode);

  if(file == NULL)
    printf(MESSAGE_ERROR);
  else{

    fseek(file, idSelected * sizeof(Teacher), SEEK_SET);
    fwrite(ptrTeacher, sizeof(Teacher), 1, file);

    fclose(file);
  }
}