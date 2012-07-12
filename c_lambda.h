//
// Write nested, anonymous, and closure functions in ISO C99
//


// Public syntax-extension macros

#define func(rt, n, ...) FN_8CM_GO((8EMIT_NS, (n, (rt n), ( 8blk( __VA_ARGS__ ) ), ((8CM_END,(~))))))
#define namespace(n, ...) FN_8CM_GO((8EMIT_NS, (n, (), ( 8blk( __VA_ARGS__ ) ), ((8CM_END,(~))))))

#define fn(rt, args, ...) ), 8fn(rt, args, (8blk(__VA_ARGS__))), 8blk(
#define cl(rt, args, over, ...) ), 8cl(rt, args, over, (8blk(__VA_ARGS__))), 8blk(
#define defn(rt, n, a, ...) static FN_8FTYPE(rt, const, a, n) = fn(rt, a, __VA_ARGS__);

#define sizeof_cl(rt, args, over) sizeof(struct{void(*f)(void); M_ZIP_WITH(FN_8CLSZ, (M_ID args, M_ID over), M_ILIST) })

#define _fe1(_0, ...) FN_8FEXP(_0, (), M_FIRST(__VA_ARGS__), (__VA_ARGS__))
#define _fe2(_0, _1, ...) FN_8FEXP(_0, (_1,), M_FIRST(__VA_ARGS__), (__VA_ARGS__))
#define _fe3(_0, _1, _2, ...) FN_8FEXP(_0, (_1, _2,), M_FIRST(__VA_ARGS__), (__VA_ARGS__))
#define _fe4(_0, _1, _2, _3, ...) FN_8FEXP(_0, (_1, _2, _3,), M_FIRST(__VA_ARGS__), (__VA_ARGS__))

#define _cle1(_0, ...) FN_8CLEXP(_0, (), M_FIRST(__VA_ARGS__), (__VA_ARGS__))
#define _cle2(_0, _1, ...) FN_8CLEXP(_0, (_1,), M_FIRST(__VA_ARGS__), (__VA_ARGS__))
#define _cle3(_0, _1, _2, ...) FN_8CLEXP(_0, (_1, _2,), M_FIRST(__VA_ARGS__), (__VA_ARGS__))
#define _cle4(_0, _1, _2, _3, ...) FN_8CLEXP(_0, (_1, _2, _3,), M_FIRST(__VA_ARGS__), (__VA_ARGS__))


// Continuation machine

#define FN_8CM_GO(x) FN_8CM_RET(FN_8CM_UP_0 x)

#define FN_8CM_RET(x) FN_8CM_RET_(x)
#define FN_8CM_RET_(_, ...) __VA_ARGS__

#define FN_8CM_END(...) ,

#define FN_8CM_D_0(x) FN_8CM_DN_0 x
#define FN_8CM_U_0(x) FN_8CM_UP_1 x
#define FN_8CM_D_1(x) FN_8CM_DN_1 x
#define FN_8CM_U_1(x) FN_8CM_UP_2 x
#define FN_8CM_D_2(x) FN_8CM_DN_2 x
#define FN_8CM_U_2(x) FN_8CM_UP_3 x
#define FN_8CM_D_3(x) FN_8CM_DN_3 x
#define FN_8CM_U_3(x) FN_8CM_UP_4 x
#define FN_8CM_D_4(x) FN_8CM_DN_4 x
#define FN_8CM_U_4(x) FN_8CM_UP_5 x
#define FN_8CM_D_5(x) FN_8CM_DN_5 x
#define FN_8CM_U_5(x) FN_8CM_UP_6 x
#define FN_8CM_D_6(x) FN_8CM_DN_6 x
#define FN_8CM_U_6(x) FN_8CM_UP_7 x
#define FN_8CM_D_7(x) FN_8CM_DN_7 x
#define FN_8CM_U_7(x) FN_8CM_UP_8 x
#define FN_8CM_D_8(x) FN_8CM_DN_8 x
#define FN_8CM_U_8(x) FN_8CM_UP_9 x
#define FN_8CM_D_9(x) FN_8CM_DN_9 x
#define FN_8CM_U_9(x) FN_8CM_UP_10 x
#define FN_8CM_D_10(x) FN_8CM_DN_10 x
#define FN_8CM_U_10(x) FN_8CM_UP_11 x
#define FN_8CM_D_11(x) FN_8CM_DN_11 x
#define FN_8CM_U_11(x) FN_8CM_UP_12 x
#define FN_8CM_D_12(x) FN_8CM_DN_12 x
#define FN_8CM_U_12(x) FN_8CM_UP_13 x
#define FN_8CM_D_13(x) FN_8CM_DN_13 x
#define FN_8CM_U_13(x) FN_8CM_UP_14 x
#define FN_8CM_D_14(x) FN_8CM_DN_14 x
#define FN_8CM_U_14(x) FN_8CM_UP_15 x
#define FN_8CM_D_15(x) FN_8CM_DN_15 x
#define FN_8CM_U_15(x) FN_8CM_UP_16 x
#define FN_8CM_D_16(x) FN_8CM_DN_16 x
#define FN_8CM_U_16(x) FN_8CM_ERROR_OUT_OF_STEPS(0)

#define FN_8CM_DN_0(f, x, ...) FN_##f x __VA_ARGS__
#define FN_8CM_UP_0(f, x, ...) FN_8CM_U_0(FN_8CM_D_0(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_1(f, x, ...) FN_8CM_D_0(FN_8CM_D_0(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_1(f, x, ...) FN_8CM_U_1(FN_8CM_D_1(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_2(f, x, ...) FN_8CM_D_1(FN_8CM_D_1(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_2(f, x, ...) FN_8CM_U_2(FN_8CM_D_2(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_3(f, x, ...) FN_8CM_D_2(FN_8CM_D_2(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_3(f, x, ...) FN_8CM_U_3(FN_8CM_D_3(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_4(f, x, ...) FN_8CM_D_3(FN_8CM_D_3(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_4(f, x, ...) FN_8CM_U_4(FN_8CM_D_4(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_5(f, x, ...) FN_8CM_D_4(FN_8CM_D_4(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_5(f, x, ...) FN_8CM_U_5(FN_8CM_D_5(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_6(f, x, ...) FN_8CM_D_5(FN_8CM_D_5(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_6(f, x, ...) FN_8CM_U_6(FN_8CM_D_6(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_7(f, x, ...) FN_8CM_D_2(FN_8CM_D_6(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_7(f, x, ...) FN_8CM_U_3(FN_8CM_D_7(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_8(f, x, ...) FN_8CM_D_3(FN_8CM_D_7(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_8(f, x, ...) FN_8CM_U_4(FN_8CM_D_8(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_9(f, x, ...) FN_8CM_D_4(FN_8CM_D_8(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_9(f, x, ...) FN_8CM_U_5(FN_8CM_D_9(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_10(f, x, ...) FN_8CM_D_5(FN_8CM_D_9(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_10(f, x, ...) FN_8CM_U_6(FN_8CM_D_10(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_11(f, x, ...) FN_8CM_D_4(FN_8CM_D_10(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_11(f, x, ...) FN_8CM_U_5(FN_8CM_D_11(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_12(f, x, ...) FN_8CM_D_5(FN_8CM_D_11(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_12(f, x, ...) FN_8CM_U_6(FN_8CM_D_12(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_13(f, x, ...) FN_8CM_D_2(FN_8CM_D_12(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_13(f, x, ...) FN_8CM_U_3(FN_8CM_D_13(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_14(f, x, ...) FN_8CM_D_3(FN_8CM_D_13(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_14(f, x, ...) FN_8CM_U_4(FN_8CM_D_14(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_15(f, x, ...) FN_8CM_D_4(FN_8CM_D_14(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_15(f, x, ...) FN_8CM_U_5(FN_8CM_D_15(FN_##f x)) __VA_ARGS__
#define FN_8CM_DN_16(f, x, ...) FN_8CM_D_5(FN_8CM_D_15(FN_##f x)) __VA_ARGS__
#define FN_8CM_UP_16(f, x, ...) FN_8CM_U_6(FN_8CM_D_16(FN_##f x)) __VA_ARGS__

#define FN_8CM_ERROR_OUT_OF_STEPS(A, B)


// Internal lambda builder functions

#define FN_8FEXP(call, p, f, R) { FN_8GETTYPE_8fn f = fn f; call(M_ID p M_IF(M_2ORMORE R, (_fun, M_REST_ R), (_fun))); }
#define FN_8CLEXP(call, p, c, R) { void * _fun = &cl c; call(M_ID p M_IF(M_2ORMORE R, (_fun, M_REST_ R), (_fun))); }

#define FN_8EMIT_NS(N, H, B, Q) FN_8EMIT_NS_((FN_8GET_NL(N, B)), H, (M_ZIP_W2(FN_8EMIT_ELEM, B, M_ILIST)), Q)
#define FN_8EMIT_NS_(NL, H, BL, Q) (8ZIPNE,(NL, BL, Q), FN_8EMIT_BODY(NL, H, BL))

#define FN_8GET_NL(N, B) M_ZIP_W2(FN_8GET_NL_1, M_ENLIST(_8anon_##N##_, M_NARGS B), M_ILIST)
#define FN_8GET_NL_1(A, B) , M_CONC_(A, B)
#define FN_8EMIT_BODY(NL, H, BL) M_ID H M_ZIP_WITH(FN_8EMIT_BLOCK, BL, NL)

#define FN_8EMIT_ELEM(E, _) ,M_CONC_(FN_8EMIT_, E)
#define FN_8EMIT_8blk(...) (1, 0, __VA_ARGS__)
#define FN_8EMIT_8fn(...) (0, 0, __VA_ARGS__)
#define FN_8EMIT_8cl(...) (0, 1, __VA_ARGS__)
#define FN_8EMIT_BLOCK(P, N) M_IF(M_FIRST P, (M_REST2 P), (FN_8EMIT_NAME((M_REST P, r, a, o), N)))
#define FN_8EMIT_NAME(P, N) M_IF(M_FIRST P, (FN_8EMIT_CL(N, M_ID P)), (N))
#define FN_8EMIT_CL(...) FN_8EMIT_CL_(__VA_ARGS__)
#define FN_8EMIT_CL_(n, _, r, a, o, ...) (struct n##_env_t){ n M_FOR_EACH(FN_8CL_SND, M_ID o) }
#define FN_8CL_SND(P) , M_REST_ P

#define FN_8EMIT_ENV(E, Q) (8DO_Q, (Q), FN_8EMIT_ENV_(E))
#define FN_8EMIT_ENV_(n, rt, a, o) struct n##_env_t { FN_8CTYPE(rt, n, a, _fun); M_FOR_EACH(FN_8FLDS, M_ID o) };
#define FN_8FLDS(F) M_FIRST_ F M_REST_ F;
#define FN_8CL_DEC(rt, n, a) static rt n(struct n##_env_t * _env, M_ID a)

#define FN_8FTYPE(rt, C, a, pn) rt(* C pn)a
#define FN_8CTYPE(rt, n, a, pn) rt(* pn)(struct n##_env_t *, M_ID a)
#define FN_8FN_TYPE(F) M_CONC(FN_8GETTYPE_, M_FIRST(M_REST((F))))
#define FN_8GETTYPE_8fn(rt, a, ...) rt(* _fun)a
#define FN_8CLSZ(T, N) T M_CONC(_, N);

#define FN_8ZIPNE(NL, BL, Q) (8FLTNE, ((M_ZIP_W2(FN_8ZIPNE_, NL, BL)), Q))
#define FN_8ZIPNE_(N, B) ,(M_FIRST_ B, N, M_REST_ B)

#define FN_8FLTNE(EL, Q) (8POPEM, ((0 M_FOR_EACH(FN_8FLTNE_, M_ID EL)), Q))
#define FN_8FLTNE_(E) M_IF(M_FIRST_ E, (), (,(M_REST_ E)))

#define FN_8POPEM(FL, Q) M_IF(M_2ORMORE(M_ID FL), ((8F2NS, ((M_REST_ FL), Q))), ((8DO_Q, (Q))))

#define FN_8F2NS(FL, Q) (8DO_Q, ((M_FOR_E2(FN_8F2NS_1, M_ID FL), M_ID Q)))
#define FN_8F2NS_1(F) ,FN_8F2NS_2 F
#define FN_8F2NS_2(n, isC, rt, a, ...) M_IF(isC, \
((8EMIT_NS_NX, (n, (FN_8CL_DEC(rt, n, a)), M_REST(__VA_ARGS__))), (8EMIT_ENV,(n, rt, a, M_FIRST(__VA_ARGS__)))), \
((8EMIT_NS_NX, (n, (static rt n a), __VA_ARGS__))))

#define FN_8DO_Q(Q) (M_ID(M_FIRST_ M_FIRST_ Q),(M_ID M_REST_ M_FIRST_ Q, (M_REST_ Q)))

#define FN_8EMIT_NS_NX(...) (8EMIT_NS, (__VA_ARGS__))


// Some generic simple metaprogramming macros used by the above

#include "cmacros.h"

