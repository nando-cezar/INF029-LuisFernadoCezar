#ifndef STUDENT_H // include guard

    #define STUDENT_H

    typedef struct detailsStudent{
        char enrollment[MAX_ENR_LEN];
        char name[MAX_NAME_LEN];
        Date birthDate;
        char CPF[MAX_CPF_LEN];
        char gender;
        char disciplineCode[MAX_DISC][MAX_ENR_LEN];
    } Student; 
    
    void createStudent();
    void retrieveStudent();
    void retrieveStudentWithLessThan3Disciplines();
    Student retrieveDataStudent(char enrollment[]);
    Student retrieveObjectStudent(int *idSelected, int *sizeArray);
    char* retrieveEnrollmentStudent();
    void retrieveStudentByGender();
    void retrieveStudentByName();
    void sortStudentByName();
    void sortStudentByBirthDate();
    void birthdaysOfTheMonthStudent();
    void updateStudent();
    void deleteStudent();
    
    void printFullStudent(Student student);
    void printSummaryStudent(Student student);
    void printSummaryStudentWithBirthDate(Student student);
    Student insertCreateStudent(Student student);
    Student insertUpdateStudent(Student student);
    void mainStudent();

    int isExistingStudent(char enrollment[]);

    Student* toPointerStudent(size_t *nReg, size_t size, char filePath[], char mode[]);
    void toFileStudent(Student *ptrStudent, size_t size, char filePath[], char mode[], int idSelected);

#endif 
