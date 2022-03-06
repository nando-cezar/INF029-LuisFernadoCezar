#ifndef TEACHER_H // include guard

    #define TEACHER_H

    typedef struct detailsTeacher{
        char enrollment[MAX_ENR_LEN];
        char name[MAX_NAME_LEN];
        Date birthDate;
        char CPF[MAX_CPF_LEN];
        char gender;
    } Teacher; 
    
    void createTeacher();
    void retrieveTeacher();
    void retrieveTeacherByGender();
    void retrieveStudentByName();
    void sortTeacherByName();
    void sortTeacherByBirthDate();
    void birthdaysOfTheMonthTeacher();
    void updateTeacher();
    void deleteTeacher();
    void mainTeacher();
    void printTeacher(Teacher teacher);
    Teacher insertTeacher(Teacher teacher);

#endif
