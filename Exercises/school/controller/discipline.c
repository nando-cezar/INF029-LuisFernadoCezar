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

  FILE *dfile, *tfile;
  Discipline discipline;
  Teacher teacher;
  int verification, idSelected, verificationStudent, sizeArray = 1, incrementStudent = 0;
  char alternative;
  char studentEnrollment[MAX_STUDENTS_DISC][MAX_ENR_LEN];

  dfile = fopen("db/discipline.txt","rb+");
  tfile = fopen("db/teacher.txt","rb");

  if(dfile == NULL && tfile == NULL){
    printf("Error opening file!");
    getchar();
  }else{

    header();
    while(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){ 
      while(fread(&teacher, sizeof(Teacher), 1, tfile) == 1){
        if(strcmp(discipline.teacherEnrollment, teacher.enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printSummaryDiscipline(discipline, teacher);
          sizeArray++;
        }
      }  
      fseek(tfile, 0L, SEEK_SET); 
    }

    do{
      printf("Informe o ID da disciplina que deseja inserir o estudante: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));
    
    do{
      
      do{
        strcpy(studentEnrollment[incrementStudent], retrieveStudentSelected());

        fseek(dfile, idSelected * sizeof(Discipline), SEEK_SET);
        if(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){
          verificationStudent = checkDisciplineStudent
          (
            discipline.code, 
            studentEnrollment[incrementStudent]
          );
        }

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

    fseek(dfile, idSelected * sizeof(Discipline), SEEK_SET);
    if(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){
      for(int i = 0; i <= incrementStudent; i++){
        strcpy(discipline.studentEnrollment[i], studentEnrollment[i]);
      }
    }
    
    fseek(dfile, idSelected * sizeof(Discipline), SEEK_SET);
    fwrite(&discipline, sizeof(Discipline), 1, dfile);

    fclose(dfile);
    fclose(tfile);
  }
}

void retrieveDiscipline(){

  FILE *dfile, *tfile;
  Discipline discipline;
  Teacher teacher;

  dfile = fopen("db/discipline.txt","rb");
  tfile = fopen("db/teacher.txt","rb");

  if(dfile == NULL && tfile == NULL){
    printf("Error opening file!");
  }else{
    header();
    while(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){ 
      while(fread(&teacher, sizeof(Teacher), 1, tfile) == 1){ 
        if(strcmp(discipline.teacherEnrollment, teacher.enrollment) == 0){
          printDiscipline(discipline, teacher);
        }
      }   
      fseek(tfile, 0L, SEEK_SET);
    }
    fclose(dfile);
    fclose(tfile);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

Discipline retrieveDisciplineSelected(){

  FILE *dfile, *tfile;
  Discipline discipline, auxiliaryDiscipline;
  Teacher teacher;
  int idSelected, sizeArray = 1;

  dfile = fopen("db/discipline.txt","rb");
  tfile = fopen("db/teacher.txt","rb");

  if(dfile == NULL && tfile == NULL){
    printf("Error opening file!");

  }else{

    header();
    while(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){ 
      while(fread(&teacher, sizeof(Teacher), 1, tfile) == 1){
        if(strcmp(discipline.teacherEnrollment, teacher.enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printSummaryDiscipline(discipline, teacher);
          sizeArray++;
        }
      }  
      fseek(tfile, 0L, SEEK_SET); 
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    fseek(dfile, idSelected * sizeof(Discipline), SEEK_SET);
    if(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){ 
      auxiliaryDiscipline = discipline;
    }
    
    fclose(dfile);
    fclose(tfile);
    return auxiliaryDiscipline;
  }
}

void retrieveDisciplineWithStudent(){

  FILE *dfile, *tfile, *sfile;
  Discipline discipline;
  Teacher teacher;
  Student student;
  int idSelected, sizeArray = 1, incrementStudent = 0;

  dfile = fopen("db/discipline.txt","rb");
  tfile = fopen("db/teacher.txt","rb");
  sfile = fopen("db/student.txt","rb");

  if(dfile == NULL && tfile == NULL && sfile == NULL){
    printf("Error opening file!");
  }else{
    header();
    while(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){ 
      while(fread(&teacher, sizeof(Teacher), 1, tfile) == 1){
        if(strcmp(discipline.teacherEnrollment, teacher.enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printSummaryDiscipline(discipline, teacher);
          sizeArray++;
        }
      }  
      fseek(tfile, 0L, SEEK_SET); 
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    fseek(dfile, idSelected * sizeof(Discipline), SEEK_SET);
    if(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){
      while(fread(&student, sizeof(Student), 1, sfile) == 1){
        if(strcmp(discipline.studentEnrollment[incrementStudent], student.enrollment) == 0){
         printSummaryStudent(student);
         incrementStudent ++; 
        }
      }
      fseek(sfile, 0L, SEEK_SET);
    }

    fclose(dfile);
    fclose(tfile);
    fclose(sfile);
    printf("Pressione qualquer tecla para voltar...");
  }
  getchar();
}

void updateDiscipline(){

  FILE *dfile, *tfile;
  Discipline discipline;
  Teacher teacher;
  int idSelected, sizeArray = 1;

  dfile = fopen("db/discipline.txt","rb+");
  tfile = fopen("db/teacher.txt","rb");

  if(dfile == NULL && tfile == NULL){
    printf("Error opening file!");

  }else{

    header();
    while(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){ 
      while(fread(&teacher, sizeof(Teacher), 1, tfile) == 1){
        if(strcmp(discipline.teacherEnrollment, teacher.enrollment) == 0){
          printf("ID: %d\n", sizeArray);
          printDiscipline(discipline, teacher);
          sizeArray++;
        }
      }   
      fseek(tfile, 0L, SEEK_SET);
    }

    do{
      printf("Informe o ID da disciplina que deseja selecionar: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;
    }while(!(idSelected >= 0 && idSelected < sizeArray-1));

    discipline = insertDiscipline(discipline);
    strcpy(discipline.teacherEnrollment, retrieveTeacherSelected());
    fseek(dfile, idSelected * sizeof(Discipline), SEEK_SET);
    fwrite(&discipline, sizeof(Discipline), 1, dfile);
    
    fclose(dfile);
    fclose(tfile);
    printf("Pressione qualquer tecla para voltar..."); 
  }
  getchar();
}

void deleteDiscipline(){

  FILE *dfile, *tfile;
  size_t fSize, nReg;
  Discipline discipline, *ptrDiscipline;
  Teacher teacher;
  int idSelected, sizeArray = 1, indexPtrDiscipline = 0;

  dfile = fopen("db/discipline.txt","rb");
  tfile = fopen("db/teacher.txt","rb");

  if(dfile == NULL && tfile == NULL){
    printf("Error opening file!");

  }else{

    fseek(dfile, 0L, SEEK_END); // Indo até a posição final
    fSize = ftell(dfile);  //Salvando o tamanho total do arquivo
    nReg = fSize/sizeof(Discipline); // número de registros = Tamanho do arquivo / quantidade de bytes da struct
    ptrDiscipline = (Discipline*) malloc(fSize); //Definindo ponteiro com tamanho fSize para discipline

    if(ptrDiscipline == NULL){
      printf("Error opening array!");
    }else{

      header();
      fseek(dfile, 0L, SEEK_SET); //Voltando para posição inicial

      /*
      -Lê todos os registros e atribui um ID de 1 a N para
      cada uma das disciplinas.
      -Atribui o valor de cada disciplina ao ptrDiscipline
      */
      while(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){ 
        while(fread(&teacher, sizeof(Teacher), 1, tfile) == 1){
          if(strcmp(discipline.teacherEnrollment, teacher.enrollment) == 0){
            printf("ID: %d\n", sizeArray);
            printDiscipline(discipline, teacher);
            ptrDiscipline[indexPtrDiscipline] = discipline;
            indexPtrDiscipline++;
            sizeArray++;
          }
        }   
        fseek(tfile, 0L, SEEK_SET);
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
      ptrDiscipline[idSelected] = ptrDiscipline[nReg-1];
      ptrDiscipline = (Discipline*) realloc(ptrDiscipline, --sizeArray * sizeof(Discipline)); 
    
      //Fechar, excluir e abrir um novo arquivo 
      fclose(dfile);
      remove("db/discipline.txt");
      dfile = fopen("db/discipline.txt","ab");

      //Verificar se o arquivo foi aberto com sucesso
      if (dfile == NULL) {
        printf("Error opening file!");
      }else{

        for(int j = 0; j < nReg-1; j++){
          strcpy(discipline.code, ptrDiscipline[j].code);
          strcpy(discipline.name, ptrDiscipline[j].name);
          discipline.semester = ptrDiscipline[j].semester;
          strcpy(discipline.teacherEnrollment, ptrDiscipline[j].teacherEnrollment);
          fwrite(&discipline, sizeof(Discipline), 1, dfile);
        }
      }
      free(ptrDiscipline);
      fclose(dfile);
      fclose(tfile);
      printf("Pressione qualquer tecla para voltar...");
    }
  }
  getchar();
}

void deleteStudentInDiscipline(){

  FILE *dfile, *tfile, *sfile;
  size_t fSize, nReg;
  Discipline discipline, *ptrDiscipline;
  Teacher teacher;
  Student student;
  int idDisciplineSelected, sizeArrayDiscipline = 1,  indexPtrDiscipline = 0;
  int idStudentSelected, sizeArrayStudent = 1, incrementStudent = 0;

  dfile = fopen("db/discipline.txt","rb");
  tfile = fopen("db/teacher.txt","rb");
  sfile = fopen("db/student.txt","rb");

  if(dfile == NULL && tfile == NULL && sfile == NULL){
    printf("Error opening file!");
  }else{

    fseek(dfile, 0L, SEEK_END); 
    fSize = ftell(dfile);  
    nReg = fSize/sizeof(Discipline);
    ptrDiscipline = (Discipline*) malloc(fSize);

    if(ptrDiscipline == NULL){
      printf("Error opening array!");
    }else{

      header();
      while(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){ 
        while(fread(&teacher, sizeof(Teacher), 1, tfile) == 1){
          if(strcmp(discipline.teacherEnrollment, teacher.enrollment) == 0){
            printf("ID: %d\n", sizeArrayDiscipline);
            printSummaryDiscipline(discipline, teacher);
            ptrDiscipline[indexPtrDiscipline] = discipline;
            indexPtrDiscipline++;
            sizeArrayDiscipline++;
          }
        }  
        fseek(tfile, 0L, SEEK_SET); 
      }

      do{
        printf("Informe o ID da disciplina que deseja selecionar: ");
        scanf("%d", &idDisciplineSelected);
        getchar();
        idDisciplineSelected--;
      }while(!(idDisciplineSelected >= 0 && idDisciplineSelected < sizeArrayDiscipline-1));

      fseek(dfile, idDisciplineSelected * sizeof(Discipline), SEEK_SET);
      if(fread(&discipline, sizeof(Discipline), 1, dfile) == 1){
        while(fread(&student, sizeof(Student), 1, sfile) == 1){
          if(strcmp(discipline.studentEnrollment[incrementStudent], student.enrollment) == 0){
            printf("ID: %d\n", sizeArrayStudent);
            printSummaryStudent(student);
            sizeArrayStudent++;
            incrementStudent ++; 
          }
        }
        fseek(sfile, 0L, SEEK_SET);
      }

      do{
        printf("Informe o ID do estudante que deseja selecionar: ");
        scanf("%d", &idStudentSelected);
        getchar();
        idStudentSelected--;
      }while(!(idStudentSelected >= 0 && idStudentSelected < sizeArrayStudent-1));

      /*implements*/
      strcpy(ptrDiscipline[idDisciplineSelected].studentEnrollment[idStudentSelected], ptrDiscipline[idDisciplineSelected].studentEnrollment[sizeArrayStudent-1]);
      for(int i = 0; i < sizeArrayStudent-1; i++){
        printf("---->> %s", ptrDiscipline[idDisciplineSelected].studentEnrollment[i]);
      }

      //ptrDiscipline[idDisciplineSelected].studentEnrollment = (Discipline*) realloc([idDisciplineSelected].studentEnrollment, --sizeArrayStudent * sizeof(Discipline)); 

      /*for(int i = 0; i < sizeArrayStudent-1; i++){
        printf("---->> %s", ptrDiscipline[idDisciplineSelected].studentEnrollment[i]);
      }*/
      fclose(dfile);
      fclose(tfile);
      fclose(sfile);
      printf("Pressione qualquer tecla para voltar...");
    }
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