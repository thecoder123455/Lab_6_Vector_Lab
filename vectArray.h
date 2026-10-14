/*
* filename: vectArray.h
* author: Nick G
* date 9/29/26
* Stores, adds, clears, and lists the vectors :)
 */
#ifndef VECT_ARRAY_H
#define VECT_ARRAY_H

#include <stddef.h>
#include "vect.h"

#define INITIAL_VECTOR_CAPACITY 10

extern vect *totalVect;
extern size_t totalVectCapacity;

void addVect(vect newVect);

vect *getVect(const char *name);

void clear();

void list();

void helpMe();

int increaseArray(void);

#endif