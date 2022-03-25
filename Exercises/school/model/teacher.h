#ifndef TEACHER_H // include guard

    #define TEACHER_H

    typedef struct detailsTeacher{
        char enrollment[MAX_ENR_LEN];
        char name[MAX_NAME_LEN];
        Date birthDate;
        char CPF[MAX_CPF_LEN];
        char gender;
        char disciplineCode[MAX_DISC][MAX_ENR_LEN];
    } Teacher; 
    
    void createTeacher();
    void retrieveTeacher();
    Teacher retrieveDataTeacher(char enrollment[]);
    Teacher retrieveObjectTeacher(int *idSelected, int *sizeArray);
    char* retrieveEnrollmentTeacher();
    void retrieveTeacherByGender();
    void retrieveTeacherByName();
    void sortTeacherByName();
    void sortTeacherByBirthDate();
    void birthdaysOfTheMonthTeacher();
    void updateTeacher();
    void deleteTeacher();
 
    void printFullTeacher(Teacher teacher);
    void printSummaryTeacher(Teacher teacher);
    void printSummaryTeacherWithBirthDate(Teacher teacher);
    Teacher insertCreateTeacher(Teacher teacher);
    Teacher insertUpdateTeacher(Teacher teacher);
    void mainTeacher(); 

    int isExistingTeacher(char enrollment[]);

    Teacher* toPointerTeacher(size_t *nReg, size_t size, char filePath[], char mode[]);
    void toFileTeacher(Teacher *ptrTeacher, size_t size, char filePath[], char mode[], int idSelected);

#endif
