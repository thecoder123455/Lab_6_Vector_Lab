/*
* filename: vectParse.h
* author: Nick G
* date 9/29/26
* Turning user input data into vectors
 */
#include "vect.h"

 vect *createVect(const char *name, double x, double y, double z);

 char getOperator(const char *input);

 void vectParse(char *userInput);