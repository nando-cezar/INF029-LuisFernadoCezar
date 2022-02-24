#include <stdio.h>

#include "../school/src/util/utility.h"
#include "../school/src/model/interface/student.h"
#include "../school/src/model/interface/teacher.h"
#include "../school/src/model/interface/discipline.h"

void logo();
void menu();

int main(){

    logo();

    return 0;
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
        sleep(1);
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