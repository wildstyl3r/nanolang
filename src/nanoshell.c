#include "nano.h"
#include <string.h>

string normalize(string s)
{
    string braces = "{}()[]";
    int count = 0;
    char* br = strpbrk(s, braces);
    size_t ofs = 0;
    while (br != NULL){
	count++;
	ofs = br - s;
	br = strpbrk(s + ofs + 1, braces);
    }
    string res = malloc(strlen(s) + 1 + count*2);

    br = strpbrk(s, braces);
    ofs = 0;
    strncpy(res, s, br-s);
    
    while (br != NULL){
	
	count++;
	ofs = br - s;
	br = strpbrk(s + ofs + 1, braces);
    }
}
