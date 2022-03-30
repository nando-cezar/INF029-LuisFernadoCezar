#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/student.h"
#include "../model/teacher.h"
#include "../model/discipline.h"
#include "../model/menu.h"

void createDiscipline(){

  FILE *file;
  size_t nRegTeacher;
  Discipline discipline;
  Teacher *ptrTeacher, dataTeacher;
  char *teacherEnrollmentSelected = (char*)malloc(MAX_ENR_LEN * sizeof(char));
  char alternative;
  int verification, incrementDiscipline = 0;

  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR); 
    getchar();
  }else{

    do{

      file = fopen(DISCIPLINE_PATH,"ab");

      if(file == NULL){
        printf(MESSAGE_ERROR); 
        getchar();
      }else{

        header();
        discipline = insertCreateDiscipline(discipline);

        teacherEnrollmentSelected = retrieveEnrollmentTeacher();
        dataTeacher = retrieveDataTeacher(teacherEnrollmentSelected);

        for(int n = 0; n < MAX_DISC; n++){
          if(strcmp(dataTeacher.disciplineCode[n], "\0") != 0)
            incrementDiscipline++;
        }

        if(incrementDiscipline >= MAX_DISC){
          printf("Não a mais limite de disciplinas para o professor escolhido.");
          free(ptrTeacher);
          fclose(file);
          getchar();
          return;
        }

        strcpy(discipline.teacherEnrollment, teacherEnrollmentSelected);

        fwrite(&discipline, sizeof(Discipline), 1, file);
        fclose(file);

        for(int i = 0; i < nRegTeacher; i++){
          if(strcmp(ptrTeacher[i].enrollment, discipline.teacherEnrollment) == 0){
            strcpy(ptrTeacher[i].disciplineCode[incrementDiscipline], discipline.code);
            toFileTeacher(&ptrTeacher[i], sizeof(Teacher), TEACHER_PATH,"rb+", i);
          }
        } 
      
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
  free(ptrTeacher);
}

void insertStudentInDiscipline(){

  Discipline *ptrDiscipline, disciplineSelected;
  Student *ptrStudent, dataStudent;
  size_t nRegTeacher, nRegStudent, nRegDiscipline;
  int verification, idSelected, sizeArray = 1;
  int incrementDiscipline;
  int verificationStudent, incrementStudent = 0;
  char alternative, studentEnrollment[MAX_ENR_LEN];

  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), STUDENT_PATH,"rb");
  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), DISCIPLINE_PATH,"rb");

  if(ptrStudent == NULL || ptrDiscipline == NULL){
    printf(MESSAGE_ERROR);
  }else{

    disciplineSelected = retrieveObjectDiscipline(&idSelected, &sizeArray);

    for(int n = 0; n < MAX_STUDENTS_DISC; n++){
      if(strcmp(disciplineSelected.studentEnrollment[n], "\0") != 0)
        incrementStudent++;
    }

    do{
      
      incrementDiscipline = 0;

      do{
        
        strcpy(disciplineSelected.studentEnrollment[incrementStudent], retrieveEnrollmentStudent());
        strcpy(studentEnrollment, disciplineSelected.studentEnrollment[incrementStudent]);
        verificationStudent = checkStudentInDiscipline(disciplineSelected.code, disciplineSelected.studentEnrollment[incrementStudent]);
        
        if(!verificationStudent){
          printf("\nO aluno já se encontra matriculado na disciplina.\n");
          getchar();
          return;
        }    
      }while(!verificationStudent);

      //*********************************
      dataStudent = retrieveDataStudent(studentEnrollment);

      for(int n = 0; n < MAX_DISC; n++){
        if(strcmp(dataStudent.disciplineCode[n], "\0") != 0)
          incrementDiscipline++;
      }
      
      for(int i = 0; i < nRegStudent; i++){
        if(strcmp(ptrStudent[i].enrollment, studentEnrollment) == 0){
          strcpy(ptrStudent[i].disciplineCode[incrementDiscipline], disciplineSelected.code);
          toFileStudent(&ptrStudent[i], sizeof(Student), STUDENT_PATH,"rb+", i);
        }
      }
      //

      toFileDiscipline(&disciplineSelected, sizeof(Discipline), DISCIPLINE_PATH,"rb+", idSelected);

      do{
        printf("\n\nDeseja continuar(s/n)? ");
        scanf(" %c", &alternative);
        getchar();
        
        verification = validateAlternative(alternative);

        if(!verification)
          printf("\nInforme alternativa valida!\n\n");
          
      }while(!verification);
      
      if(alternative == 's'){
        incrementStudent++;
        incrementDiscipline++;
      }

    }while(alternative == 's'); 
    
    free(ptrStudent);
    free(ptrDiscipline);
  }
}

void retrieveDiscipline(){

  size_t nRegDiscipline, nRegTeacher;
  Discipline *ptrDiscipline;
  Teacher *ptrTeacher;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), DISCIPLINE_PATH,"rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrDiscipline == NULL || ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printSummaryDiscipline(ptrDiscipline[i], ptrTeacher[j]);
        }
      }   
    }

    free(ptrDiscipline);
    free(ptrTeacher);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

Discipline retrieveObjectDiscipline(int *idSelected, int *sizeArray){
 
  Discipline *ptrDiscipline;
  Teacher *ptrTeacher;
  size_t nRegDiscipline, nRegTeacher;
  int id = 0;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), DISCIPLINE_PATH,"rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL || ptrDiscipline == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      for(int j = 0; j < nRegTeacher; j++){ 
        if(strcmp(ptrDiscipline[i].teacherEnrollment, ptrTeacher[j].enrollment) == 0){
          printf("ID: %d\n", *sizeArray);
          printSummaryDiscipline(ptrDiscipline[i], ptrTeacher[j]);
          (*sizeArray)++;
        }
      }   
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &id);
      getchar();
      *idSelected = id;
      (*idSelected)--;
    }while(!(*idSelected >= 0 && *idSelected < *sizeArray-1));
    
    return ptrDiscipline[*idSelected];
  }
}

void retrieveDisciplineWithStudent(){

  size_t nRegTeacher, nRegStudent;
  Discipline disciplineSelected;
  Student *ptrStudent;
  int idSelected = 0, sizeArray = 1;

  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    disciplineSelected = retrieveObjectDiscipline(&idSelected, &sizeArray);

    for(int i = 0; i < MAX_STUDENTS_DISC; i++){
      for(int j = 0; j < nRegStudent; j++){
        if(strcmp(disciplineSelected.studentEnrollment[i], ptrStudent[j].enrollment) == 0){
          printSummaryStudent(ptrStudent[j]);
        }
      }
    }

    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void retrieveDisciplineWithMoreThan40Students(){

  size_t nRegDiscipline = 0;
  Discipline *ptrDiscipline;
  int values[nRegDiscipline];

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), DISCIPLINE_PATH,"rb");

  if(ptrDiscipline == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    for(int i = 0; i < nRegDiscipline; i++){ 
      values[i] = 0;
      for(int j = 0; strcmp(ptrDiscipline[i].studentEnrollment[j], "\0") != 0; j++){
        values[i] += 1;
      }
    }
    for(int i = 0; i < nRegDiscipline; i++){
      if(values[i] > 40){
        printMaxSummaryDiscipline(ptrDiscipline[i]);
      }
    }

    free(ptrDiscipline);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void updateDiscipline(){

  Discipline disciplineSelected;
  Teacher *ptrTeacher;
  size_t nRegTeacher;
  int idSelected = -1, sizeArray = 1;
  char *newTeacher = (char*)malloc(MAX_ENR_LEN * sizeof(char));
  char *oldTeacher = (char*)malloc(MAX_ENR_LEN * sizeof(char));

  //Abrir professor
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), TEACHER_PATH,"rb");

  if(ptrTeacher == NULL){
    printf(MESSAGE_ERROR);
  }else{

    disciplineSelected = retrieveObjectDiscipline(&idSelected, &sizeArray);

    if(idSelected != -1){
      disciplineSelected = insertUpdateDiscipline(disciplineSelected);
      
      //Guardando o professor novo e antigo em variáveis
      newTeacher = retrieveEnrollmentTeacher();
      strcpy(oldTeacher, disciplineSelected.teacherEnrollment);

      //Se o novo professor for diferente do professor atual
      if (strcmp(newTeacher, oldTeacher) != 0){
        //printf("Professores diferentes. ");
        strcpy(disciplineSelected.teacherEnrollment, newTeacher);

        //Encontrar o professor antigo (i)
        for (int i = 0; i < nRegTeacher; i++){
          if (strcmp(ptrTeacher[i].enrollment, oldTeacher) == 0){
            /*Encontrar a disciplina dentro de professor. (j)*/
            for (int j = 0; j < MAX_DISC; j++){
              if (strcmp(ptrTeacher[i].disciplineCode[j], disciplineSelected.code) == 0){
                for(int k = j; k <= MAX_DISC; k++){
                  if (k == MAX_DISC)
                    strcpy(ptrTeacher[i].disciplineCode[k], "\0");
                  else
                    strcpy(ptrTeacher[i].disciplineCode[k], ptrTeacher[i].disciplineCode[k + 1]);
                }
                break;
              } 
            }
          }else if (strcmp(ptrTeacher[i].enrollment, newTeacher) == 0){
            /*Encontrar a disciplina dentro de professor. (j)*/
            for (int j = 0;  j < MAX_DISC; j++){
              if (strcmp(ptrTeacher[i].disciplineCode[j], "\0") == 0){
                strcpy(ptrTeacher[i].disciplineCode[j], disciplineSelected.code);
                break;
              } 
            }
          }

          toFileTeacher(&ptrTeacher[i], sizeof(Teacher), TEACHER_PATH,"rb+", i);
        }
      }
      
      toFileDiscipline(&disciplineSelected, sizeof(Discipline), DISCIPLINE_PATH,"rb+", idSelected);
      
      printf("Pressione qualquer tecla para voltar..."); 
    }
  }

  getchar();
}

void deleteDiscipline(){

  size_t nRegDiscipline, nRegTeacher, nRegStudent;
  Discipline disciplineSelected, *ptrDiscipline;
  Teacher *ptrTeacher;
  Student *ptrStudent;
  int idSelected = 0, sizeArray = 1, quantity = 0;

  ptrDiscipline = toPointerDiscipline(&nRegDiscipline, sizeof(Discipline), DISCIPLINE_PATH,"rb");
  ptrTeacher = toPointerTeacher(&nRegTeacher, sizeof(Teacher), TEACHER_PATH,"rb");
  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrDiscipline == NULL || ptrTeacher == NULL || ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    header();

    disciplineSelected = retrieveObjectDiscipline(&idSelected, &sizeArray);

    for(int i = 0; i < MAX_STUDENTS_DISC; i++){
      printf("%s\n", disciplineSelected.studentEnrollment[i]); //debug
      if (strcmp(disciplineSelected.studentEnrollment[i], "\0") != 0)
        quantity++;
    }
    
    if(quantity == 0){

      for(int i = 0; i < nRegTeacher; i++){
        if(strcmp(disciplineSelected.teacherEnrollment, ptrTeacher[i].enrollment) == 0){
          for(int j = 0; j < MAX_DISC; j++){
            if(strcmp(ptrTeacher[i].disciplineCode[j], disciplineSelected.code) == 0){
              for(int k = j; k <= MAX_DISC; k++){
                if (k == MAX_DISC) 
                  strcpy(ptrTeacher[i].disciplineCode[k], "\0");
                else
                  strcpy(ptrTeacher[i].disciplineCode[k], ptrTeacher[i].disciplineCode[k+1]);
              }
              toFileTeacher(&ptrTeacher[i], sizeof(Teacher), TEACHER_PATH,"rb+", i);
            }
          }
          break;      
        }
      }

      ptrDiscipline[idSelected] = ptrDiscipline[nRegDiscipline-1];
      ptrDiscipline = (Discipline*) realloc(ptrDiscipline, --sizeArray * sizeof(Discipline)); 

      remove(DISCIPLINE_PATH);

      for(int i = 0; i < nRegDiscipline-1; i++){
        toFileDiscipline(&ptrDiscipline[i], sizeof(Discipline), DISCIPLINE_PATH,"ab", i);
      }
    }else{
      printf("A disciplina se encontra vinculada a um ou mais alunos!\n");
    }

    free(ptrTeacher);
    free(ptrDiscipline);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void deleteStudentInDiscipline(){

  size_t nRegStudent;
  Student *ptrStudent;
  Discipline disciplineSelected;
  int idDisciplineSelected, sizeArrayDiscipline = 1;
  int idStudentSelected, sizeArrayStudent = 1;
  int indexStudentEnrolled = 0;
  char studentEnrollment[MAX_ENR_LEN];

  ptrStudent = toPointerStudent(&nRegStudent, sizeof(Student), STUDENT_PATH,"rb");

  if(ptrStudent == NULL){
    printf(MESSAGE_ERROR);
  }else{

    disciplineSelected = retrieveObjectDiscipline(&idDisciplineSelected, &sizeArrayDiscipline);
      
    for(int i = 0; strcmp(disciplineSelected.studentEnrollment[indexStudentEnrolled], "\0") != 0; i++){
      if(strcmp(disciplineSelected.studentEnrollment[indexStudentEnrolled], ptrStudent[i].enrollment) == 0){
        printf("ID: %d\n", sizeArrayStudent);
        printSummaryStudent(ptrStudent[i]);
        sizeArrayStudent++;
        indexStudentEnrolled++;
      } 
    }      

    if(indexStudentEnrolled > 0){

      do{
        printf("Informe o ID do estudante que deseja selecionar: ");
        scanf("%d", &idStudentSelected);
        getchar();
        idStudentSelected--;
      }while(!(idStudentSelected >= 0 && idStudentSelected < sizeArrayStudent-1));

      strcpy(studentEnrollment, disciplineSelected.studentEnrollment[idStudentSelected]);

      strcpy(disciplineSelected.studentEnrollment[idStudentSelected], disciplineSelected.studentEnrollment[sizeArrayStudent-1]);
      strcpy(disciplineSelected.studentEnrollment[sizeArrayStudent-1], "\0");

      for (int h = idStudentSelected; h < MAX_STUDENTS_DISC; h++){
        strcpy(disciplineSelected.studentEnrollment[h],  disciplineSelected.studentEnrollment[h+1]);
      }
      
      //***************************
      for(int i = 0; i < nRegStudent; i++){
        if(strcmp(studentEnrollment, ptrStudent[i].enrollment) == 0){
          for(int j = 0; j < MAX_DISC; j++){
            if(strcmp(ptrStudent[i].disciplineCode[j], disciplineSelected.code) == 0){
              strcpy(ptrStudent[i].disciplineCode[j], "\0");
              for(int k = j; k <= MAX_DISC; k++){
                if (k = MAX_DISC)
                  strcpy(ptrStudent[i].disciplineCode[k], "\0");
                else
                  strcpy(ptrStudent[i].disciplineCode[k], ptrStudent[i].disciplineCode[k+1]);
              } 
              toFileStudent(&ptrStudent[i], sizeof(Student), STUDENT_PATH,"rb+", i);
            }
          } 
          break;     
        }
      }
      //
      toFileDiscipline(&disciplineSelected, sizeof(Discipline), DISCIPLINE_PATH,"rb+", idDisciplineSelected);

    }
    
    free(ptrStudent);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

int isExistingDiscipline(char code[]){

  size_t nReg;
  Discipline *ptrDiscipline;

  ptrDiscipline = toPointerDiscipline(&nReg, sizeof(Discipline), DISCIPLINE_PATH,"rb");

  if(ptrDiscipline == NULL){
    printf(MESSAGE_ERROR);
 
  }else{

    textToUpper(code);

    for(int i = 0; i < nReg; i++){
      if(strcmp(ptrDiscipline[i].code, code) == 0){
        free(ptrDiscipline);
        return 0;
      }
    }
  }
  free(ptrDiscipline);
  return 1;
}

int checkStudentInDiscipline(char code[], char enrollment[]){

  size_t nReg;
  Discipline *ptrDiscipline;

  ptrDiscipline = toPointerDiscipline(&nReg, sizeof(Discipline), DISCIPLINE_PATH,"rb");

  if(ptrDiscipline == NULL){
      printf(MESSAGE_ERROR);

  }else{

    for(int i = 0; i < nReg; i++){
        if(strcmp(ptrDiscipline[i].code, code) == 0){
          for(int j = 0; j < MAX_STUDENTS_DISC; j++){
            if(strcmp(ptrDiscipline[i].studentEnrollment[j], enrollment) == 0){
              free(ptrDiscipline);
              return 0;
            } 
          }
      }
    }
  }
  free(ptrDiscipline);
  return 1;
}

Discipline* toPointerDiscipline(size_t *nReg, size_t size, char filePath[], char mode[]){

  FILE *file;
  Discipline* pointer = NULL;
  size_t fSize;

  file = fopen(filePath, mode);

  if(file == NULL){
    printf(MESSAGE_ERROR);

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
    printf(MESSAGE_ERROR);
  else{

    fseek(file, idSelected * sizeof(Discipline), SEEK_SET);
    fwrite(ptrDiscipline, sizeof(Discipline), 1, file);

    fclose(file);
  }
}