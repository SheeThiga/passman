/*******************************************************************************
 * File: main.c
 * Author: Erick Muuo
 * 
 * Description: Contains entry point to Keeman program
 * ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "include/user.h"

#define FILENAME "user.bin"


int main(int argc, char** argv)
{
    FILE* dataFile = fopen(FILENAME, "ab+");

    if(dataFile == NULL)
    {
        perror("Error");
        exit(2);    // could not open file
    }

    User_t user;

    register_user(&user, dataFile);

    fclose(dataFile);

    return EXIT_SUCCESS;
}
