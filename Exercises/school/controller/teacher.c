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

    file = fopen("db/teacher.txt","ab");

    if(file == NULL){
      printf("Error opening file!");
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

  FILE *file;
  Teacher teacher;

  file = fopen("db/teacher.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
    
  }else{
    header();
    while(fread(&teacher, sizeof(Teacher), 1, file) == 1){   
      printTeacher(teacher);
    }
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  } 
  getchar();
}

char* retrieveTeacherSelected(){

  FILE *file;
  Teacher teacher;
  char* enrollment = (char*)malloc(MAX_ENR_LEN * sizeof(char));
  int idSelected, sizeArray = 1;

  file = fopen("db/teacher.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{

    while(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 
      printf("ID: %d\n", sizeArray);
      printSummaryTeacher(teacher);
      sizeArray++;
    }

    do{
      printf("Informe o ID do professor que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    fseek(file, idSelected * sizeof(Teacher), SEEK_SET);
    if(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 
      strcpy(enrollment, teacher.enrollment);
    }
    fclose(file);
    return enrollment;
  }
}

void retrieveTeacherByGender(){

  FILE *file;
  Teacher teacher;
  char gender;
  int verification, count = 0;

  file = fopen("db/teacher.txt","rb");

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

    while(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 

      if(teacher.gender == gender){
        printTeacher(teacher);
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

void retrieveTeacherByName(){
  
  FILE *file;
  Teacher teacher; 
  int verification = 0;
  char nameSearch[MAX_NAME_LEN];
  int sizeNameSearch;
 
 
  file = fopen("db/teacher.txt","rb");

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
   
    while(fread(&teacher,sizeof(Teacher), 1, file) == 1){
      if(strstr(teacher.name, nameSearch)){
        printTeacher(teacher);
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

void sortTeacherByName(){

  FILE *file;
  Teacher teacher, auxiliaryTeacher, *ptrTeacher;
  int counter = 0, auxiliary = 0;

  file = fopen("db/teacher.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    counter =  structAmount(file, &teacher, sizeof(Teacher));   
    ptrTeacher = (Teacher*) malloc(counter * sizeof(Teacher));
   
    while(fread(&ptrTeacher[auxiliary++],sizeof(ptrTeacher[auxiliary]), 1, file) == 1);

    for(int i = 0 ; i < counter; i++){
      for(int j = i+1; j < counter; j++ ){
        if(strcmp(ptrTeacher[i].name, ptrTeacher[j].name) > 0){
          auxiliaryTeacher = ptrTeacher[i];
          ptrTeacher[i] = ptrTeacher[j];
          ptrTeacher[j] = auxiliaryTeacher;
        }
      }
    }

    header();
    for(int i = 0; i < counter; i++){ 
      printTeacher(ptrTeacher[i]);
    }
    free(ptrTeacher);
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void sortTeacherByBirthDate(){

  FILE *file;
  Teacher teacher, auxiliaryTeacher, *ptrTeacher;
  int counter = 0, auxiliary = 0;
  int checkerYear, checkerMonth, checkerDay;

  file = fopen("db/teacher.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    counter =  structAmount(file, &teacher, sizeof(Teacher));   
    ptrTeacher = (Teacher*) malloc(counter * sizeof(Teacher));
   
    while(fread(&ptrTeacher[auxiliary++],sizeof(ptrTeacher[auxiliary]), 1, file) == 1);

    for(int i = 0; i < counter; i++){
      for(int j = i+1; j < counter; j++ ){

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
    for(int i = 0; i < counter;i++){ 
      printTeacher(ptrTeacher[i]);
    }

    free(ptrTeacher);
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");   
  }
  getchar();
}

void birthdaysOfTheMonthTeacher(){

  FILE *file;
  Teacher teacher;
  int month;

  file = fopen("db/teacher.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    header();
    printf("Informe qual o número do mês deseja buscar: ");
    scanf("%d", &month);
    getchar();

    while(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 

      if(teacher.birthDate.month == month){
        printTeacher(teacher);
      }
    }
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void updateTeacher(){

  FILE *file;
  Teacher teacher, teacherUpdated;
  int idSelected, sizeArray = 1;

  file = fopen("db/teacher.txt","rb+");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();

    while(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 
      printf("ID: %d\n", sizeArray);
      printTeacher(teacher);
      sizeArray++;
    }

    do{
      printf("Informe o ID do professor que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    fseek(file, idSelected * sizeof(Teacher), SEEK_SET); 
    if(fread(&teacher, sizeof(Teacher), 1, file) == 1){
      strcpy(teacherUpdated.enrollment, teacher.enrollment);
      teacherUpdated = insertUpdateTeacher(teacher);
    }
    
    fseek(file, idSelected * sizeof(Teacher), SEEK_SET); 
    fwrite(&teacherUpdated, sizeof(Teacher), 1, file);
    
    fclose(file);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void deleteTeacher(){

  FILE *file;
  size_t fSize, nReg;
  Teacher teacher, *ptrTeacher;
  int idSelected, sizeArray = 1, indexPtrTeacher = 0;

  file = fopen("db/teacher.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{

    fseek(file, 0L, SEEK_END);
    fSize = ftell(file);
    nReg = fSize/sizeof(Teacher);
    ptrTeacher = (Teacher *) malloc(fSize);

    if(ptrTeacher == NULL){
      printf("Error opening array!");
    }else{

      header();
      fseek(file, 0L, SEEK_SET);
      while(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 
        printf("ID: %d\n", sizeArray);
        printTeacher(teacher);
        ptrTeacher[indexPtrTeacher] = teacher;
        indexPtrTeacher++;
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
    
      fclose(file);
      remove("db/teacher.txt");
      file = fopen("db/teacher.txt","ab");

      for(int j = 0; j < nReg-1; j++){
        strcpy(teacher.enrollment, ptrTeacher[j].enrollment);
        strcpy(teacher.name, ptrTeacher[j].name);
        strcpy(teacher.CPF, ptrTeacher[j].CPF);
        teacher.birthDate.day = ptrTeacher[j].birthDate.day;
        teacher.birthDate.month = ptrTeacher[j].birthDate.month;
        teacher.birthDate.year = ptrTeacher[j].birthDate.year;
        teacher.gender = ptrTeacher[j].gender;
        fwrite(&teacher, sizeof(Teacher), 1, file);
      }
      free(ptrTeacher);
      fclose(file);
      printf("Pressione qualquer tecla para voltar...");    
    }
  }
  getchar();
}

int isExistingTeacher(char enrollment[]){

  FILE *file;
  Teacher teacher;

  file = fopen("db/teacher.txt","rb");

  if(file == NULL){
      printf("Error opening file!");

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