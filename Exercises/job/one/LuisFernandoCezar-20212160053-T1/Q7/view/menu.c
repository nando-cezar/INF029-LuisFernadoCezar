#include "../utility/utility.h"
#include "menu.h"

void logo(){

    system(CLEAR);

    printf("   NNNNNNNNNN         NNNNNNNN            CCCCCCCCCCCCCCCCCCCCCC\n");
    printf("   N::::::::N         N::::::N           C::::::::::::::::::::::C\n");
    printf("   N:::::::: N        N::::::N          C:::::::::CCCCCCCC::::::::C\n");
    printf("   N::::::::::N       N::::::N         C:::::::::C        C::::::::C\n");
    printf("   N::::::NN:::N      N::::::N        C:::::::::C          CCCCCCCCC\n");
    printf("   N::::::N N:::N     N::::::N        C::::::::C\n");  
    printf("   N::::::N  N:::N    N::::::N        C::::::::C\n");
    printf("   N::::::N   N:::N   N::::::N        C::::::::C\n");
    printf("   N::::::N    N:::N  N::::::N        C::::::::C\n");
    printf("   N::::::N     N:::N N::::::N        C::::::::C\n");
    printf("   N::::::N      N:::NN::::::N        C::::::::C\n");
    printf("   N::::::N       N::::::::::N        C::::::::C          CCCCCCCCCC\n");
    printf("   N::::::N        N:::::::::N         C::::::::C        C:::::::::C\n");
    printf("   N::::::N         N::::::::N          C::::::::CCCCCCCC:::::::::C\n");
    printf("   N::::::N          N:::::::N           C:::::::::::::::::::::::C\n");
    printf("   NNNNNNNN           NNNNNNNN            CCCCCCCCCCCCCCCCCCCCCCC\n");

   
    printf("\n\n\n             ..:: Sejam bem-vindos ao game! ::.. \n");

    printf ("\n\nCarregando o sistema: \n\n");

    for (int i = 1; i <= 50; i++){
      printf ("  %d%%\r", i*2);
      fflush (stdout);

        for (int j = 0; j < i; j++){
            if (!j)
            printf("  ");

            printf ("%c", 2);
            #if defined(_WIN32) || defined(_WIN64)
                sleep(0.5); 
            #else
                usleep(0.5*1000);  
            #endif
        }
    }

    system(CLEAR);
      
}