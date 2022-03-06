#!/usr/bin/bash
gcc -o main main.c global/validation/*.c global/function/*.c controller/*.c view/*.c 
read -p "Pressione alguma tecla para continuar ou CTRL C para sair"
./main