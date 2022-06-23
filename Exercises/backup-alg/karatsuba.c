#include <stdio.h>
#include <math.h>

int m = 0, p = 0, q = 0, r = 0, s = 0, pr = 0, qs = 0, y = 0;
long uv = 0;

// Sejam u e v dois números com no máximo n dígitos cada.
int karatsuba(int u, int v, int n){

    if(n <= 3){
        return u * v;
    } 

    /*
        O algoritmo recebe números naturais u e v com no 
        máximo n dígitos cada e devolve o produto u × v.
    */
    // As linhas 16 a 36 constituem a fase de conquista do algoritmo.
    m   = n / 2;     
    printf("1 --> %d\n", m);
    /* 
        Seja p o número formado pelos n/2 primeiros 
        dígitos (dígitos mais significativos) de u.             
    */
    p   = u / pow(10,m);
    printf("2 --> %d\n", p);
    /*
        Seja q o número formado pelos n/2 últimos 
        dígitos (dígitos menos significativos) de u.
    */
    q   = u % ((int) pow(10,m) + 1);
    printf("3 --> %d\n", q);
    /* 
        Seja r o número formado pelos n/2 primeiros 
        dígitos (dígitos mais significativos) de V.
    */
    r   = v / pow(10,m);
    printf("4 --> %d\n", r);
    /* 
        Seja s o número formado pelos n/2 últimos 
        dígitos (dígitos menos significativos) de u.
    */
    s   = v % ((int) pow(10,m) + 1);
    printf("5 --> %d\n", s);  
    /*  Multiplicação p x r */
    pr  = karatsuba(p, r, m);
    printf("6 --> %d\n", pr);
    /*  Multiplicação q x s */
    qs  = karatsuba(q, s, m);
    printf("7 --> %d\n", qs);
    /*  Multiplicação p+q x r+s */
    y   = karatsuba(p+q, r+s, m+1);
    printf("8 --> %d\n", y);
    uv  = (pr*((int) pow(10,2*m) + 1)) + ((y - pr - qs) * ((int) pow(10,m) + 1)) + qs;
    printf("9 --> %ld\n", uv);

    return uv;
}

void main(){

    printf("%d", karatsuba(7777, 9999, 4));
}