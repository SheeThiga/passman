/*******************************************************************
 * Project: Keeman
 * File   : user.h
 *
 * Description: Contains user data record definiton
 *
 * ****************************************************************/

#ifndef _USER_H
#define _USER_H


#define MAX_CHAR 128    // maximum width

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
 * return   : bool true if suceeded false if failed
 *
 * Registers a user and appends details
 *
 * ****************************************************************/

bool register_user(User_t* user, FILE* userFile)
{
}
#endif /*_USER_H*/
