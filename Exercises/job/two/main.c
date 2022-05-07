#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

#if defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
    #include <unistd.h>
#endif

void menu();
void menuCriarEstruturaAuxiliar();
void menuInserirValorNaEstrutura();
void menuExcluirNumeroDoFinaldaEstrutura();
//void menuExcluirNumeroEspecificoDeEstrutura();
//void menuDadosEstruturaAuxiliar();
void menuVerificacao(int validacao);


int main(){
  inicializar();
  menu();
  finalizar();
}

void menu(){
  int op = 0,posicao = 0, tamanho = 0;

  do{
    printf("---------------------------\n");
    printf("        Trabalho 2         ");
    printf("\n---------------------------\n");

    printf("\n1 - Criar estrutura auxiliar");
    printf("\n2 - Inserir o valor na estrutura"); 
    printf("\n3 - Excluir numero final da estrutura");
    printf("\n4 - Excluir numero especifico da estrutura");
    printf("\n5 - mostra dados da estrutura auxiliar");
    printf("\n\nescolha uma opcao:");
    scanf("%d",& op);
    getchar();

    if(op<1 || op>4){
      printf("opcao invalida \n\naperte qualquer tecla para continua...");
      getchar();
    }
    system(CLEAR);
  }while(op<1 || op>3);

  switch (op){
    case 1: menuCriarEstruturaAuxiliar(); break;
    case 2: menuInserirValorNaEstrutura(); break;
    case 3: menuExcluirNumeroDoFinaldaEstrutura(); break;
    case 4: break;
  }
}

void menuCriarEstruturaAuxiliar(){
  int posicao, tamanho, validacao;

  printf("Digite uma posicao:");
  scanf("%d", & posicao);
  getchar();

  printf("Digite um tamanho:");
  scanf("%d", & tamanho);
  getchar();

  validacao = criarEstruturaAuxiliar(posicao, tamanho);

  if(validacao == SUCESSO)
    printf("Estrutura auxiliar criada com sucesso!!\n\naperte qualquer tecla para continua...");
  else
    menuVerificacao(validacao);
  

  getchar();
  system(CLEAR);
  menu();
}

void menuInserirValorNaEstrutura(){

    int posicao, valor, validacao,op, tamanho;

    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    printf("Digite um valor:");
    scanf("%d", & valor);
    getchar();

    validacao = inserirNumeroEmEstrutura(posicao, valor);

    if(validacao == SUCESSO){
        printf("Numero inserido com sucesso!!\n\naperte qualquer tecla para continua...");
    }else if(validacao == SEM_ESTRUTURA_AUXILIAR){
        printf("Sem estrutura auxiliar!");
        do{
            system(CLEAR);
            printf("deseja criar um estrutura auxiliar\n1 - Sim\n2 - Nao\nEscolha uma opcao:");
            scanf("%d", & op);
        }while(op<1 || op>2);

        if(op == 1){

            printf("Digite um tamanho:");
            scanf("%d", & tamanho);
            getchar();

            validacao = criarEstruturaAuxiliar(posicao, tamanho);

            if(validacao == SUCESSO){
              printf("Estrutura auxiliar criada com sucesso!!\n\naperte qualquer tecla para continua...");
              getchar();
              validacao = inserirNumeroEmEstrutura(posicao, valor);
              
              if(validacao == SUCESSO){
                printf("Numero inserido com sucesso!!\n\naperte qualquer tecla para continua...");
              }else{
                menuVerificacao(validacao);
              }
              
            }else{
              menuVerificacao(validacao);
            }
          
        }else{
          printf("voce sera encaminhado para o menu principal!\n\naperte qualquer tecla para continua...");
        }
    }else{
        menuVerificacao(validacao);
    }

    getchar();
    system(CLEAR);
    menu();
}

void menuExcluirNumeroDoFinaldaEstrutura(){
 
  int posicao,validacao;
  
  printf("Digite uma posicao:");
  scanf("%d", & posicao);
  getchar();

  validacao = excluirNumeroDoFinaldaEstrutura(posicao);

  if(validacao == SUCESSO)
    printf("Numero excluido com sucesso\n\naperte qualquer tecla para continua...");
  else
    menuVerificacao(validacao);
  

  getchar();
  system(CLEAR);
  menu();
}

/*
void menuExcluirNumeroEspecificoDeEstrutura(){
    int posicao, valor, validacao;

    printf("Digite uma posicao:");
    scanf("%d", & posicao);
    getchar();

    printf("Digite um valor:");
    scanf("%d", & valor);
    getchar();

    validacao = excluirNumeroEspecificoDeEstrutura(posicao,valor);

}

void menuDadosEstruturaAuxiliar(){
  int posicao, tamanho = 0, validacao = 0;
  
  printf("Digite uma posicao:");
  scanf("%d", & posicao);
  getchar();

  if(posicao<0 || posicao>TAM){
    printf("posicao invalida\n\naperte qualquer tecla para continua...");
  }else if(!existiEstrutura(posicao-1)){
    printf("Nao existi estrutura\n\naperte qualquer tecla para continua...");
  }else{
    tamanho = getQuantidadeElementosEstruturaAuxiliar(posicao);
    
    int vetor[tamanho];
    validacao = getDadosEstruturaAuxiliar(posicao,vetor);

    if(validacao == SUCESSO){
      printf("Dados na posicao %d", posicao);
      for(int i = 0; i<tamanho;i++){
        printf("%d ",vetor[tamanho]);
      }
    }
  }
}
*/
void menuVerificacao(int validacao){
  
  if(validacao == JA_TEM_ESTRUTURA_AUXILIAR){
      printf("ja existi estrutura Auxiliar!!\n\naperte qualquer tecla para continua...");
  }else if(validacao ==POSICAO_INVALIDA){
      printf("posicao invalida!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == SEM_ESPACO_DE_MEMORIA){
      printf("Sem espaço de menoria!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == TAMANHO_INVALIDO){
      printf("Tamanho invalido!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == SEM_ESPACO){
      printf("sem espaco!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS){
      printf("Todas as estruturas auxiliares estao vazias!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == NOVO_TAMANHO_INVALIDO){
      printf("Todas as estruturas auxiliares estao vazias!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == NUMERO_INEXISTENTE){
      printf("Numero Inexistente!!\n\naperte qualquer tecla para continua...");
  }else if(validacao == SEM_ESTRUTURA_AUXILIAR){
      printf("Sem estrutura auxiliar!!\n\naperte qualquer tecla para continua...");
  }
  
}