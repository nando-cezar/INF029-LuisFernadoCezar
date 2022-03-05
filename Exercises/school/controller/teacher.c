#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../model/teacher.h"
#include "../model/menu.h"
#include "../global/function/function.h"

void createTeacher(){

  FILE * file;
  Teacher teacher;
  char alternative;
  int verification;

  file = fopen("db/teacher.txt","ab");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    do{
      header();
      teacher = insertTeacher(teacher);
      fwrite(&teacher, sizeof(Teacher), 1, file);

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
  }
  fclose(file);
  getchar();
}

void retrieveTeacherByGender(){

  FILE *file;
  Teacher teacher;
  char gender;
  int verification;

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

    }while(!verification);

    while(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 

      if(teacher.gender == gender){
        printTeacher(teacher);
      }
    }
  }
  fclose(file);
  getchar();
}

void retrieveTeacherByName(){
  
  FILE *file;
  Teacher teacher, *ptrTeacher; 
  int counter = 0, auxiliary = 0, verification = 0;
  char nameSearch[MAX_NAME_LEN], *ret;
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
      printf("\n\n");

      if(sizeNameSearch < 3){
        printf("\nDigite no mínimo 3 caracteres.");
        getchar();
      }
    }while(sizeNameSearch < 3);

    counter = structAmount(file, &teacher, sizeof(Teacher));
    ptrTeacher = (Teacher*) malloc(counter * sizeof(Teacher));
   
    while(fread(&ptrTeacher[auxiliary],sizeof(ptrTeacher[auxiliary]), 1, file) == 1){

      ret = strstr(ptrTeacher[auxiliary].name, nameSearch);
      if(ret){
        printTeacher(ptrTeacher[auxiliary]);
        verification++;
      }   
      auxiliary++;
    }

    if(verification==0) printf("\n\nNão encontrado!");
    else verification = 0;  
  }
  free(ptrTeacher);
  fclose(file);
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
    printf("%d", counter);
    getchar();
    ptrTeacher = (Teacher*) malloc(counter * sizeof(Teacher));
   
    while(fread(&ptrTeacher[auxiliary++], sizeof(ptrTeacher[auxiliary]), 1, file) == 1);

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
    
  }
  free(ptrTeacher);
  fclose(file);
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

    counter = structAmount(file, &teacher, sizeof(Teacher));   
    ptrTeacher = (Teacher*) malloc(counter * sizeof(Teacher));

    while(fread(&ptrTeacher[auxiliary++], sizeof(ptrTeacher[auxiliary]), 1, file) == 1);

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
    
  }
  free(ptrTeacher);
  fclose(file);
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
    printf("\n\n");

    while(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 

      if(teacher.birthDate.month == month){
        printTeacher(teacher);
      }
    }
  }
  fclose(file);
  getchar();
}

void updateTeacher(){

  FILE *file;
  Teacher teacher;
  int id, identity = 1;

  file = fopen("db/teacher.txt","rb+");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();

    while(fread(&teacher, sizeof(Teacher), 1, file) == 1){ 
      printf("ID: %d\n", identity);
      printTeacher(teacher);
      identity++;
    }

    printf("Informe o ID do aluno que deseja alterar: ");
    scanf("%d", &id);
    getchar();
    id--;

    if(id >= 0 && id < identity-1) {
      teacher = insertTeacher(teacher);
      fseek(file, id * sizeof(Teacher), SEEK_SET);
      fwrite(&teacher, sizeof(Teacher), 1, file);
    }

  }
  fclose(file);
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

      printf("Informe o ID do aluno que deseja excluir: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;

      if(idSelected >= 0 && idSelected < sizeArray-1) {

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
      }else{
        printf("Invalide code!");
      }

    }
  }
  fclose(file);
  getchar();
}