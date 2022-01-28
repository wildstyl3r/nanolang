#include <memory.h>
#include "nano.h"

int main()
{
    char input[LINE_LEN];
    fgets(input, LINE_LEN, stdin);
    
    while(strcmp(input, "~~~") != 0){
	fputs("::: ", stdout);
	normalize(input);
	func_ptr f = create_func(input);
	if (f->argc == 0) {
	    run(f, 0, 0);
	}
	fputs(get_symbol(stack[0]), stdout);

	fgets(input, LINE_LEN, stdin);
    }
    return 0;
}
