#include "nano.h"
#include <string.h>

func_num new_func(size_t argc, size_t code_len)
{
    func_ptr fp = (func_ptr) malloc(FUNC_SIZE(code_len));
    fp->argc = argc;
    fp->size = code_len;
    funx[fi] = fp;
    fi++;
    return fi;
}

void delete_func (func_num f)
{
    if (f >= 0) {
	free(funx[f]);
    }
}

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
