/*
* filename: vectArray.c
* author: Nick G
* date 9/29/26
* Stores, adds, clears, and lists the vectors
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vect.h"
#include "vectParse.h"
#include "vectArray.h"
#include "vectorCalc.h"
#define MAX_VECTORS 10

vect totalVect[MAX_VECTORS];

//ADDS A VECTOR
 void addVect(vect newVect){

    // first check if the vector already exists
    for(int i = 0; i < MAX_VECTORS; i++){
        if(totalVect[i].name[0] != '\0' &&
           strcmp(totalVect[i].name, newVect.name) == 0){

            totalVect[i] = newVect;
            return;
        }
    }

    // if it doesn't already exist add it to an empty slot
    for(int i = 0; i < MAX_VECTORS; i++){
        if(totalVect[i].name[0] == '\0'){
            totalVect[i] = newVect;
            return;
        }
    }

    printf("VECTOR MEMORY IS FULL\n");
}
// GETS A VECTOR BASED ON NAME
 vect *getVect(const char *name){
    for (int i = 0; i < MAX_VECTORS; i++){
        
        if(totalVect[i].name[0] != '\0' && 
            strcmp(totalVect[i].name, name) == 0){
            return &totalVect[i];
        }
        }
        return NULL;
 }
 // CLEARS THE ARRAY
 void clear(){
        for(int i = 0; i < MAX_VECTORS; i++){
            memset(&totalVect[i], 0, sizeof(vect));
        }
 }

 //LISTS EVERYTHING

 void list(){
    int length = sizeof(totalVect) / sizeof(totalVect[0]);
    int count = 0;
    for(int i = 0; i < length; i++){
        if(totalVect[i].name[0] != '\0'){
        printf("%s = %f, %f, %f\n", totalVect[i].name, totalVect[i].x, totalVect[i].y, totalVect[i].z);
        count++;
        }
    }
    printf("Total Vectors = %d\n", count);
}