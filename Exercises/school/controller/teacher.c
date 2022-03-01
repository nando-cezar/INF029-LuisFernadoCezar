#include "../util/utility.h"
#include "../model/menu.h"
#include "../model/teacher.h"

void createTeacher(){

  
}

void retrieveTeacher(){

  
}

void retrieveTeacherByGender(){

  
}

void sortTeacherByName(){

  
}

void sortTeacherByBirthDate(){

 
}

void birthdaysOfTheMonth(){

  
}

void deleteTeacher(){

  
}

void mainTeacher(){

  int option;

  do{
    header();
    printf("1. Inserir professor;\n");
    printf("2. Listar professores;\n");
    printf("3. Listar professores por sexo (M/F);\n");
    printf("4. Listar professores ordenados por nome;\n");
    printf("5. Listar professores ordenados data de nascimento;\n");
    printf("6. Aniversariantes do mês;\n");
    printf("7. Atualizar professor;\n");
    printf("8. Excluir professor;\n");
    printf("9. Retornar ao menu principal;\n\n");
    printf("\nEscolha uma opção: ");
    scanf("%d", &option);
    getchar();
    switch(option){
      case 1:createTeacher();break;
      case 2:retrieveTeacher();break;
      case 3:retrieveTeacherByGender();break;
      case 4:sortTeacherByName();break; //implementing
      case 5:sortTeacherByBirthDate();break; //implementing
      case 6:birthdaysOfTheMonth();break;
      case 7:updateTeacher();break;
      case 8:deleteTeacher();break;
      case 9: break;
      default: 
        printf("Opção inválida!\n"); 
        getch();
        break;
    }
  }while(option != 9);

}