#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#define LINE_LEN 1024

#define APPLY_ADDR 0

struct Func
{   /*head*/
    size_t argc;
    size_t size;
    /*text/code*/
    /*func_num  code;*/
};

typedef struct Func func_t;
typedef func_t* func_ptr;
typedef int16_t func_num;
typedef char* string;


func_ptr funx [10000];
func_num fi = 0;
func_num stack[10000];


#define FUNC_SIZE(size) sizeof(func_t) + size * sizeof(func_num)
#define FUNC_CODE(f) (func_num*)((char*)funx[f] + sizeof(func_t))

func_num new_func(size_t argc, size_t code_len);
void delete_func (func_num f);
string substr(string src, size_t pos, size_t len);

func_num curry (func_num f, size_t fixc, size_t stack_p);
void run(func_num f, size_t argc, size_t stack_p);
