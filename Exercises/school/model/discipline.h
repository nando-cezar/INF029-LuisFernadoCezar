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
    Discipline retrieveObjectDiscipline(int *idSelected, int *sizeArray);
    void retrieveDisciplineWithStudent();
    void retrieveDisciplineWithMoreThan40Students();
    void updateDiscipline();
    void deleteDiscipline();
    void deleteStudentInDiscipline();

    void printFullDiscipline(Discipline discipline, Teacher teacher);
    void printSummaryDiscipline(Discipline discipline, Teacher teacher);
    void printMaxSummaryDiscipline(Discipline discipline);
    Discipline insertCreateDiscipline(Discipline discipline);
    Discipline insertUpdateDiscipline(Discipline discipline);
    void mainDiscipline();

    int isExistingDiscipline(char code[]);
    int checkStudentInDiscipline(char code[], char enrollment[]);

    Discipline* toPointerDiscipline(size_t *nReg, size_t size, char filePath[], char mode[]);
    void toFileDiscipline(Discipline *ptrDiscipline, size_t size, char filePath[], char mode[], int idSelected);
    
#endif

