typedef struct detailsDiscipline{
    long int code;
    char name[MAX_NAME_LEN];
    int semester;
    Teacher teacher;
} Discipline;

Discipline registerDiscipline();
