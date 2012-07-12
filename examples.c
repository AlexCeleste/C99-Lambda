
#include <stdio.h>

#include "c_lambda.h"

/*
func(int, G, (void) {
	_fe1(foo, (int, (int x, int y), {return x*y;}));
	_fe2(foo, 1, (int, (int x, int y), {return x*y;}));
	_fe3(foo, 1, 2, (int, (int x, int y), {return x*y;}));
	_fe4(foo, 1, 2, 3, (int, (int x, int y), {return x*y;}));
	return 0;
})*/

namespace(myFunctionList,
  typedef int(* fptr)(void);
  fptr functions[] = {
    fn(int, (void), { return 1; }),  // Simple function literals
	fn(int, (void), { return 2; }),
	fn(int, (void), { return 3; })
  };
)

func(int, myGlobalFunc, (int blah) {
	//...code here, presumably involving inner functions
	return blah;
})

typedef int(* ifptr)(int);
func(ifptr, someFunc, (void) {
    return fn(int, (int a), {
        ifptr f = fn(int, (int b), { return b * 6; });
        return a * f(a + 1);
    });
})

func(int, someFunc1, (void) {
	int foo = fn(int, (int a, int b), { return (a + b) * (b - a); })(4, 5);
	fn(void, (int c), { printf("Received c: %d\n", c); })(47);
	return foo;
})

func(int, someFunc2, (void) {
	defn(int, helper, (int a, int b), {
		return (a + b) * (b - a);
	})
	int foo = helper(4, 5);
	return helper(foo, 2);
})

typedef struct { ifptr f; int add; } sth;

// User supplies a big enough buffer here... dirty trickery
func(void, makeAdder, (void * out_buf, int add) {
	*(sth *)out_buf = *(sth *)& cl(int, (int x), ((int, add)), {
                                 return x + _env->add;
							 });
	int x = 42, y = 47;
	(void)&cl(void, (...), ((int, x), (int, y)), {
		printf("%d, %d\n", _env->x, _env->y);
	});
})

/*func(void, eTest, (void) {
	 // Assume gforeach and gmap are higher-order functions...
	_fe2(gforeach, glist((char*[]){"foo", "bar", "baz"}), (void, (char * c), {
		printf("%s: %d\n", c, strlen(c));
	}));

	GList * out; int k = 2;
	_cle2(gmap, glist((int[]){ 1, 2, 3, 4 }), (int, (int n), ((int, k)), {
		return n * _env->k;
	}), &out);
	// "out" now contains { 2, 4, 6, 8 }
})*/

int main(void) {
	return 0;
}

