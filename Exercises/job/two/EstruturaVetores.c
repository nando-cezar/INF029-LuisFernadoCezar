
#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

Lista *vetorPrincipal[TAM];

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
int criarEstruturaAuxiliar(int posicao, int tamanho){

    posicao--;
    int retorno = 0;
    
    if(posicaoInvalida(posicao)){     
        retorno = POSICAO_INVALIDA;
    }else if(tamanho < 1){
        retorno = TAMANHO_INVALIDO;
    }else if(estruturaExistente(posicao)){         
        retorno = JA_TEM_ESTRUTURA_AUXILIAR; 
    }else{

        for(int i = 0; i < tamanho; i++){
            vetorPrincipal[posicao] = criaLista(posicao);
        }

        if(vetorPrincipal[posicao] == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
        }else{
            retorno = SUCESSO;
        }
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
int inserirNumeroEmEstrutura(int posicao, int valor){
    
    int retorno = 0;
    posicao--;

    if(posicaoInvalida(posicao)){
        retorno = POSICAO_INVALIDA;
    }else{

        if (estruturaExistente(posicao)){
           
            if (espacoExistente(posicao)){

                inserirElementoLista(vetorPrincipal[posicao], valor);
                retorno = SUCESSO;
            }else{
                retorno = SEM_ESPACO;
            }
        }else{
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
int excluirNumeroDoFinaldaEstrutura(int posicao){
    posicao--;
    int retorno = 0;

    if(posicaoInvalida(posicao)){
        retorno = POSICAO_INVALIDA;
    }else if(estruturaExistente(posicao)){
        
        if (!estruturaAuxiliarPreenchida(posicao)){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }else{
            Lista* l = vetorPrincipal[posicao];
            Lista* x;
            while (l != NULL){  
                x = l ->prox;              
                if(l->prox == NULL || x->verificada == 0){
                    vetorPrincipal[posicao] = retiraLista(posicao, l->conteudo);
                    l = NULL;
                }else{
                    l = l -> prox;       
                }
                
            }

            realocarLista(posicao);
            retorno = SUCESSO;
        }

    }else{
        retorno = SEM_ESTRUTURA_AUXILIAR;
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
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor){
    
    posicao--;
    int retorno = 0;

    if(posicaoInvalida(posicao)){
        retorno = POSICAO_INVALIDA;
    }else if(!estruturaExistente(posicao)){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        if (!estruturaAuxiliarPreenchida(posicao)){
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }else{
            if(contemNumero(posicao, valor)){
                vetorPrincipal[posicao] = retiraLista(posicao, valor);
                realocarLista(posicao);
                retorno = SUCESSO;
            }else{
                retorno = NUMERO_INEXISTENTE;
            }
            
        }
    }

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
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    posicao--;
    int retorno = 0, incremento = 0;

    if(posicaoInvalida(posicao)){
        retorno = POSICAO_INVALIDA;
    }else if(!estruturaExistente(posicao)){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{
        Lista* aux = vetorPrincipal[posicao];

        while(aux !=NULL){
            if(aux->verificada == 1){
                vetorAux[incremento] = aux->conteudo;
                incremento++;
            }
            aux = aux->prox;
        }
        retorno = SUCESSO;
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
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){
    
    int retorno = 0;
    int tamanho = 0;
    retorno= getDadosEstruturaAuxiliar(posicao, vetorAux);

    if(retorno == SUCESSO){

        tamanho = getQuantidadeElementosEstruturaAuxiliar(posicao);
        ordenar(vetorAux, tamanho);   
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
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){
    
    int retorno = 0, incremento = 0;

    for(int i = 0 ; i< TAM; i++){
        Lista* aux = vetorPrincipal[i];

        if(estruturaExistente(i)){
            while(aux !=NULL){
                if(aux->verificada){
                    vetorAux[incremento] = aux->conteudo;
                    incremento++;
                }
                aux = aux->prox;
            }
        }
    }

    if(incremento){
        retorno = SUCESSO;
    }else{
        retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
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
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int tamanho = 0;
    int retorno =  getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if(retorno == SUCESSO){
       
        for(int i = 0 ; i<TAM;i++){
           if(vetorPrincipal[i] != NULL && vetorPrincipal[i]->verificada){
               tamanho+=getQuantidadeElementosEstruturaAuxiliar(i+1);
           }
        }
        ordenar(vetorAux, tamanho); 
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
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho){
    int retorno = 0, validade = 0;
    posicao--;
    novoTamanho = getTamanhoDaEstruturaAuxilia(posicao) + novoTamanho;
   
    if(posicaoInvalida(posicao)){
        retorno = POSICAO_INVALIDA;
    }else if(novoTamanho<1){
        retorno = NOVO_TAMANHO_INVALIDO;
    }else if(!estruturaExistente(posicao)){
        retorno = SEM_ESTRUTURA_AUXILIAR;
    }else{

        Lista * aux = vetorPrincipal[posicao];
        vetorPrincipal[posicao] = NULL;

        for(int i = 0; i<novoTamanho ;i++){
            vetorPrincipal[posicao] = criaLista(posicao);
        }

        if(vetorPrincipal[posicao] == NULL){
            retorno = SEM_ESPACO_DE_MEMORIA;
            vetorPrincipal[posicao] = aux;
        }else{

            while(aux!= NULL){
                if(aux ->verificada){
                    validade = inserirNumeroEmEstrutura(posicao +1,aux ->conteudo);

                    if(validade!=SUCESSO){
                        retorno = validade;
                        aux = NULL;
                    }else{
                       aux = aux ->prox;  
                    }
                }else{
                  aux = aux ->prox;  
                }
              
            }
            retorno = SUCESSO;
        }

    }
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
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    int retorno = 0, quantidade = 0;
    posicao --;

    if(posicaoInvalida(posicao)){
        retorno = POSICAO_INVALIDA;
    }else if(!estruturaExistente(posicao)){
        retorno =SEM_ESTRUTURA_AUXILIAR;
    }else{
        Lista* l = vetorPrincipal[posicao];

        while(l!=NULL){

            if(l->verificada){
                quantidade++;
            }
            l = l->prox;
        }

        retorno = quantidade;
    }

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote(){
    No* lista = NULL;
    int tamanho = 0, validade;
 
    for(int i = 0 ; i<TAM;i++){
        if(vetorPrincipal[i] != NULL && vetorPrincipal[i]->verificada){
            tamanho+=getQuantidadeElementosEstruturaAuxiliar(i+1);
        }
    }
   
    int vetor[tamanho];
    
    validade = getDadosDeTodasEstruturasAuxiliares(vetor);

    for(int i = tamanho-1 ; i>=0 ; i--){
        lista = insereNo(lista,vetor[i]);
    }

    return lista;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]){
    No* l = inicio;
    int i = 0;

    while(l!=NULL){
        vetorAux[i] = l->conteudo;
        i++;
        l = l->prox; 
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.
Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio){
    
    No* p = *inicio;
    while(p !=NULL){
        No * t = p->prox;
        free(p);
        p = t;
    }

    *inicio = NULL;
}



No* insereNo(No* no , int i){

    No* novo = (No*) malloc (sizeof(No));
    novo->conteudo = i;
    novo ->prox = no;
    return novo; 
}


void inicializar(){
    for(int i = 0 ; i< TAM ; i++){
        vetorPrincipal[i] = NULL;
    }
}

void finalizar(){
    for(int i = 0 ; i<TAM ;i++){
        liberaLista(&vetorPrincipal[i]);
    }
}

void liberaLista(Lista** l){
    Lista* p = *l;
    while (p!= NULL){
        Lista* t = p ->prox;
        free(p);
        p =t;
    }
    
}

int estruturaExistente(int posicao){return vetorPrincipal[posicao]!= NULL;}

int estruturaAuxiliarPreenchida(int posicao){return vetorPrincipal[posicao]->verificada == 1;};

int espacoExistente(int posicao){
    int retorno = 0;
  
    Lista* l = vetorPrincipal[posicao];
  
    while(l != NULL){
        if(l->verificada == 0){
            retorno =1;
            break;
        }
        l = l->prox;
    }
    return retorno;
}

Lista* criaLista(int posicao){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo ->verificada = 0;
    novo ->prox = vetorPrincipal[posicao];
    return novo;
}

void inserirElementoLista(Lista *l, int numero){
    
    while(l != NULL){
        if(l->verificada == 0){
            l ->conteudo = numero;
            l -> verificada =1;
            break;
        }

        l = l->prox;
    }
}

/*void retiraListaFinalElemento(Lista* l){
    while (l != NULL){
        printf("a");
        if((l->verificada == 1 && l->prox->verificada == 0) || (l->prox ==NULL)){
            l = retiraLista(l, l->conteudo);
            break;
        }
        l = l->prox;
    }
}*/

int contemNumero(int posicao, int v){
    Lista* ant = NULL; 
    Lista* p = vetorPrincipal[posicao];


    while(p != NULL && p ->conteudo != v){
        ant = p;
        p = p ->prox;
    }

    if(p == NULL) return 0;
    else return 1;
}

Lista* retiraLista(int posicao, int v){

    Lista* ant = NULL; 
    Lista* p = vetorPrincipal[posicao];

    while(p != NULL && p->conteudo != v){
        ant = p;
        p = p ->prox;
    }

    if(p == NULL) return 0;

    if(ant == NULL){
        vetorPrincipal[posicao] = p->prox;
    }else{
        ant ->prox = p->prox;
    }

    free(p);
    return vetorPrincipal[posicao];
}

void realocarLista(int posicao){
    
    Lista* ant = NULL;
    Lista* p = vetorPrincipal[posicao];
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    

    while(p != NULL){
        ant = p;
        p = p->prox;
    }

    novo ->verificada = 0;
    novo ->prox = NULL;

    ant->prox = novo;
}

void ordenar(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = i + 1; j < tamanho; ++j) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

int getTamanhoDaEstruturaAuxilia(int posicao){
    int quantidade = 0;
    Lista * l = vetorPrincipal[posicao];

    while(l!=NULL){
        quantidade ++;
        l= l->prox;
    }

    return quantidade;
}

int posicaoInvalida(int posicao){
    return (posicao < 0 || posicao >= TAM);
}

