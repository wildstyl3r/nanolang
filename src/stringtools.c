#include "nano.h"
#include <string.h>
#include <ctype.h>

string substr(string src, size_t pos, size_t len)
{
    string res;

    if (pos < strlen(src)){
        res = malloc(len+1);
        if (res == NULL){
            exit(EXIT_FAILURE);
        }
        for (size_t i = 0; i < len && src[i] !='\0'; ++i) {
            res[i] = src[pos+i];
        }
        res[len] = '\0';
    } else {
        res = malloc(1);
        if (res == NULL){
            exit(EXIT_FAILURE);
        }
        res[0] = '\0';
    }
    return res;
}

void ws_cleaner(string s)
{
    size_t i;
    for(i = 0; s[i] != '\0'; ++i){
        if(s[i] != ' ' && isspace(s[i])){
            s[i] = ' ';
        }
    }
}
