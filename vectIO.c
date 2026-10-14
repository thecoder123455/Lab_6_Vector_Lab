/*
* filename: vectIO.c
* author: Nick G
* date: 10/31/26
* Saves vectors to, and loads vectors from a CSV file
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vect.h"
#include "vectArray.h"
#include "vectIO.h"

void save(const char *fileName){

    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("ERROR OPENING FILE\n");
        return;
    }

    int count = 0;
    for (size_t i = 0; i < totalVectCapacity; i++) {
        if(totalVect[i].name[0] != '\0'){
            fprintf(fp, "%s,%f,%f,%f\n", totalVect[i].name,
                    totalVect[i].x, totalVect[i].y, totalVect[i].z);
            count++;
        }
    }
    fclose(fp);
}

void load(const char *fileName){
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("ERROR OPENING FILE\n");
        return;
    }

    char line[128];
    int verified = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        vect current = {0};

        if (sscanf(line, " %7[^,],%lf,%lf,%lf",
                   current.name, &current.x, &current.y, &current.z) == 4) {

            if(getVect(current.name) != NULL && verified == 0){
                printf("WARNING: VECTORS MAY BE OVERWRITTEN. PROCEED?\n");

                char response[16];
                if (fgets(response, sizeof(response), stdin) == NULL ||
                    (response[0] != 'y' && response[0] != 'Y')) {
                    fclose(fp);
                    return;
                }
                verified = 1;
            }

            addVect(current);

        } else if (line[strspn(line, " \t\r\n")] == '\0') {
            continue;

        } else {
            printf("INVALID VECTOR FORMAT IN FILE: %s", line);
        }
    }

    if (ferror(fp)) {
        printf("ERROR READING FILE\n");
        fclose(fp);
        return;
    }

    fclose(fp);
    list();
}

int handleIOCommand(const char *userInput){
    char command[8];
    char fileName[100];
    int fields = sscanf(userInput, "%7s %99[^\n]", command, fileName);

    if (fields < 1 || (strcmp(command, "save") != 0 &&
                       strcmp(command, "load") != 0)) {
        return 0;
    }

    if (fields != 2) {
        printf("Usage: %s <filename>\n", command);
        return 1;
    }

    if (strcmp(command, "save") == 0) {
        save(fileName);
    } else {
        load(fileName);
    }
    return 1;
}