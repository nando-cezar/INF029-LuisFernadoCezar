#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

#define TAM 10

No* vetorPrincipal[TAM];


int existeEstruturaAuxiliar(No* vetorPrincipal);
int ehPosicaoValida(int posicao);
int temEspaco(No* vetorPrincipal);

No* inserirFinalLista(No* vetorPrincipal, int valor);
int inserirSortAscLista(No* vetorPrincipal, int v);
No* inserirLista(No* vetorPrincipal, int valor);
No* pesquisaLista(No* vetorPrincipal, int valor);
No* atualizarLista(No* vetorPrincipal, int valor);
No* deletarLista(No* vetorPrincipal, int valor);
int vaziaEstruturaAuxiliar(No* vetorPrincipal);
void recuperarLista(int posicao);
No* realocarValorLista(No* vetorPrincipal, int valor);
No* ordenarAscLista(No* vetorPrincipal);

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int * estruturaAuxiliar;

    int retorno = 0;
    // se posição é um valor válido {entre 1 e 10}
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
    }
    // o tamanho ser muito grande
    else if(tamanho > 10){
        retorno = SEM_ESPACO_DE_MEMORIA;
    }
    // o tamanho nao pode ser menor que 1
    else if(tamanho < 1){
        retorno = TAMANHO_INVALIDO;
    }
    // a posicao pode já existir estrutura auxiliar
    else if(existeEstruturaAuxiliar(vetorPrincipal[posicao])){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    } 
    // deu tudo certo, crie
    else{
        for(int i = 0; i < tamanho; i++) 
            vetorPrincipal[posicao] = inserirLista(vetorPrincipal[posicao], 0);
        retorno = SUCESSO;
    }

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    //int existeEstruturaAuxiliar = 0;
    //int temEspaco = 0;
    int posicao_invalida = 0;

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        retorno = POSICAO_INVALIDA;
        printf("POSICAO_INVALIDA\n");
      }else
    {
        // testar se existe a estrutura auxiliar
        if(existeEstruturaAuxiliar(vetorPrincipal[posicao]))
        {
            if (temEspaco(vetorPrincipal[posicao]))
            {
                //insere
                vetorPrincipal[posicao] = atualizarLista(vetorPrincipal[posicao], valor);
                recuperarLista(posicao);
                retorno = SUCESSO;
                printf("SUCESSO\n");
            }
            else
            {
                retorno = SEM_ESPACO;
                printf("SEM_ESPACO\n");
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
            printf("SEM_ESTRUTURA_AUXILIAR\n");
        }
    }

    //recuperarLista(vetorPrincipal[posicao]);
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
    int retorno = SUCESSO;
    No* p = NULL;
    int valor = 0;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        //printf("POSICAO_INVALIDA\n");
        retorno = POSICAO_INVALIDA;
    }else if(!existeEstruturaAuxiliar(vetorPrincipal[posicao])){
        //printf("SEM_ESTRUTURA_AUXILIAR\n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else if(vaziaEstruturaAuxiliar(vetorPrincipal[posicao])){
        //printf("ESTRUTURA_AUXILIAR_VAZIA\n"); 
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }else{
        //printf("SUCESSO\n");
        int count = 0;
        for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
            
            if(p->conteudo == 0){
                break;
            }
            count++;
            valor = p->conteudo;
            //printf(">> %d \n", p->conteudo);
        }
        
        realocarValorLista(vetorPrincipal[posicao], valor);
    }
    
    
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = SUCESSO;

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        //printf("POSICAO_INVALIDA\n");
        retorno = POSICAO_INVALIDA;
    }else if(!existeEstruturaAuxiliar(vetorPrincipal[posicao])){
        //printf("SEM_ESTRUTURA_AUXILIAR\n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else if(vaziaEstruturaAuxiliar(vetorPrincipal[posicao])){
        //printf("ESTRUTURA_AUXILIAR_VAZIA\n");
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }else if(pesquisaLista(vetorPrincipal[posicao], valor) == NULL){
        //printf("NUMERO_INEXISTENTE\n");
        retorno = NUMERO_INEXISTENTE;
    }else{
        //printf("SUCESSO\n");
        realocarValorLista(vetorPrincipal[posicao], valor);
        //recuperarLista(posicao);
        //getchar();
    }
    
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = SUCESSO;
    if (posicao < 1 || posicao > 10) retorno = POSICAO_INVALIDA;
    return retorno;
}

// verifica se na posição existe estrutura
int existeEstruturaAuxiliar(No* vetorPrincipal){
    return (vetorPrincipal != NULL);
}

// verifica se a estrutra tem espaço disponivel
int temEspaco(No* vetorPrincipal){
    No* p = NULL;
    int count1 = 0;
    int retorno = 0;

    for(p = vetorPrincipal; p != NULL; p = p->prox){
        if(p->conteudo == 0) count1++;
    } 

    if(count1 > 0) retorno = 1;

    //printf("Espaco: %d %d\n", count1, count2);
    return retorno;
}

// verifica se a estrutra tem espaço disponivel
int vaziaEstruturaAuxiliar(No* vetorPrincipal){
    
    No* p = NULL;
    int count1 = 0;
    int count2 = 0;
    int retorno = 0;

    for(p = vetorPrincipal; p != NULL; p = p->prox){
        count1++;
        if(p->conteudo == 0) count2++;
    } 
    
    if(count1 == count2) retorno = 1;

    //printf("Espaco: %d %d\n", count1-count2, count2);
    return retorno;
}

// pesquisa 
No* pesquisaLista(No* vetorPrincipal, int valor){
    No* p;
    for(p = vetorPrincipal; p != NULL; p = p->prox){
        if(p->conteudo == valor) return p;
    }
    
    return NULL;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = SUCESSO;

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        //printf("POSICAO_INVALIDA\n");
        retorno = POSICAO_INVALIDA;
    }else if(!existeEstruturaAuxiliar(vetorPrincipal[posicao])){
        //printf("SEM_ESTRUTURA_AUXILIAR\n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        int count1 = 0;
        int count2 = 0;
        int aux = 0;

        for(No* p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
            vetorAux[count1] = p->conteudo;
            if(vetorAux[count1] != 0) count2++;
            count1++;
        }
        
        for(int i = 0; i < count2; i++){
            if(vetorAux[i+1] != 0){
                aux = vetorAux[i];
                vetorAux[i] = vetorAux[i+1];
                vetorAux[i+1] = aux;
            }
        }
    }
    //recuperarLista(2);
    //printf("TESTE---");
    //getchar();
  
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = SUCESSO;
    int count = 0;
    No* p;
    No* q = NULL;
    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        //printf("POSICAO_INVALIDA\n");
        retorno = POSICAO_INVALIDA;
    }else if(!existeEstruturaAuxiliar(vetorPrincipal[posicao])){
        //printf("SEM_ESTRUTURA_AUXILIAR\n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        
        for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
            vetorAux[count] = inserirSortAscLista(p, p->conteudo);
            count++;
        }
    }

    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
No* inserirLista(No* vetorPrincipal, int valor){ 

    No* novo = (No*) malloc(sizeof(No));
    novo->conteudo = valor;
    novo->prox = vetorPrincipal;
    return novo;
}

No* inserirFinalLista(No* vetorPrincipal, int valor){

    No* p;
    No* novo = malloc(sizeof(No));

    if(novo){
        novo->conteudo = valor;
        novo->prox = NULL;

        if(vetorPrincipal == NULL)
            vetorPrincipal = novo;
        else{
            p = vetorPrincipal;
            while(p->prox) 
                p = p->prox;
            p->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");

    return vetorPrincipal;
}

No* atualizarLista(No* vetorPrincipal, int valor){ 

    No* novo = (No*) malloc(sizeof(No));

    novo = vetorPrincipal;
    novo = deletarLista(novo, 0);
    novo = inserirLista(novo, valor);

    return novo;
}

No* deletarLista(No* vetorPrincipal, int valor){

    No* ant = NULL;
    No* p = vetorPrincipal;

    while(p != NULL && p->conteudo != valor){
        ant = p;
        p = p->prox;
    }

    if(p == NULL) return vetorPrincipal;

    if(ant == NULL) vetorPrincipal = p->prox;
    else ant->prox = p->prox;

    free(p);
    return vetorPrincipal;
}

No* realocarValorLista(No* vetorPrincipal, int valor){

    No* novo = (No*) malloc(sizeof(No));

    novo = vetorPrincipal;
    novo = deletarLista(novo, valor);
    novo = inserirFinalLista(novo, 0);
       
    return novo;
}

int inserirSortAscLista(No* vetorPrincipal, int v){

    No* novo;
    No* ant = NULL;
    No* p = vetorPrincipal;


    while(p != NULL && p->conteudo < v){
        ant = p;
        p = p->prox;
    }

    novo = (No*) malloc(sizeof(No));
    novo->conteudo = v;

    if(ant == NULL){

        novo->prox = vetorPrincipal;
        vetorPrincipal = novo;

    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return vetorPrincipal->conteudo;
}


int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;

    for(int i = 0; i < novoTamanho; i++) 
            vetorPrincipal[posicao] = inserirFinalLista(vetorPrincipal[posicao], 0);

    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    //return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/
void recuperarLista(int posicao){

    No* p;

    for(int i = 0; i < TAM; i++){
        if(existeEstruturaAuxiliar(vetorPrincipal[posicao])){
            printf("( %02d )", i);
            for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox) printf("| %02d |", p->conteudo); 
            printf("\n"); 
        } 
    }
}

void inicializar()
{
    for(int i = 0; i < TAM; i++) vetorPrincipal[i] = NULL;    
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    
}
