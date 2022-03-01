#include "../util/utility.h"
#include "../model/student.h"

void printStudent(Student student){

  printf("Matricula: %s\n", student.enrollment);
  printf("Nome: %s\n", student.name);
  printf("CPF: %s\n", student.CPF);
  printf("Data de nascimento: %d/%d/%d\n", 
  student.birthDate.day,
  student.birthDate.month,
  student.birthDate.year
  );
  printf("Gênero: %c\n", student.gender);
  printf ("\n***********************************************\n\n");

}

Student insertStudent(Student student){

  size_t ln;

  printf("Inserir matricula: ");
  fgets(student.enrollment, MAX_ENR_LEN, stdin);
  ln = strlen(student.enrollment) - 1;
  if (student.enrollment[ln] == '\n')
    student.enrollment[ln] = '\0';

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
  getchar();

  printf("Inserir gênero (M/F): ");
  scanf(" %c", &student.gender);
  getchar();

  return student;
}