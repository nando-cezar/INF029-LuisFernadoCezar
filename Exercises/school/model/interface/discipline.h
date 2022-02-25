#ifndef DISCIPLINE_H // include guard
#define DISCIPLINE_H

typedef struct detailsDiscipline{
    long int code;
    char name[MAX_NAME_LEN];
    int semester;
    struct detailsTeacher *teacher;
} Discipline;

Discipline registerDiscipline();

#endif
