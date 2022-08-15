#ifndef _ENCRYPTION_
#define _ENCRYPTION_

// Encryption uses the classic ROT13 algorithm

#include <string.h>
#include <ctype.h>

inline void encrypt(char* data){
    
    for(int i = 0; i < strlen(data); ++i)
    {
        if(isalpha(data[i]))
        {
            if(toupper(data[i]) >= 'A' && toupper(data[i]) <= 'M')
                data[i] += 13;
            else
                data[i] -= 13;
        }
    }
}

inline void decrypt(char* data){

    for(int i = 0; i < strlen(data); ++i)
    {
        if(isalpha(data[i]))
        {
            if(toupper(data[i]) >= 'A' && toupper(data[i]) <= 'M')
                data[i] += 13;
            else
                data[i] -= 13;
        }
    }
}

#endif /*_ENCRYPTION_*/