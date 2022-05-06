#include <stdio.h>
#include <stdlib.h>

#include "EstruturaVetores.h"

#define TAM 10

No* vetorPrincipal[TAM];


int existeEstruturaAuxiliar(int posicao);
int ehPosicaoValida(int posicao);
int temEspaco(int posicao);

No* inserirFinalLista(int posicao, int valor);
No* inserirSortAscLista(No* l, int v);
No* inserirLista(int posicao, int valor);
int pesquisaLista(int posicao, int valor);
No* atualizarLista(int posicao, int valor);
No* deletarLista(int posicao, int valor);
int vaziaEstruturaAuxiliar(int posicao);
void recuperarLista(int posicao);
No* realocarValorLista(int posicao, int valor);
No* ordenarAscLista(int posicao);
No* inverterLista(int posicao);
void ordenarLista(int posicao);
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
    else if(existeEstruturaAuxiliar(posicao)){
        retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    } 
    // deu tudo certo, crie
    else{
        for(int i = 0; i < tamanho; i++) 
            vetorPrincipal[posicao] = inserirLista(posicao, 0);
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

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if(existeEstruturaAuxiliar(posicao))
        {
            if (temEspaco(posicao))
            {
                //insere
                vetorPrincipal[posicao] = atualizarLista(posicao, valor);
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

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
    No* p = NULL;
    int retorno = SUCESSO;

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        //printf("POSICAO_INVALIDA\n");
        retorno = POSICAO_INVALIDA;
    }else if(!existeEstruturaAuxiliar(posicao)){
        //printf("SEM_ESTRUTURA_AUXILIAR\n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else if(vaziaEstruturaAuxiliar(posicao)){
        //printf("ESTRUTURA_AUXILIAR_VAZIA\n"); 
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }else{
        //printf("SUCESSO\n");
        int count = 0;
        for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
            if(p->conteudo == 0) break;
            else count = p->conteudo;
        }
        realocarValorLista(posicao, count);
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
    }else if(!existeEstruturaAuxiliar(posicao)){
        //printf("SEM_ESTRUTURA_AUXILIAR\n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else if(vaziaEstruturaAuxiliar(posicao)){
        //printf("ESTRUTURA_AUXILIAR_VAZIA\n");
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
    }else if(!pesquisaLista(posicao, valor)){
        //printf("NUMERO_INEXISTENTE\n");
        retorno = NUMERO_INEXISTENTE;
    }else{
        //printf("SUCESSO\n");
        realocarValorLista(posicao, valor);
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
int existeEstruturaAuxiliar(int posicao){
    return (vetorPrincipal[posicao] != NULL);
}

// verifica se a estrutra tem espaço disponivel
int temEspaco(int posicao){
    No* p = NULL;
    int count1 = 0;
    int count2 = 0;
    int retorno = 0;

    for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
        count1++;
        if(p->conteudo != 0) count2++;
    } 

    if(count1 != count2) retorno = 1;

    //printf("Espaco: %d %d\n", count1, count2);
    return retorno;
}

// verifica se a estrutra tem espaço disponivel
int vaziaEstruturaAuxiliar(int posicao){
    No* p = NULL;
    int count1 = 0;
    int count2 = 0;
    int retorno = 0;

    for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
        //printf(">>> %d\n", p->conteudo);
        count2++;
        if(p->conteudo == 0) count1++;
    } 
    
    if(count1 == count2) retorno = 1;

    //printf("Espaco: %d %d\n", count1, count2);
    return retorno;
}

// pesquisa 
int pesquisaLista(int posicao, int valor){

    No* p = NULL;
    int retorno = 0;

    for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
        if(p->conteudo == valor) retorno = 1;
    }
    //printf("Retorno: %d\n", retorno);
    return retorno;
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
    No* p = NULL;
    int retorno = SUCESSO;

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        //printf("POSICAO_INVALIDA\n");
        retorno = POSICAO_INVALIDA;
    }else if(!existeEstruturaAuxiliar(posicao)){
        //printf("SEM_ESTRUTURA_AUXILIAR\n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        int count1 = 0;
        int count2 = 0;
        int aux = 0;

        for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
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
    No* p = NULL;
    No* s[TAM];

    for(int i = 0; i < 2; i++) s[i] = NULL;

    if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
        //printf("POSICAO_INVALIDA\n");
        retorno = POSICAO_INVALIDA;
    }else if(!existeEstruturaAuxiliar(posicao)){
        //printf("SEM_ESTRUTURA_AUXILIAR\n");
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        
        int count1 = 0;
        int count2 = 0;
        int aux = 0;

        for(p = vetorPrincipal[posicao]; p != NULL; p = p->prox){
            vetorAux[count1] = p->conteudo;
            if(vetorAux[count1] != 0) count2++;
            count1++;
        }
        
        for(int i = 0; i < count2; i++){
            if(vetorAux[i+1] != 0){
                if(vetorAux[i+1] < vetorAux[i]){
                    aux = vetorAux[i+1];
                    vetorAux[i+1] = vetorAux[i];
                    vetorAux[i] = aux;
                }
            }
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

    int retorno = SUCESSO;
    int count1 = 0;
    int count2 = 0;
    No* p = NULL;

    for(int i = 0; i < TAM; i++)
        if(vaziaEstruturaAuxiliar(i))
            count1++;
        
    if(count1 == TAM)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{
        for(int i = 0; i < TAM; i++){
            if(existeEstruturaAuxiliar(i) && !vaziaEstruturaAuxiliar(i)){
                
                for(p = inverterLista(i); p != NULL; p = p->prox){
                    //if(p->conteudo != 0){
                        printf(">> %d\n", p->conteudo);
                        vetorAux[count2] = p->conteudo;
                        count2++;
                    //} 
                }
            }
        }
    }

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
    int retorno = SUCESSO;
    int count = 0;

    for(int i = 0; i < TAM; i++)
        if(vaziaEstruturaAuxiliar(i))
            count++;
        
    if(count == TAM)
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    else{

        for(int i = 0; i < TAM; i++){
            if(existeEstruturaAuxiliar(i) && !vaziaEstruturaAuxiliar(i)){
                
                /*for(p = vetorPrincipal[i]; p != NULL; p = p->prox){
                    //if(p->conteudo != 0){
                        //printf(">> %d\n", p->conteudo);
                        vetorAux[count2] = p->conteudo;
                        count2++;
                    //} 
                }
                for(int i = 0; i < TAM; i++){
                    if(!listEmpty(l[i]))
                        for(p = l[i]; p != NULL; p = p->next)
                            if(p->info != 0)
                                s[i] = listInsertSortedAsc(s[i], p->info);
                }*/
            }
        }
    }

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
No* inserirLista(int posicao, int valor){ 

    No* novo = (No*) malloc(sizeof(No));
    novo->conteudo = valor;
    novo->prox = vetorPrincipal[posicao];
    return novo;
}

No* inserirFinalLista(int posicao, int valor){

    No* p = NULL;
    No* novo = malloc(sizeof(No));

    if(novo){
        novo->conteudo = valor;
        novo->prox = NULL;

        if(vetorPrincipal[posicao] == NULL)
            vetorPrincipal[posicao] = novo;
        else{
            p = vetorPrincipal[posicao];
            while(p->prox) 
                p = p->prox;
            p->prox = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");

    return vetorPrincipal[posicao];
}

No* atualizarLista(int posicao, int valor){ 

    No* novo = (No*) malloc(sizeof(No));

    novo = vetorPrincipal[posicao];
    novo = deletarLista(posicao, 0);
    novo = inserirLista(posicao, valor);

    return novo;
}

No* deletarLista(int posicao, int valor){

    No* ant = NULL;
    No* p = vetorPrincipal[posicao];

    while(p != NULL && p->conteudo != valor){
        ant = p;
        p = p->prox;
    }

    if(p == NULL) return vetorPrincipal[posicao];

    if(ant == NULL) vetorPrincipal[posicao] = p->prox;
    else ant->prox = p->prox;

    free(p);
    return vetorPrincipal[posicao];
}

//inverter lista encadeada
No* inverterLista(int posicao)
{
    No* p = vetorPrincipal[posicao];
    No* prox = vetorPrincipal[posicao]->prox;
    No* temp = vetorPrincipal[posicao]->prox;
    No* n = (No*) malloc(sizeof(No));

    n = vetorPrincipal[posicao];

    while(prox != NULL && prox->conteudo != 0){
        temp = temp->prox;
        prox->prox = p;
        p = prox;
        prox = temp;
    }

    n->prox = NULL;
    n = p;
    return n;
}

No* realocarValorLista(int posicao, int valor){

    No* p = NULL;
    No* novo = (No*) malloc(sizeof(No));

    novo = vetorPrincipal[posicao];
    novo = deletarLista(posicao, valor);
    novo = inserirFinalLista(posicao, 0);
       
    return novo;
}

No* inserirSortAscLista(No* l, int v){

    No* novo;
    No* ant = NULL;
    No* p = l;

    while(p != NULL && p->conteudo < v){
        ant = p;
        p = p->prox;
    }

    novo = (No*) malloc(sizeof(No));
    novo->conteudo = v;

    if(ant == NULL){

        novo->prox = l;
        l = novo;

    }else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}


int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{
    int retorno = 0;

    for(int i = 0; i < novoTamanho; i++) 
            vetorPrincipal[posicao] = inserirFinalLista(posicao, 0);

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

    No* p = NULL;

    for(int i = 0; i < TAM; i++){
        if(existeEstruturaAuxiliar(posicao)){
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
