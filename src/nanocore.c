#include "nano.h"

func_num curry (func_num f, size_t fixc, size_t stack_p)
{
    func_num res = new_func(funx[f]->argc - fixc, funx[f]->size);
    
    func_num* code_src = FUNC_CODE(f);
    func_num* code_dst = FUNC_CODE(res);
    
    for (size_t i = 0; i < funx[f]->size; ++i){
	if ((intptr_t)code_src[i] < -fixc) {
	    code_dst[i] = code_src[i] + fixc;
	} else {
	    code_dst[i] = stack[stack_p + (intptr_t)code_src[i]];
	}
    }
    return res;
}

void run(func_num f, size_t argc, size_t stack_p)
{
    func_num* code = FUNC_CODE(f);
    size_t stack_current = stack_p;
    
    for(size_t i = 0; i < funx[f]->size; ++i){
	if (code[i] != APPLY_ADDR) {
	    if (stack_current == SIZE_MAX) {
		fputs("Stack overflow", stdout);
		abort();
	    }
	    if(code[i] > 0){
		stack[stack_current] = code[i];
	    } else {
		stack[stack_current] = stack[stack_p + code[i]];
	    }
	    stack_current++;
	} else {
	    stack_current--; //target is the last element on the stack
	    size_t argc_new = stack_current - stack_p;
	    if (argc_new < funx[stack[stack_current]]->argc) {
		stack[stack_p] = curry(stack[stack_current], argc_new, stack_current);
		stack_current = stack_p + 1;
	    } else {
		run(stack[stack_current], argc_new, stack_current);
		stack_current = stack_current - funx[stack[stack_current]]->argc + 1;
	    }
	}
    }
}
