#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 255
#define MAX_CPF_LEN 15
#define MAX_REGISTER_LEN 255

typedef struct {
    int year;
    int month;
    int day;
} Date;

typedef struct {
    int enrollment;
    char name[MAX_NAME_LEN];
    Date birthDate;
    char CPF[MAX_CPF_LEN];
    char gender;
} Student;

typedef struct {
    int enrollment;
    char name[MAX_NAME_LEN];
    Date birthDate;
    char CPF[MAX_CPF_LEN];
    char gender;
} Teacher;

typedef struct {
    long int code;
    char name[MAX_NAME_LEN];
    int semester;
    Teacher teacher;
} Discipline;

Student registerStudent();
Student menuStudent();
Teacher registerTeacher();
Teacher menuTeacher();
Discipline registerDiscipline();
Discipline menuDiscipline();

void logo();
void menu();

int main(){

    logo();

    return 0;
}

Student registerStudent(){

    Student student;
    student = menuStudent();
    
    return student;
}

Teacher registerTeacher(){

    Teacher teacher;
    teacher = menuTeacher();
    
    return teacher;
}

void logo(){
    
   printf("  SSSSSSSSSSSSSSS    UUUUUUU     UUUUUUU               AAA                 PPPPPPPPPPPPPPPPP\n");
   printf(" SS:::::::::::::::S  U:::::U     U:::::U             A:::::A               P::::::::::::::::PP\n");
   printf("S:::::SSSSSS::::::S  U:::::U     U:::::U            A::AAA::A              P::::PPPPPPPPP::::PP\n");
   printf("S:::::S     SSSSSSS  U:::::U     U:::::U           A::A   A::A             P::::P        P::::PP\n");
   printf("S:::::S              U:::::U     U:::::U          A::A     A::A            P::::P        P::::PP\n");
   printf("S:::::S              U:::::D     D:::::U         A::A       A::A           P::::P        P::::PP\n");
   printf(" S::::SSSS           U:::::D     D:::::U        A::A         A::A          P::::PPPPPPPPP::::PP\n");
   printf("  SS::::::SSSSS      U:::::D     D:::::U       A::A           A::A         P:::::::::::::::PP\n");
   printf("    SSS::::::::SS    U:::::D     D:::::U      A::::AAAAAAAAAA:::::A        P:::PPPPPPPPPPPP\n");
   printf("       SSSSSS::::S   U:::::D     D:::::U     A:::::::::::::::::::::A       P:::P\n");
   printf("            S:::::S  U:::::D     D:::::U    A:::::::::::::::::::::::A      P:::P\n");
   printf("            S:::::S  U::::::U   U::::::U   A::::: AAAAAAAAAAAA:::::::A     P:::P\n");
   printf("SSSSSSS     S:::::S  U:::::::UUU:::::::U  A:::::A              A::::::A    P:::P\n");
   printf("S::::::SSSSSS:::::S   UU:::::::::::::UU  A:::::A                A::::::A   P:::P\n");
   printf("S:::::::::::::::SS     UU:::::::::UU    A:::::A                  A::::::A  P:::P\n");
   printf(" SSSSSSSSSSSSSSS         UUUUUUUUU      AAAAAA                     AAAAA   PPPP\n");

   
    printf("\n\n\n             ..:: Sejam bem-vindos ao SUAP-SISTEMA ACADEMICO! ::.. \n");

   printf ("\n\nCarregando o sistema: \n\n");

    for (int i = 1; i <= 50; i++){
      printf ("  %d%%\r", i*2);
      fflush (stdout);

      for (int j = 0; j < i; j++){
        if (!j)
        printf("  ");

        printf ("%c", 2);
        sleep(3);
      }
   }
      
    system("cls");
    menu();
}

void menu(){

    int opcao;
    system("cls");
    do{
        printf("MENU PRINCIPAL\n");
        printf("--------------\n\n");
        printf("1 - Professor\n");
        printf("2 - Aluno\n");
        printf("3 - Administrador\n");
        printf("4 - Sair\n\n");
        printf("Escolha sua opcao: ");
        scanf("%d",& opcao);
        system("cls");
        fflush(stdin);
    }while((opcao<1 ) || (opcao>4) );

    /*switch (opcao){
        case 1:validacao_prof();break;    
        case 2:validacao_aluno();break;    
        case 3:validacao_adm();break;
        case 4:sair_sistema(); break;
    }*/

}


Student menuStudent(){

    size_t ln;
    Student student;

    printf("Inserir matricula: ");
    scanf("%d", &student.enrollment);

    printf("Inserir nome: ");
    fgets(student.name, MAX_NAME_LEN, stdin);
    ln = strlen(student.name) - 1;
    if (student.name[ln] == '\n')
      student.name[ln] = '\0';

    printf("Inserir CPF: ");
    fgets(student.CPF, MAX_CPF_LEN, stdin);
    ln = strlen(student.CPF) - 1;
    if (student.CPF[ln] == '\n')
      student.CPF[ln] = '\0';

    printf("Inserir data de nascimento: ");
    scanf("%d %d %d", 
    &student.birthDate.day, 
    &student.birthDate.month, 
    &student.birthDate.year);   

    printf("Inserir genero (M/F): ");
    scanf(" %c", &student.gender);

    return student;
}

Teacher menuTeacher(){

    size_t ln;
    Teacher teacher;
    
    printf("Inserir matricula: ");
    scanf("%d", &teacher.enrollment);

    printf("Inserir nome: ");
    fgets(teacher.name, MAX_NAME_LEN, stdin);
    ln = strlen(teacher.name) - 1;
    if (teacher.name[ln] == '\n')
      teacher.name[ln] = '\0';

    printf("Inserir CPF: ");
    fgets(teacher.CPF, MAX_CPF_LEN, stdin);
    ln = strlen(teacher.CPF) - 1;
    if (teacher.CPF[ln] == '\n')
      teacher.CPF[ln] = '\0';

    printf("Inserir data de nascimento: ");
    scanf("%d %d %d", 
    &teacher.birthDate.day, 
    &teacher.birthDate.month, 
    &teacher.birthDate.year);   

    printf("Inserir genero (M/F): ");
    scanf(" %c", &teacher.gender);

    return teacher;
}