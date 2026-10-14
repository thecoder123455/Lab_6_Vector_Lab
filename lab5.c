/*
* filename: lab5.c
* author: Nick G
* date 9/29/26
* Class that handles all the UI stuff
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vectIO.h"
#include "vect.h"
#include "vectParse.h"
#include "vectArray.h"
#include "vectorCalc.h"


int main(){
    char userInput[100];

    printf("Hello and welcome to the vector calculator!\nPlease enter a vector to get started then you can add vectors, subtract vectors, or multiply by a constant. Enjoy! :)\n");
    do{
        printf("New Vector: ");
        fgets(userInput, sizeof(userInput), stdin);
        

        if(strcmp(userInput, "list\n") == 0){
            list();
        } else if(strcmp(userInput, "clear\n") == 0){
            clear();
        } else if (strcmp(userInput, "help\n") == 0){
            helpMe();
        } else if(strcmp(userInput, "quit\n") != 0){
            if (!handleIOCommand(userInput)) {
                vectParse(userInput);
            }
        } 

    }while(strcmp(userInput, "quit\n") != 0);
    clear();
    return 0;
}