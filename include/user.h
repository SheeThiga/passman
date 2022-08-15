/*******************************************************************
 * Project: Keeman
 * File   : user.h
 *
 * Description: Contains user data record definiton
 *
 * ****************************************************************/

#ifndef _USER_H
#define _USER_H

#include <stdlib.h>
#include <stdio_ext.h>  // for __fpurge(file)
#include <string.h>
#include <ctype.h>
#include <stdbool.h>    // bool true false

#include "encryption.h"

#define MAX_CHAR 60    // maximum width

struct User{
    char username[MAX_CHAR];
    char password[MAX_CHAR];
    char email[MAX_CHAR];
    char master_pass[MAX_CHAR];
};

typedef struct User User_t;


// function definitions


/*******************************************************************
 * function: register_user(&User, file)
 * return   : bool true if succeeded false if failed
 *
 * Registers a user and appends details
 *
 * ****************************************************************/

inline void register_user(User_t* user, FILE* userFile)
{
    char* username = (char*)calloc(MAX_CHAR, sizeof(char)),
        *password = (char*)calloc(MAX_CHAR, sizeof(char)),
        *email = (char*)calloc(MAX_CHAR, sizeof(char)),
        *master_pass = (char*)calloc(MAX_CHAR, sizeof(char));

    puts("Please enter your details on prompt:\n");


    while(true)
    {
        // username
        printf("Please enter your preferred username: ");
        fgets(username, MAX_CHAR, stdin);
        __fpurge(stdin);

        // password
        printf("Please enter your password: ");
        fgets(password, MAX_CHAR, stdin);
        printf("Please enter your password again for confirmation: ");
        fgets(user->password, MAX_CHAR, stdin);

        if(strcmp(password, user->password))
        {
            puts("Passwords don't match!");
            __fpurge(stdin);
            continue;
        }


        // email
        printf("Enter your email: ");
        fgets(email, MAX_CHAR, stdin);

        // master password
        printf("Enter your master password: ");
        fgets(master_pass, MAX_CHAR, stdin);
        printf("Enter your master password again for confirmation: ");
        fgets(user->master_pass, MAX_CHAR, stdin);

        if(strcmp(master_pass, user->master_pass))
        {
            puts("Passwords don't match!");
            __fpurge(stdin);
            continue;
        }

        // copy the data from buffers into the structs
        strcpy(user->username, username);
        strcpy(user->email, email);
        // The others were copied initially be default

        // confirm if the details are correct
        puts("\nIs the following data correct?\n");

        printf("Username: %10s\n"
                "Email: %10s\n"
                "\nYour choice: (y/N):",
                user->username, user->email);

        char ch = toupper(getchar());    // choice input buffer

        if(ch == 'Y')
        {
            encrypt(user->username);
            encrypt(user->email);
            encrypt(user->master_pass);
            encrypt(user->password);
            fwrite(user,sizeof(*user), 1, userFile);
            puts("Data saved successfully");
            break;
        }
        else
            continue;

    }

    free(username);
    free(password);
    free(email);
    free(master_pass);
}
#endif /*_USER_H*/
