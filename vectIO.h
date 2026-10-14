/*
* filename: vectIO.h
* author: Nick G
* date 10/31/26
* Saves vectors to, and loads vectors from a CSV file
 */

#ifndef VECT_IO_H
#define VECT_IO_H

void save(const char *fileName);
void load(const char *fileName);
int handleIOCommand(const char *userInput);
#endif