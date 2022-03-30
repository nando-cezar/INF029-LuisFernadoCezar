#include "../util/utility.h"
#include "../model/menu.h"
#include "../model/student.h"
#include "../model/teacher.h"
#include "../model/discipline.h"

void logo(){

    

    printf("  SSSSSSSSSSSSSSS    UUUUUUU     UUUUUUU              AAAAA                PPPPPPPPPPPPPPPPP\n");
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

    printf("****************************************************\n");
    printf("\t ..:: SUAP | SISTEMA ACADEMICO ::..\n");
    printf("****************************************************\n\n");
}

void menu(){

    int option;

    setlocale(LC_ALL, "Portuguese");

    do{
        system(CLEAR);
        printf("  ssssssssss   uuu    uuu         a         pppppppppp\n");
        printf("s:::sssss:::s  u:u    u:u        aaa        p::ppppp::pp\n");
        printf("s:::s    ssss  u:u    u:u       a:a:a       p::p    p::pp\n");
        printf(" s::::s        u:u    u:u      a:a a:a      p::pppppp:pp\n");
        printf("    s::ss      u:u    u:u     a:a   a:a     p::pppppppp\n");
        printf("       s::ss   u:u    u:u    a::aaaaa::a    p::p\n");
        printf("ssss    s:::s  u:u    u:u   a::a     a::a   p::p\n");
        printf("s::sssss:::s    u:uuuu:u   a::a       a::a  p::p\n");
        printf(" sssssssss        uuuu    aaaa         aaaa pppp\n");
        printf("\n\n\t ..:: SUAP | SISTEMA ACADEMICO ::..\n\n");
        printf("1 - Estudante;\n");
        printf("2 - Professor;\n");
        printf("3 - Disciplina;\n");
        printf("4 - Sair;\n\n");
        printf("Escolha sua opção: ");
        scanf("%d", &option);

        switch (option){
            case 1:mainStudent();break;    
            case 2:mainTeacher();break;    
            case 3:mainDiscipline();break;
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