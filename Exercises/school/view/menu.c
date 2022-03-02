#include "../util/utility.h"
#include "../util/validation.h"
#include "../model/menu.h"
#include "../model/discipline.h"
#include "../model/student.h"
#include "../model/teacher.h"

void logo(){

    

    printf("  SSSSSSSSSSSSSSS    UUUUUUU     UUUUUUU validateSystem();              AAA                 PPPPPPPPPPPPPPPPP\n");
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

    system(CLEAR);
      
}

void header(){

    system(CLEAR);

    printf ("***********************************************\n");
    printf ("\t GERENCIAMENTO ESCOLAR\n");
    printf ("***********************************************\n\n");
}

void menu(){

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
            //case 2:mainTeacher();break;    
            //case 3:mainDiscipline();break;
            case 4:
                printf("Acesso finalizado!");
                getchar();
                break;
            default:
                printf("Opção inválida!");
                getchar();
                break;
        }
    }while(option != 4);

}