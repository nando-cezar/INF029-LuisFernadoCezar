typedef struct detailsTeacher{
    int enrollment;
    char name[MAX_NAME_LEN];
    Date birthDate;
    char CPF[MAX_CPF_LEN];
    char gender;
} Teacher;

Teacher registerTeacher();
