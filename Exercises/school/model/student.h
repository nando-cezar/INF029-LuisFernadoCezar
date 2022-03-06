#ifndef STUDENT_H // include guard

    #define STUDENT_H

    typedef struct detailsStudent{
        char enrollment[MAX_ENR_LEN];
        char name[MAX_NAME_LEN];
        Date birthDate;
        char CPF[MAX_CPF_LEN];
        char gender;
        //char disciplineCode[MAX_DISC][MAX_ENR_LEN];
    } Student; 
    
    void createStudent();
    void retrieveStudent();
    void retrieveStudentByGender();
    void retrieveStudentByName();
    void sortStudentByName();
    void sortStudentByBirthDate();
    void birthdaysOfTheMonthStudent();
    void updateStudent();
    void deleteStudent();
    void mainStudent();
    void printStudent(Student student);
    Student insertStudent(Student student);

#endif
