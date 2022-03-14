#ifndef GLOBAL_H // include guard

    #define GLOBAL_H

    int isLarger(int numberOne, int numberTwo);
    size_t structAmount(FILE *file, void *obj, size_t size);
    void textToUpper(char* string);
    char charToUpper(char ch);
    int verifyNumber(char *string);
    void removeBreakLine(char *string);
    void removeSpace(char* string);
    void toPointer(void *pointer, size_t *nReg, size_t size, FILE *file);
#endif