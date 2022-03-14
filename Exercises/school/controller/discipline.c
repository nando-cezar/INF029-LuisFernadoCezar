#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/student.h"
#include "../model/teacher.h"
#include "../model/discipline.h"
#include "../model/menu.h"

void createDiscipline(){

  FILE *file;
  Discipline discipline;
  char alternative;
  int verification;

  do{

    file = fopen("db/discipline.txt","ab");

    if(file == NULL){
      printf("Error opening file!");
      getchar();
    }else{
      
      header();
      discipline = insertDiscipline(discipline);
      strcpy(discipline.teacherEnrollment, retrieveTeacherSelected());
      fwrite(&discipline, sizeof(Discipline), 1, file);
      fclose(file); 
      
      do{
        printf("Deseja continuar (s/n)? ");
        scanf(" %c", &alternative);
        getchar();

        verification = validateAlternative(alternative);

        if (!verification){
          printf("Insira uma alternativa válida!\n\n");
        }
        
      }while(!verification);
    }
  }while(alternative == 's');
}

void insertStudentInDiscipline(){

  Discipline *ptrDiscipline;
  Teacher *ptrTeacher;
  size_t nRegDiscipline, nRegTeacher;
  int verification, idSelected, verificationStudent, sizeArray = 1, incrementStudent = 0;
  char alternative;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), "db/discipline.txt","rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), "db/teacher.txt","rb");

  if(ptrDiscipline == NULL || ptrTeacher == NULL){
    printf("Error opening array!");
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printDiscipline(ptrDiscipline[i], ptrTeacher[j]);
          sizeArray++;
        }
      }   
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    do{
      
      do{
        strcpy(ptrDiscipline[idSelected].studentEnrollment[incrementStudent], retrieveStudentSelected());
        verificationStudent = checkDisciplineStudent(ptrDiscipline[idSelected].code, ptrDiscipline[idSelected].studentEnrollment[incrementStudent]);
        
        if(!verificationStudent){
          printf("\nO aluno já se encontra matriculado na disciplina.\n");
          getchar();
        }    
      }while(!verificationStudent);

      do{
        printf("\n\nDeseja continuar(s/n)? ");
        scanf(" %c", &alternative);
        getchar();
        
        verification = validateAlternative(alternative);

        if(!verification)
          printf("\nInforme alternativa valida!\n\n");
          
      }while(!verification);
      
      if(alternative == 's')
        incrementStudent++;

    }while(alternative == 's'); 
    
    toFileDiscipline(&ptrDiscipline[idSelected], sizeof(Discipline), "db/discipline.txt","rb+", idSelected);

    free(ptrDiscipline);
    free(ptrTeacher);
  }
}

void retrieveDiscipline(){

  FILE *file;
  size_t nRegDiscipline, nRegTeacher;
  Discipline discipline, *ptrDiscipline;
  Teacher *ptrTeacher;
  int idSelected, sizeArray = 1;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), "db/discipline.txt","rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), "db/teacher.txt","rb");

  if(ptrDiscipline == NULL || ptrTeacher == NULL){
    printf("Error opening array!");
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printDiscipline(ptrDiscipline[i], ptrTeacher[j]);
        }
      }   
    }

    free(ptrDiscipline);
    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

Discipline retrieveDisciplineSelected(){
 
  Discipline *ptrDiscipline;
  Teacher *ptrTeacher;
  size_t nRegDiscipline, nRegTeacher;
  int idSelected, sizeArray = 1;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), "db/discipline.txt","rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), "db/teacher.txt","rb");

  if(ptrTeacher == NULL || ptrDiscipline == NULL){
    printf("Error opening array!");
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printDiscipline(ptrDiscipline[i], ptrTeacher[j]);
          sizeArray++;
        }
      }   
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));
    
    return ptrDiscipline[idSelected];
  }
}

void retrieveDisciplineWithStudent(){

  FILE *file;
  size_t nRegDiscipline, nRegTeacher, nRegStudent;
  Discipline discipline, *ptrDiscipline;
  Teacher *ptrTeacher;
  Student *ptrStudent;
  int idSelected, sizeArray = 1;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), "db/discipline.txt","rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), "db/teacher.txt","rb");
  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), "db/student.txt","rb");

  if(ptrDiscipline == NULL || ptrTeacher == NULL || ptrStudent == NULL){
    printf("Error opening array!");
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printDiscipline(ptrDiscipline[i], ptrTeacher[j]);
          sizeArray++;
        }
      }   
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    for(int i = 0; i < nRegStudent; i++){
      for(int j = 0; j < nRegStudent; j++){
        if(strcmp(ptrDiscipline[idSelected].studentEnrollment[i], ptrStudent[j].enrollment) == 0){
          printSummaryStudent(ptrStudent[j]);
        }
      }
    }

    free(ptrDiscipline);
    free(ptrTeacher);
    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void updateDiscipline(){

  FILE *file;
  size_t nRegDiscipline, nRegTeacher;
  Discipline discipline, *ptrDiscipline;
  Teacher *ptrTeacher;
  int idSelected, sizeArray = 1;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), "db/discipline.txt","rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), "db/teacher.txt","rb");

  if(ptrDiscipline == NULL || ptrTeacher == NULL){
    printf("Error opening array!");
  }else{

    header();
    
    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printDiscipline(ptrDiscipline[i], ptrTeacher[j]);
          sizeArray++;
        }
      }   
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    ptrDiscipline[idSelected] = insertDiscipline(discipline);
    strcpy(ptrDiscipline[idSelected].teacherEnrollment, retrieveTeacherSelected());

    toFileDiscipline(&ptrDiscipline[idSelected], sizeof(Discipline), "db/discipline.txt","rb+", idSelected);

    free(ptrDiscipline);
    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar..."); 
  }
  getchar();
}

void deleteDiscipline(){

  size_t nRegDiscipline, nRegTeacher;
  Discipline discipline, *ptrDiscipline;
  Teacher *ptrTeacher;
  int idSelected, sizeArray = 1;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), "db/discipline.txt","rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), "db/teacher.txt","rb");

  if(ptrDiscipline == NULL || ptrTeacher == NULL){
    printf("Error opening array!");
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printDiscipline(ptrDiscipline[i], ptrTeacher[j]);
          sizeArray++;
        }
      }   
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    /*
    -Atribui o último índice do ponteiro ao índice que será excluído
    -Realoca o ponteiro, retirando a última posição
    */
    ptrDiscipline[idSelected] = ptrDiscipline[nRegDiscipline-1];
    ptrDiscipline = (Discipline*) realloc(ptrDiscipline, --sizeArray * sizeof(Discipline)); 

    remove("db/discipline.txt");

    for(int i = 0; i < nRegDiscipline-1; i++){
      toFileDiscipline(&ptrDiscipline[i], sizeof(Discipline), "db/discipline.txt","ab", i);
    }

    free(ptrDiscipline);
    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void deleteStudentInDiscipline(){

  size_t nRegDiscipline, nRegTeacher, nRegStudent;
  Discipline *ptrDiscipline;
  Teacher *ptrTeacher;
  Student *ptrStudent;
  int idDisciplineSelected, sizeArrayDiscipline = 1;
  int idStudentSelected, sizeArrayStudent = 1;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), "db/discipline.txt","rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), "db/teacher.txt","rb");
  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), "db/student.txt","rb");

  if(ptrDiscipline == NULL || ptrTeacher == NULL || ptrStudent == NULL){
    printf("Error opening array!");
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printf("ID: %d\n", sizeArrayDiscipline);
          printDiscipline(ptrDiscipline[i], ptrTeacher[j]);
          sizeArrayDiscipline++;
        }
      }   
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idDisciplineSelected);
      getchar();
      idDisciplineSelected--;
    }while(!(idDisciplineSelected >= 0 && idDisciplineSelected < sizeArrayDiscipline-1));

      
    for(int i = 0, j = 0; i < nRegStudent; i++){
      if(strcmp(ptrDiscipline[idDisciplineSelected].studentEnrollment[j], ptrStudent[i].enrollment) == 0){
        printf("ID: %d\n", sizeArrayStudent);
        printSummaryStudent(ptrStudent[i]);
        sizeArrayStudent++;
        j++;
      } 
    }      

    do{
      printf("Informe o ID do estudante que deseja selecionar: ");
      scanf("%d", &idStudentSelected);
      getchar();
      idStudentSelected--;
    }while(!(idStudentSelected >= 0 && idStudentSelected < sizeArrayStudent-1));

      
    strcpy(ptrDiscipline[idDisciplineSelected].studentEnrollment[idStudentSelected], ptrDiscipline[idDisciplineSelected].studentEnrollment[nRegStudent-1]);
    strcpy(ptrDiscipline[idDisciplineSelected].studentEnrollment[nRegStudent-1], "\0");

    toFileDiscipline(&ptrDiscipline[idDisciplineSelected], sizeof(Discipline), "db/discipline.txt","rb+", idDisciplineSelected);

    free(ptrDiscipline);
    free(ptrTeacher);
    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

int isExistingDiscipline(char code[]){

  FILE *file;
  Discipline discipline;

  file = fopen("db/discipline.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    while(fread(&discipline,sizeof(discipline), 1, file) == 1){
      if(strcmp(discipline.code, code) == 0){
        fclose(file);
        return 0;
      }
    }
  }
  fclose(file);
  return 1;
}

int checkDisciplineStudent(char code[],char enrollment[]){


  FILE *file;
  Discipline discipline;

  file = fopen("db/discipline.txt","rb");

  if(file == NULL){
    printf("Error opening file!");
  }else{

    while(fread(&discipline,sizeof(discipline), 1, file) == 1){
        if(strcmp(discipline.code, code) == 0){
           for(int i = 0; i < MAX_STUDENTS_DISC; i++){
               if(strcmp(discipline.studentEnrollment[i], enrollment) == 0){
                fclose(file);
                return 0;
               }
           }
        }
    }
  }
  fclose(file);
  return 1;
}

Discipline* toPointerDiscipline(size_t *nReg, size_t size, char filePath[], char mode[]){

  FILE *file;
  Discipline* pointer = NULL;
  size_t fSize;

  file = fopen(filePath, mode);

  if(file == NULL){
    printf("Error opening file!");

  }else{

    fseek(file, 0L, SEEK_END);
    fSize = ftell(file);
    (*nReg) = fSize/size;
    rewind(file);
    
    pointer = (Discipline*) malloc(fSize);

    for(int i = 0; i < (*nReg); i++){
      fread(&pointer[i], size, 1, file);
    }

    fclose(file);
  }
  return pointer;
}

void toFileDiscipline(Discipline *ptrDiscipline, size_t size, char filePath[], char mode[], int idSelected){

  FILE *file;

  file = fopen(filePath, mode);

  if(file == NULL)
    printf("Error opening file!");
  else{

    fseek(file, idSelected * sizeof(Discipline), SEEK_SET);
    fwrite(ptrDiscipline, sizeof(Discipline), 1, file);

    fclose(file);
  }
}