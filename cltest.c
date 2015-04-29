
// simple closure example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_lambda.h"

func(void, test1, (void) {
	int x = 6;
	closure_type(int, (int)) clos = cl(int,(int y),((int,x)),{ return _env->x + y; });
	
	printf("test1: %d\n", clos->_fun(clos, 5));
})

typedef closure_type(int, (int, int)) Closure;

func(Closure, test2, (void) {
	int p = 10, q = 5, r = 1;
	
	Closure c = cl(int, (int x, int y), ((int,p), (int,q), (int,r)), {
		return x * _env->p + y * _env->q + _env->r;
	});
	
	Closure ret = malloc(c->_size);
	memcpy(ret, c, c->_size);
	return ret;
})

func(int, main, (void) {
	test1();
	Closure c = test2();
	printf("test2: %d\n", c->_fun(c, 8, 9));
})
