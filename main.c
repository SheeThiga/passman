/*******************************************************************************
 * File: main.c
 * Author: Erick Muuo
 * 
 * Description: Contains entry point to Keeman program
 * ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "user.bin"

int main(int argc, char** argv)
{
    FILE* dataFile = fopen(FILENAME, "ab+");

    if(dataFile == NULL)
    {
        perror("Error");
        exit(2);    // could not open file
    }

    fclose(dataFile);

    return EXIT_SUCCESS;
}
