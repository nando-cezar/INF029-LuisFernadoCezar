#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H

// enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que voce de significado
// as suas constantes, para mais informacoes https://en.cppreference.com/w/c/language/enum
// as constantes do enum em sua inicialização vao representar o numero resultante da soma do valor da
// constante anterior mais 1, caso nao haja valor algum na primeira constante ela vai ser inicializada com 0
enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };


typedef struct lista {
    int conteudo;
    int verificada;
    struct lista *prox;
} Lista;


typedef struct reg {
    int conteudo;
    struct reg *prox;
} No;


void inicializar();
int criarEstruturaAuxiliar(int posicao, int tamanho);
int inserirNumeroEmEstrutura(int posicao, int valor);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
int getTamanhoDaEstruturaAuxilia(int posicao);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
void finalizar();

No* montarListaEncadeadaComCabecote();
No* insereNo(No* l , int i);
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]);
void destruirListaEncadeadaComCabecote(No **inicio);
void liberaLista(Lista **l);

Lista* criaLista(int posicao);
Lista* retiraLista(Lista* l,int v); 
int contemNumero(Lista* l, int v);
int estruturaExistente(int posicao);
int espacoExistente(int posicao);
int conteudoExistente(int posicao);
int posicaoValida(int posicao);
void insercaoElementosLista(Lista *l, int numero);
void retiraListaFinalElemento(Lista* l);
void realocamento(Lista* l);
void ordenar(int vetor[], size_t tamanho);




#endif  // TRABALHO2_ESTRUTURAVETORES_H