/*
* filename: vectArray.c
* author: Nick G
* date 9/29/26
* Stores, adds, clears, and lists the vectors :)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "vect.h"
#include "vectParse.h"
#include "vectArray.h"
#include "vectorCalc.h"

vect *totalVect = NULL;
size_t totalVectCapacity = 0;

//ADDS A VECTOR
 void addVect(vect newVect){
    if (totalVectCapacity == 0 && !increaseArray()) {
        return;
    }

    // first check if the vector already exists
    for(size_t i = 0; i < totalVectCapacity; i++){
        if(totalVect[i].name[0] != '\0' &&
           strcmp(totalVect[i].name, newVect.name) == 0){

            totalVect[i] = newVect;
            return;
        }
    }

    // if it doesn't already exist add it to an empty slot
    for(size_t i = 0; i < totalVectCapacity; i++){
        if(totalVect[i].name[0] == '\0'){
            totalVect[i] = newVect;
            return;
        }
    }

    size_t oldCapacity = totalVectCapacity;
    if (increaseArray()) {
        totalVect[oldCapacity] = newVect;
    }
}
// GETS A VECTOR BASED ON NAME
 vect *getVect(const char *name){
    for (size_t i = 0; i < totalVectCapacity; i++){
        
        if(totalVect[i].name[0] != '\0' && 
            strcmp(totalVect[i].name, name) == 0){
            return &totalVect[i];
        }
        }
        return NULL;
 }
 // CLEARS THE ARRAY
 void clear(){
     free(totalVect);
     totalVect = NULL;
     totalVectCapacity = 0;
 }

 //LISTS EVERYTHING

 void list(){
    int count = 0;
    for(size_t i = 0; i < totalVectCapacity; i++){
        if(totalVect[i].name[0] != '\0'){
        printf("%s = %f, %f, %f\n", totalVect[i].name, totalVect[i].x, totalVect[i].y, totalVect[i].z);
        count++;
        }
    }
    printf("Total Vectors = %d\n", count);
}

int increaseArray(void){
    size_t oldCapacity = totalVectCapacity;

    //If the old capacity is 0, we set the new capacity to INITIAL_VECTOR_CAPACITY, 
    //otherwise we double the old capacity.
    size_t newCapacity = oldCapacity == 0 ? INITIAL_VECTOR_CAPACITY: oldCapacity * 2;
    vect *newArray = realloc(totalVect, newCapacity * sizeof(vect));
    if (newArray == NULL) {
        printf("ERROR RESIZING ARRAY\n");
        return 0;
    }
    totalVect = newArray;
    memset(totalVect + oldCapacity, 0,(newCapacity - oldCapacity) * sizeof(vect));
    totalVectCapacity = newCapacity;
    return 1;
}

//HELPPPPPPPP

void helpMe(){
    printf("Make new vectors using the a = x, y, z, format.\nAdd them or subtract them using c = a - b or a = a - b, and multiply them by a constant using a = a * 2.\nThen use save<filename> or load<filename> to save or load your vectors to a CSV file.\nUse list to see all the vectors you have created, and clear to clear them all.\nType quit to exit the program.\n");
}