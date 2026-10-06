/*
* filename: vectParse.c
* author: Nick G
* date 9/29/26
* Turning user input data into vectors
 */
#include <stdio.h>
#include <string.h>
#include "vect.h"
#include "vectParse.h"
#include "vectArray.h"
#include "vectorCalc.h"


//turns the name, x, y, and z coordinates into a new vector 
 vect *createVect(const char *name, double x, double y, double z){
    vect newVect;
    strcpy(newVect.name, name);
    newVect.x = x;
    newVect.y = y;
    newVect.z = z;
    addVect(newVect);
    return getVect(name);
 }

 // gets the operator (if there is one)
char getOperator(const char *input){
    for(int i = 0; input[i] != '\0'; i++){
        if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
            return input[i];
        }
    }

    return '\0';
}

void vectParse(char *userInput){
    //getting rid of commas
    for(int i = 0; userInput[i] != '\0'; i++){
    if(userInput[i] == ','){
        userInput[i] = ' ';
    }
    }

    char operation = getOperator(userInput);

    //This means we're creating a new vector instead of 
    //adjusting a current one
    if(getOperator(userInput) == '\0'){

    char destVect[8];
    double x, y, z = 0;

    int count = sscanf(userInput, "%7s = %lf %lf %lf", destVect, &x, &y, &z); 

    if(count == 3){
        z = 0;
    }
    if(count < 3){
        printf("INVALID VECTOR FORMAT\n");
        return;
    }

    vect *v3 = createVect(destVect, x, y, z);
    
    if(v3 != NULL){
         printf("%s = %1f %1f %f\n", v3->name, v3->x, v3->y, v3->z);
    }
   

    } else if (operation == '+' || operation == '-'){
        
        char destName[8];
        char v1Name[8];
        char v2Name[8];

        int count = sscanf(userInput, "%7s = %7s %*c %7s \n", destName, v1Name, v2Name);

        if(count != 3){
            printf("INVALID VECTOR OPERATION\n");
            return;
        }

        vect *v1 = getVect(v1Name);
        vect *v2 = getVect(v2Name);

        if(v1 == NULL || v2 == NULL){
            printf("ONE OR BOTH VECTORS ARE NOT DEFINED\n");
            return;
        }

        vect result = vectCalc(*v1, *v2, operation, 0);
        strcpy(result.name, destName);
        addVect(result);

       printf("%s = %f, %f, %f\n", result.name, result.x, result.y, result.z);

      // SCALAR MULTIPLICATION
    } else if(operation == '*'){
        char destName[8];
        char v1Name[8];
        double multiplier;

        int count = sscanf(userInput, "%7s = %7s * %lf", destName, v1Name,&multiplier);

        if(count != 3){
            printf("INVALID VECTOR MULTIPLICATION\n");
            return;
        }

        vect *v1 = getVect(v1Name);

        if(v1 == NULL){
            printf("VECTOR IS NOT DEFINED\n");
            return;
        }

        vect dummyVect = {0};
        vect result = vectCalc(*v1, dummyVect, operation, multiplier);
        strcpy(result.name, destName);
        addVect(result);

        printf("%s = %f, %f, %f\n", result.name, result.x, result.y, result.z);
    }
}

