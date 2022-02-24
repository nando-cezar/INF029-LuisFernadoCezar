typedef struct detailsStudent{
    int enrollment;
    char name[MAX_NAME_LEN];
    Date birthDate;
    char CPF[MAX_CPF_LEN];
    char gender;
} Student;

Student registerStudent();
