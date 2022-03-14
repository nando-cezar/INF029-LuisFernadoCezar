#ifndef DISCIPLINE_H // include guard

    #define DISCIPLINE_H

    typedef struct detailsDiscipline{ 
        char code[MAX_ENR_LEN];
        char name[MAX_NAME_LEN];
        int semester;
        char teacherEnrollment[MAX_ENR_LEN];
        char studentEnrollment[MAX_STUDENTS_DISC][MAX_ENR_LEN];
    } Discipline;

    void createDiscipline();
    void insertStudentInDiscipline();
    void retrieveDiscipline();
    Discipline retrieveDisciplineSelected();
    void retrieveDisciplineWithStudent();
    void updateDiscipline();
    void deleteDiscipline();
    void deleteStudentInDiscipline();

    void printDiscipline(Discipline discipline, Teacher teacher);
    void printSummaryDiscipline(Discipline discipline, Teacher teacher);
    Discipline insertDiscipline(Discipline discipline);
    void mainDiscipline();

    int isExistingDiscipline(char code[]);
    int checkDisciplineStudent(char code[],char enrollment[]);
    
#endif

