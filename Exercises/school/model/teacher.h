#ifndef TEACHER_H // include guard

    #define TEACHER_H

    typedef struct detailsTeacher{
        char enrollment[MAX_ENR_LEN];
        char name[MAX_NAME_LEN];
        Date birthDate;
        char CPF[MAX_CPF_LEN];
        char gender;
        //char disciplines[MAX_DISC][MAX_ENR_LEN];
    } Teacher; 
    
    void createTeacher();
    void retrieveTeacher();
    char* retrieveTeacherSelected();
    void retrieveTeacherByGender();
    void retrieveTeacherByName();
    void sortTeacherByName();
    void sortTeacherByBirthDate();
    void birthdaysOfTheMonthTeacher();
    void updateTeacher();
    void deleteTeacher();
 
    void printTeacher(Teacher teacher);
    void printSummaryTeacher(Teacher teacher);
    Teacher insertCreateTeacher(Teacher teacher);
    Teacher insertUpdateTeacher(Teacher teacher);
    void mainTeacher(); 

    int isExistingTeacher(char enrollment[]);

#endif
