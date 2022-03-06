#ifndef DISCIPLINE_H // include guard

    #define DISCIPLINE_H

    typedef struct detailsDiscipline{ 
        char code[MAX_ENR_LEN];
        char name[MAX_NAME_LEN];
        int semester;
        struct detailsTeacher *teacher;
    } Discipline;

    void createDiscipline();
    void retrieveDiscipline();
    void updateDiscipline();
    void deleteDiscipline();
    void mainDiscipline();
    void printDiscipline(Discipline discipline);
    Discipline insertDiscipline();

#endif

