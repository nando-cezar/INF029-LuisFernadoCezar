#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 255
#define MAX_CPF_LEN 15

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    char name[MAX_NAME_LEN];
    Date birthDate;
    char CPF[MAX_CPF_LEN];
    char gender;
} Client;

Client registerClient();

int main(){

    Client client = registerClient();
    printf("\n%s\n%d/%d/%d\n%s\n%c", 
    client.name, 
    client.birthDate.day, 
    client.birthDate.month, 
    client.birthDate.year, 
    client.CPF, 
    client.gender); 

    return 0;
}

Client registerClient(){

    Client client;

    printf("Insert name: ");
    fgets(client.name, MAX_NAME_LEN, stdin);
    printf("Insert birth date: ");
    scanf("%d %d %d", 
    &client.birthDate.day, 
    &client.birthDate.month, 
    &client.birthDate.year);
    printf("Insert CPF: ");
    fgets(client.CPF, MAX_CPF_LEN, stdin);   
    printf("Insert gender (M/F): ");
    scanf(" %c", &client.gender);
    
    return client;
}
