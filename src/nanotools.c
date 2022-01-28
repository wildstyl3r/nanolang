#include "nano.h"

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
