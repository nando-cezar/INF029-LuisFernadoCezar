// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: LUIS FERNANDO CEZAR DOS SANTOS
//  email: nandocezar22@gmail.com
//  Matrícula: 20212160053
//  Semestre: 2 SEMESTRE

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "LuisFernandoCezar_20212160053_T1.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <math.h>
#include <locale.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x){ //função utilizada para testes
    int fat = 6;
    return fat;
}

int teste(int a){
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

int validaSomenteNumero(char c){

    if(isalpha(c) || ispunct(c)) return 0;
    return 1;
}

int anoBissexto(int ano){

    if(ano%400 == 0 || (ano%4 == 0 && ano%100 != 0)) return 1;
    else return 0;
}

int validaData(int dia, int mes, int ano){

    if(
        mes == 1 || 
        mes == 3 ||
        mes == 5 || 
        mes == 7 ||
        mes == 8 || 
        mes == 10||
        mes == 12
    ){
        if(dia > 31) return 0;
        else return 1;
         
    }else if(mes == 2 && anoBissexto(ano)){
        if(dia > 29) return 0;
        else return 1;          
    }else if(mes == 2){
        if(dia > 28) return 0;
        else return 1;
    }else{
        if(dia > 30) return 0;
        else return 1;
    }

}

DataQuebrada quebraData(char data[]){

    DataQuebrada dq;
    char sDia[3];
	char sMes[3];
	char sAno[5];
	int i;

    for (int i = 0; i < strlen(data); i++){
        if (data[i] != '/' && !validaSomenteNumero(data[i])){
            dq.valido = 0;
            return dq;
        }
    }

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else{
		dq.valido = 0;
        return dq;
    }

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else{
		dq.valido = 0;
        return dq;
    }
	
	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else{
		dq.valido = 0;
        return dq;
    }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno); 

    if(dq.iMes <= 0 || dq.iMes > 12 ){
        dq.valido = 0;
        return dq;
    } 
    else if(dq.iDia <= 0 || dq.iDia > 31){
        dq.valido = 0;
        return dq;
    }
    else if(validaData(dq.iDia, dq.iMes, dq.iAno) == 0){
        dq.valido = 0;
        return dq;
    }

	dq.valido = 1;
    return dq;
}

int dataInicialMaiorDataFinal(char datainicial[], char datafinal[]){

    DiasMesesAnos dmaInicial;
    DiasMesesAnos dmaFinal;
    DataQuebrada dataQuebrada;

    dataQuebrada = quebraData(datainicial);
    if(dataQuebrada.valido == 1){
        dmaInicial.qtdDias = dataQuebrada.iDia;
        dmaInicial.qtdMeses = dataQuebrada.iMes;
        dmaInicial.qtdAnos = dataQuebrada.iAno;
    }else{
        return 0;
    }
    
    dataQuebrada = quebraData(datafinal);
    if(dataQuebrada.valido == 1){
        dmaFinal.qtdDias = dataQuebrada.iDia;
        dmaFinal.qtdMeses = dataQuebrada.iMes;
        dmaFinal.qtdAnos = dataQuebrada.iAno;
    }else{
        return 0;
    }
    
    if(dmaInicial.qtdAnos > dmaFinal.qtdAnos) return 0;
    else if(dmaInicial.qtdAnos == dmaFinal.qtdAnos && dmaInicial.qtdMeses > dmaFinal.qtdMeses) return 0;
    else if(dmaInicial.qtdAnos == dmaFinal.qtdAnos && dmaInicial.qtdMeses == dmaFinal.qtdMeses && dmaInicial.qtdDias > dmaFinal.qtdDias) return 0;
    else return 1;

}

int QuantidadeDeDiasMesAnterior(int mes, int ano){

    if(
        mes == 1 || 
        mes == 3 ||
        mes == 5 || 
        mes == 7 ||
        mes == 8 || 
        mes == 10||
        mes == 12
    ){
        return 31;
         
    }else if(mes == 2 && anoBissexto(ano)){
        return 29;          
    }else if(mes == 2){
        return 28;
    }else{
        return 30;
    }
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]){

    DataQuebrada dataQuebrada = quebraData(data);

    if (dataQuebrada.valido) return 1;
    else return 0;

}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]){

    DiasMesesAnos dma;
    DataQuebrada dtInicial = quebraData(datainicial);
    DataQuebrada dtFinal = quebraData(datafinal);

    if (dtInicial.valido == 0){
        dma.retorno = 2;
        return dma;

    }else if (dtFinal.valido == 0){
        dma.retorno = 3;
        return dma;
    
    }else if(dataInicialMaiorDataFinal(datainicial, datafinal) == 0){
        //verifique se a data final não é menor que a data inicial
        dma.retorno = 4;
        return dma;

    }else{
        
        dma.qtdDias = dtFinal.iDia - dtInicial.iDia;
        dma.qtdMeses = dtFinal.iMes - dtInicial.iMes;
        dma.qtdAnos = dtFinal.iAno - dtInicial.iAno;
        
        //printf("----> %d/%d/%d\n", dma.qtdDias, dma.qtdMeses, dma.qtdAnos);
        if (dma.qtdMeses < 0){
            dma.qtdAnos--;
            dma.qtdMeses += 12;
        }

        if (dma.qtdDias < 0){
            if(dma.qtdMeses == 0){
                dma.qtdAnos--;
                dma.qtdMeses = 11;
            }else
                dma.qtdMeses--;
            dma.qtdDias = QuantidadeDeDiasMesAnterior(dtFinal.iMes-1, dtFinal.iAno) - dtInicial.iDia + dtFinal.iDia;
        }      
        //printf("----> %d/%d/%d\n", dma.qtdDias, dma.qtdMeses, dma.qtdAnos);
        //se tudo der certo
        dma.retorno = 1;
        return dma;
    }
    
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    if(isCaseSensitive == 1){
        
        for(int i = 0; i < strlen(texto); i++){
            if(texto[i] == c)
                qtdOcorrencias++;
        }
    }else{
        for(int i = 0; i < strlen(texto); i++){
            if(toupper(texto[i]) == toupper(c))
                qtdOcorrencias++;
        }
    }
    return qtdOcorrencias;
}

/* 
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]){

    int qtdOcorrencias = 0;
    int count = 0;
    int x = 0;
    int qtdAcento = 0;

    for(int i = 0; i < strlen(strTexto); i++){
        if(strTexto[i] < 0){
            qtdAcento++;
        }

        if(strTexto[i] == strBusca[0]){

            for(int j = 0; j < strlen(strBusca); j++){

                if(strTexto[j+i] == strBusca[j]){
                    count++;
                }else{
                    count = 0;
                }
            }
        }

        if(count == strlen(strBusca)){
            qtdOcorrencias++;
            posicoes[x] = i+1-(qtdAcento/2); x++;
            i += count-1;
            posicoes[x] = i+1-(qtdAcento/2); x++;
            count = 0;
        }

    }
    
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    int numInverso = 0, restoDivisao = 0; 

    while(num > 0){    
        restoDivisao = num % 10;
        numInverso = numInverso * 10 + restoDivisao;    
        num /= 10;    
    }   

    return numInverso;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */
int digitos(int number){

    int qtdDigito = 0;

    while(number > 0){
        qtdDigito++;
        number /= 10;
        
    }
    return qtdDigito;
}

int grandeza(int number){
    
    int qtdDigitoBusca = 0;

    qtdDigitoBusca = digitos(number);

    return (int)(pow(10, qtdDigitoBusca) + 0.5);
}

int identificarIgualdade(int number){

    int qtdDigito = 0;

    while(number > 0){       
        if(number / 10 == number % 10) qtdDigito++;
        
        number /= 10;    
    }
    return qtdDigito;
}

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int gdBusca = grandeza(numerobusca);
    
    while(numerobase > 0){

        if((numerobase % gdBusca) == numerobusca){
            qtdOcorrencias++;
        }

        if(identificarIgualdade(numerobusca)+1 == digitos(numerobusca)) numerobase /= gdBusca;
        else numerobase /= 10;
    }

    return qtdOcorrencias;
}
