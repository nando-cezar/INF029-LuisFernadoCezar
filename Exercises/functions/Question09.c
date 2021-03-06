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
int stringLenght(char string[]);
int validateName(char name[]);
int validateBirthDate(int day, int month, int year);
int validateCPF(char CPF[]);
int validateGender(char gender);

int main(){

    Client client = registerClient();
    
    if(
    validateName(client.name) 
    || validateBirthDate(
        client.birthDate.day, 
        client.birthDate.month, 
        client.birthDate.year) 
    || validateCPF(client.CPF)
    || validateGender(client.gender)
    ){
        printf("Internal Server Error! ");
        return 0;
    }
    
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
    printf("Insert CPF: ");
    fgets(client.CPF, MAX_CPF_LEN, stdin);
    printf("Insert birth date: ");
    scanf("%d %d %d", 
    &client.birthDate.day, 
    &client.birthDate.month, 
    &client.birthDate.year);   
    printf("Insert gender (M/F): ");
    scanf(" %c", &client.gender);
    
    return client;
}

int validateName(char name[]){ // name.lenght()

    if(stringLenght(name) > 19)
        return -1;
    
    return 0;
}

int validateBirthDate(int day, int month, int year){ // basic validation

    if(day < 0 && day > 32)
        return -1;
    if(month < 0 && month > 12)
        return -1;
    if(year < 0)
        return -1;

    return 0;
}

int validateCPF(char CPF[]){ // xxx.xxx.xxx-xx | basic validate

    if(stringLenght(CPF) > 14 || stringLenght(CPF) < 14)
        return -1;

    return 0;
}

int validateGender(char gender){

    if(
    gender == 'M' || 
    gender == 'm' || 
    gender == 'F' || 
    gender == 'f' || 
    gender == 'O' || 
    gender == 'o'
    )
        return 0;
    
    return -1;
}

int stringLenght(char string[]){

    int count = 0;

    for(int i = 0; string[i] != '\0'; i++)
        count++;

    return count;
}
