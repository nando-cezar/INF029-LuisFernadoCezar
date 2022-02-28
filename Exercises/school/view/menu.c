#include "menu.h"
#include "../util/utility.h"
#include "../model/interface/discipline.h"
#include "../model/interface/student.h"
#include "../model/interface/teacher.h"

void logo(){

    system("cls");

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
        sleep(0.75);
      }
   }

   system("cls");
      
}

void header(){

    system("cls");

    printf ("***********************************************\n");
    printf ("\t GERENCIAMENTO ESCOLAR\n");
    printf ("***********************************************\n\n");
}

void menu(){

    //setlocale(LC_ALL, "Portuguese");

    int option;

    do{
        header();
        printf("1 - Estudante;\n");
        printf("2 - Professor;\n");
        printf("3 - Disciplina;\n");
        printf("4 - Sair;\n\n");
        printf("Escolha sua opção: ");
        scanf("%d", &option);

        switch (option){
            case 1:mainStudent();break;    
            //case 2:registerTeacher();break;    
            //case 3:registerDiscipline();break;
            case 4:
                printf("Acesso finalizado!");
                getch();
                break;
            default:
                printf("Opção inválida!");
                getch();
                break;
        }
    }while(option != 4);

}