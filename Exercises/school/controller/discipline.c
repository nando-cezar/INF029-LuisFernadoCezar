#include "../util/utility.h"
#include "../global/validation/validation.h"
#include "../global/function/function.h"
#include "../model/discipline.h"
#include "../model/menu.h"

void deleteDiscipline(){

  FILE *file;
  size_t fSize; //Tamanho do file 
  size_t nReg;  //Número de registros     
  Discipline discipline;
  Discipline *ptrDiscipline; //Ponteiro dinâmico para disciplina
  int idSelected, sizeArray = 1;
  int indexPtrDiscipline = 0;
  
  //Abrir arquivo no modo de leitura binário
  file = fopen("db/discipline.txt","rb"); 

  //Verificar erro na abertura do arquivo
  if(file == NULL){
    printf("Error opening file!");

  }else{

    fseek(file, 0L, SEEK_END); // Indo até a posição final
    fSize = ftell(file);  //Salvando o tamanho total do arquivo
    nReg = fSize/sizeof(Discipline); //Tamanho do arquivo / número de registros
    ptrDiscipline = (Discipline*) malloc(fSize); //Definindo ponteiro com tamanho fSize para discipline

    if(ptrDiscipline == NULL){
      printf("Error opening array!");
    }else{

      header();
      fseek(file, 0L, SEEK_SET); //Voltando para posição inicial

      /*
      -Lê todos os registros e atribui um ID de 1 a N para
      cada uma das disciplinas.
      -Atribui o valor de cada disciplina ao ptrDiscipline
      */
      while(fread(&discipline, sizeof(Discipline), 1, file) == 1){ 
        printf("ID: %d\n", sizeArray);
        printDiscipline(discipline);
        ptrDiscipline[indexPtrDiscipline] = discipline;
        indexPtrDiscipline++;
        sizeArray++;
      }


      //Ler o índice da disciplina qu será excluída
      printf("Informe o ID da disciplina que você quer excluir: ");
      scanf("%d", &idSelected);
      getchar();
      idSelected--;

      //Se for maior que zero e menor que o último item...
      if((idSelected >= 0) && (idSelected < sizeArray-1)) {

        /*
        -Atribui o último índice do ponteiro ao índice que será excluído
        -Realoca o ponteiro, retirando a última posição
        */
        ptrDiscipline[idSelected] = ptrDiscipline[nReg-1];
        ptrDiscipline = (Discipline*) realloc(ptrDiscipline, --sizeArray * sizeof(Discipline)); 
      
        //Fechar, excluir e abrir um novo arquivo 
        fclose(file);
        remove("db/discipline.txt");
        file = fopen("db/discipline.txt","ab");

        //Verificar se o arquivo foi aberto com sucesso
        if (file == NULL) {
          printf("Error opening file!");
        }else{
          for(int j = 0; j < nReg-1; j++){
            strcpy(discipline.code, ptrDiscipline[j].code);
            strcpy(discipline.name, ptrDiscipline[j].name);
            discipline.semester = ptrDiscipline[j].semester;
            fwrite(&discipline, sizeof(Discipline), 1, file);
          }
        }
      }else{
        printf("Invalide code!");
      }
    }
  }
  fclose(file);
}

void createDiscipline(){

  FILE *file;
  Discipline discipline;
  char c;
  int verification;

  file = fopen("db/discipline.txt","ab"); //Abrir arquivo


  //Verificar erro na abertura
  if(file == NULL){
    printf("Error opening file!");

  }else{

    do{
      header();
      discipline = insertDiscipline(discipline);
      fwrite(&discipline, sizeof(Discipline), 1, file);

      do{
        printf("Deseja continuar (s/n)? ");
        scanf("%c", &c);

        verification = validateAlternative(c);

        if (!verification){
          printf("Insira uma alternativa válida! ");
        }
        
      }while (!verification);

    }while (c == 'S');
    fclose(file); 
  }
  
}

Discipline insertDiscipline(Discipline discipline){
  
  size_t ln;
  int verification;

  //.code
  printf("Insira o código da disciplina: ");
  fgets(discipline.code, MAX_ENR_LEN, stdin);
  ln = strlen(discipline.code) - 1;
  if (discipline.code[ln] == '\n')
    discipline.code[ln] = '\0';
  textToUpper(discipline.code, strlen(discipline.code));

  
  //.name
  printf("Insira o nome da disciplina: ");
  fgets(discipline.name, MAX_NAME_LEN, stdin);
  ln = strlen(discipline.name) - 1;
  if (discipline.name[ln] == '\n')
    discipline.name[ln] = '\0';
  textToUpper(discipline.name, strlen(discipline.name));


  //.semester
  printf("Insira o semestre: ");
  scanf("%d", &discipline.semester);
  getchar();

  return discipline;
}

void retrieveDiscipline(){

  FILE *file;
  Discipline discipline;

  file = fopen("db/discipline.txt","rb");

  if(file == NULL){
    printf("Error opening file!");

  }else{
    header();

    while(fread(&discipline, sizeof(Discipline), 1, file) == 1){   
      printDiscipline(discipline);
    }
    printf("Pressione qualquer tecla para voltar...");
  }
  fclose(file);
  getchar();
}


