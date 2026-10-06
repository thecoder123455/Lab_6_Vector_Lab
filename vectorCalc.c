/*
* filename: vectCalc.c
* author: Nick G
* date 9/29/26
* The thing that actually does the calculations
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "vect.h"
#include "vectParse.h"
#include "vectArray.h"
#include "vectorCalc.h"

vect vectCalc(vect v1, vect v2, char operation, double multiplier){
    vect returnVect;
    if(operation == '+'){
        returnVect.x = v1.x + v2.x;
        returnVect.y = v1.y + v2.y;
        returnVect.z = v1.z + v2.z;
    }else if(operation == '-'){
        returnVect.x = v1.x - v2.x;
        returnVect.y = v1.y - v2.y;
        returnVect.z = v1.z - v2.z;
    } else if(operation == '*'){
        returnVect.x = v1.x * multiplier;
        returnVect.y = v1.y * multiplier;
        returnVect.z = v1.z * multiplier;
    }
    return returnVect;
}