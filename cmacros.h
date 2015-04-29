//
// Simple (i.e. very limited) metaprogramming macros
//      

#ifndef C_MACROS_H
#define C_MACROS_H 1


#define M_MAX_DEPTH 32

#define M_NARGS(...) M_NARGS_(__VA_ARGS__, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, \
20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define M_NARGS_(_32, _31, _30, _29, _28, _27, _26, _25, _24, _23, _22, _21, _20, _19, _18, _17, \
_16, _15, _14, _13, _12, _11, _10, _9, _8, _7, _6, _5, _4, _3, _2, _1, N, ...) N

#define M_2ORMORE(...) M_NARGS_(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0)

#define M_ILIST (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, \
17, 18, 19, 20, 21, 23, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32)

#define M_ID(...) __VA_ARGS__
#define M_FIRST(...) M_FIRST_(__VA_ARGS__)
#define M_REST(...) M_REST_(__VA_ARGS__)
#define M_FIRST_(A, ...) A
#define M_REST_(A, ...) __VA_ARGS__
#define M_FIRST2(A, B, ...) A, B
#define M_REST2(A, B, ...) __VA_ARGS__
#define M_ROT(A, ...) __VA_ARGS__, A
#define M_REVERSE(...) M_RECUR(M_REVERSE_, M_NARGS(__VA_ARGS__), (__VA_ARGS__))
#define M_REVERSE_(...) (M_REST(__VA_ARGS__)), M_FIRST(__VA_ARGS__)
#define M_CONC(A, B) M_CONC_(A, B)
#define M_CONC_(A, B) A##B
#define M_DIV2(N) M_CONC(M_DIV2_, N)
#define M_DECR(N) M_CONC(M_DECR_, N)
#define M_IF(P, T, E) M_CONC(M_IF_, P)(T, E)
#define M_IF_0(T, E) M_ID E
#define M_IF_1(T, E) M_ID T
#define M_ENLIST(X, N) M_DO_1(M_REST M_ENLIST_1(X, N))
#define M_ENLIST_1(X, N) (M_CONC(M_NEST_, N)(M_ENLIST_2, X))
#define M_ENLIST_2(...) M_FIRST(__VA_ARGS__), __VA_ARGS__

#define M_BEFORE_AFTER(BEF, AFT) for(int _b = (BEF, 1); _b; (AFT, _b = 0))

#define M_STATIC_ASSERT(EXP, NAME) {if(sizeof(struct{unsigned int NAME:((EXP)?1:-1);}));}

#define M_RECUR(ACT, N, ARG) M_CONC(M, _REST M_CONC(M_DO_, N)(M_CONC(M_REPT_, N)(ACT)ARG))

#define M_FOR_EACH(ACTN, ...) M_CONC(M_FOR_EACH_, M_NARGS(__VA_ARGS__)) (ACTN, __VA_ARGS__)
#define M_FOR_E2(ACTN, ...) M_REST(M_FOR_EACH(ACTN, __VA_ARGS__))

#define M_FOR_EACH_0(ACTN, E) E
#define M_FOR_EACH_1(ACTN, E) ACTN(E)
#define M_FOR_EACH_2(ACTN, E, ...) ACTN(E) M_FOR_EACH_1(ACTN, __VA_ARGS__)
#define M_FOR_EACH_3(ACTN, E, ...) ACTN(E) M_FOR_EACH_2(ACTN, __VA_ARGS__)
#define M_FOR_EACH_4(ACTN, E, ...) ACTN(E) M_FOR_EACH_3(ACTN, __VA_ARGS__)
#define M_FOR_EACH_5(ACTN, E, ...) ACTN(E) M_FOR_EACH_4(ACTN, __VA_ARGS__)
#define M_FOR_EACH_6(ACTN, E, ...) ACTN(E) M_FOR_EACH_5(ACTN, __VA_ARGS__)
#define M_FOR_EACH_7(ACTN, E, ...) ACTN(E) M_FOR_EACH_6(ACTN, __VA_ARGS__)
#define M_FOR_EACH_8(ACTN, E, ...) ACTN(E) M_FOR_EACH_7(ACTN, __VA_ARGS__)
#define M_FOR_EACH_9(ACTN, E, ...) ACTN(E) M_FOR_EACH_8(ACTN, __VA_ARGS__)
#define M_FOR_EACH_10(ACTN, E, ...) ACTN(E) M_FOR_EACH_9(ACTN, __VA_ARGS__)
#define M_FOR_EACH_11(ACTN, E, ...) ACTN(E) M_FOR_EACH_10(ACTN, __VA_ARGS__)
#define M_FOR_EACH_12(ACTN, E, ...) ACTN(E) M_FOR_EACH_11(ACTN, __VA_ARGS__)
#define M_FOR_EACH_13(ACTN, E, ...) ACTN(E) M_FOR_EACH_12(ACTN, __VA_ARGS__)
#define M_FOR_EACH_14(ACTN, E, ...) ACTN(E) M_FOR_EACH_13(ACTN, __VA_ARGS__)
#define M_FOR_EACH_15(ACTN, E, ...) ACTN(E) M_FOR_EACH_14(ACTN, __VA_ARGS__)
#define M_FOR_EACH_16(ACTN, E, ...) ACTN(E) M_FOR_EACH_15(ACTN, __VA_ARGS__)
#define M_FOR_EACH_17(ACTN, E, ...) ACTN(E) M_FOR_EACH_16(ACTN, __VA_ARGS__)
#define M_FOR_EACH_18(ACTN, E, ...) ACTN(E) M_FOR_EACH_17(ACTN, __VA_ARGS__)
#define M_FOR_EACH_19(ACTN, E, ...) ACTN(E) M_FOR_EACH_18(ACTN, __VA_ARGS__)
#define M_FOR_EACH_20(ACTN, E, ...) ACTN(E) M_FOR_EACH_19(ACTN, __VA_ARGS__)
#define M_FOR_EACH_21(ACTN, E, ...) ACTN(E) M_FOR_EACH_20(ACTN, __VA_ARGS__)
#define M_FOR_EACH_22(ACTN, E, ...) ACTN(E) M_FOR_EACH_21(ACTN, __VA_ARGS__)
#define M_FOR_EACH_23(ACTN, E, ...) ACTN(E) M_FOR_EACH_22(ACTN, __VA_ARGS__)
#define M_FOR_EACH_24(ACTN, E, ...) ACTN(E) M_FOR_EACH_23(ACTN, __VA_ARGS__)
#define M_FOR_EACH_25(ACTN, E, ...) ACTN(E) M_FOR_EACH_24(ACTN, __VA_ARGS__)
#define M_FOR_EACH_26(ACTN, E, ...) ACTN(E) M_FOR_EACH_25(ACTN, __VA_ARGS__)
#define M_FOR_EACH_27(ACTN, E, ...) ACTN(E) M_FOR_EACH_26(ACTN, __VA_ARGS__)
#define M_FOR_EACH_28(ACTN, E, ...) ACTN(E) M_FOR_EACH_27(ACTN, __VA_ARGS__)
#define M_FOR_EACH_29(ACTN, E, ...) ACTN(E) M_FOR_EACH_28(ACTN, __VA_ARGS__)
#define M_FOR_EACH_30(ACTN, E, ...) ACTN(E) M_FOR_EACH_29(ACTN, __VA_ARGS__)
#define M_FOR_EACH_31(ACTN, E, ...) ACTN(E) M_FOR_EACH_30(ACTN, __VA_ARGS__)
#define M_FOR_EACH_32(ACTN, E, ...) ACTN(E) M_FOR_EACH_31(ACTN, __VA_ARGS__)

#define M_ZIP_WITH(ACTN, L1, L2) M_CONC(M_ZIP_WITH_, M_NARGS L1)(ACTN, L1, L2)
#define M_ZIP_W2(ACTN, L1, L2) M_REST(M_ZIP_WITH(ACTN, L1, L2))

#define M_ZIP_WITH_0(ACTN, L1, L2)
#define M_ZIP_WITH_1(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2)
#define M_ZIP_WITH_2(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_1(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_3(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_2(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_4(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_3(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_5(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_4(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_6(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_5(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_7(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_6(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_8(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_7(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_9(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_8(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_10(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_9(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_11(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_10(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_12(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_11(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_13(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_12(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_14(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_13(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_15(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_14(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_16(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_15(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_17(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_16(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_18(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_17(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_19(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_18(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_20(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_19(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_21(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_20(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_22(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_21(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_23(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_22(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_24(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_23(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_25(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_24(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_26(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_25(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_27(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_26(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_28(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_27(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_29(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_28(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_30(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_29(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_31(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_30(ACTN, (M_REST L1), (M_REST L2))
#define M_ZIP_WITH_32(ACTN, L1, L2) ACTN(M_FIRST L1, M_FIRST L2) M_ZIP_WITH_31(ACTN, (M_REST L1), (M_REST L2))

#define M_REPT_0(A, ...)
#define M_REPT_1(A, ...) A __VA_ARGS__
#define M_REPT_2(A, ...) M_REPT_1(A, A __VA_ARGS__)
#define M_REPT_3(A, ...) M_REPT_2(A, A __VA_ARGS__)
#define M_REPT_4(A, ...) M_REPT_3(A, A __VA_ARGS__)
#define M_REPT_5(A, ...) M_REPT_4(A, A __VA_ARGS__)
#define M_REPT_6(A, ...) M_REPT_5(A, A __VA_ARGS__)
#define M_REPT_7(A, ...) M_REPT_6(A, A __VA_ARGS__)
#define M_REPT_8(A, ...) M_REPT_7(A, A __VA_ARGS__)
#define M_REPT_9(A, ...) M_REPT_8(A, A __VA_ARGS__)
#define M_REPT_10(A, ...) M_REPT_9(A, A __VA_ARGS__)
#define M_REPT_11(A, ...) M_REPT_10(A, A __VA_ARGS__)
#define M_REPT_12(A, ...) M_REPT_11(A, A __VA_ARGS__)
#define M_REPT_13(A, ...) M_REPT_12(A, A __VA_ARGS__)
#define M_REPT_14(A, ...) M_REPT_13(A, A __VA_ARGS__)
#define M_REPT_15(A, ...) M_REPT_14(A, A __VA_ARGS__)
#define M_REPT_16(A, ...) M_REPT_15(A, A __VA_ARGS__)
#define M_REPT_17(A, ...) M_REPT_16(A, A __VA_ARGS__)
#define M_REPT_18(A, ...) M_REPT_17(A, A __VA_ARGS__)
#define M_REPT_19(A, ...) M_REPT_18(A, A __VA_ARGS__)
#define M_REPT_20(A, ...) M_REPT_19(A, A __VA_ARGS__)
#define M_REPT_21(A, ...) M_REPT_20(A, A __VA_ARGS__)
#define M_REPT_22(A, ...) M_REPT_21(A, A __VA_ARGS__)
#define M_REPT_23(A, ...) M_REPT_22(A, A __VA_ARGS__)
#define M_REPT_24(A, ...) M_REPT_23(A, A __VA_ARGS__)
#define M_REPT_25(A, ...) M_REPT_24(A, A __VA_ARGS__)
#define M_REPT_26(A, ...) M_REPT_25(A, A __VA_ARGS__)
#define M_REPT_27(A, ...) M_REPT_26(A, A __VA_ARGS__)
#define M_REPT_28(A, ...) M_REPT_27(A, A __VA_ARGS__)
#define M_REPT_29(A, ...) M_REPT_28(A, A __VA_ARGS__)
#define M_REPT_30(A, ...) M_REPT_29(A, A __VA_ARGS__)
#define M_REPT_31(A, ...) M_REPT_30(A, A __VA_ARGS__)
#define M_REPT_32(A, ...) M_REPT_31(A, A __VA_ARGS__)

#define M_NEST_0(A, ...)
#define M_NEST_1(A, ...) A(__VA_ARGS__)
#define M_NEST_2(A, ...) M_NEST_1(A, A(__VA_ARGS__))
#define M_NEST_3(A, ...) M_NEST_2(A, A(__VA_ARGS__))
#define M_NEST_4(A, ...) M_NEST_3(A, A(__VA_ARGS__))
#define M_NEST_5(A, ...) M_NEST_4(A, A(__VA_ARGS__))
#define M_NEST_6(A, ...) M_NEST_5(A, A(__VA_ARGS__))
#define M_NEST_7(A, ...) M_NEST_6(A, A(__VA_ARGS__))
#define M_NEST_8(A, ...) M_NEST_7(A, A(__VA_ARGS__))
#define M_NEST_9(A, ...) M_NEST_8(A, A(__VA_ARGS__))
#define M_NEST_10(A, ...) M_NEST_9(A, A(__VA_ARGS__))
#define M_NEST_11(A, ...) M_NEST_10(A, A(__VA_ARGS__))
#define M_NEST_12(A, ...) M_NEST_11(A, A(__VA_ARGS__))
#define M_NEST_13(A, ...) M_NEST_12(A, A(__VA_ARGS__))
#define M_NEST_14(A, ...) M_NEST_13(A, A(__VA_ARGS__))
#define M_NEST_15(A, ...) M_NEST_14(A, A(__VA_ARGS__))
#define M_NEST_16(A, ...) M_NEST_15(A, A(__VA_ARGS__))
#define M_NEST_17(A, ...) M_NEST_16(A, A(__VA_ARGS__))
#define M_NEST_18(A, ...) M_NEST_17(A, A(__VA_ARGS__))
#define M_NEST_19(A, ...) M_NEST_18(A, A(__VA_ARGS__))
#define M_NEST_20(A, ...) M_NEST_19(A, A(__VA_ARGS__))
#define M_NEST_21(A, ...) M_NEST_20(A, A(__VA_ARGS__))
#define M_NEST_22(A, ...) M_NEST_21(A, A(__VA_ARGS__))
#define M_NEST_23(A, ...) M_NEST_22(A, A(__VA_ARGS__))
#define M_NEST_24(A, ...) M_NEST_23(A, A(__VA_ARGS__))
#define M_NEST_25(A, ...) M_NEST_24(A, A(__VA_ARGS__))
#define M_NEST_26(A, ...) M_NEST_25(A, A(__VA_ARGS__))
#define M_NEST_27(A, ...) M_NEST_26(A, A(__VA_ARGS__))
#define M_NEST_28(A, ...) M_NEST_27(A, A(__VA_ARGS__))
#define M_NEST_29(A, ...) M_NEST_28(A, A(__VA_ARGS__))
#define M_NEST_30(A, ...) M_NEST_29(A, A(__VA_ARGS__))
#define M_NEST_31(A, ...) M_NEST_30(A, A(__VA_ARGS__))
#define M_NEST_32(A, ...) M_NEST_31(A, A(__VA_ARGS__))

#define M_DO_0(...)
#define M_DO_1(...) (__VA_ARGS__)
#define M_DO_2(...) M_DO_1(__VA_ARGS__)
#define M_DO_3(...) M_DO_2(__VA_ARGS__)
#define M_DO_4(...) M_DO_3(__VA_ARGS__)
#define M_DO_5(...) M_DO_4(__VA_ARGS__)
#define M_DO_6(...) M_DO_5(__VA_ARGS__)
#define M_DO_7(...) M_DO_6(__VA_ARGS__)
#define M_DO_8(...) M_DO_7(__VA_ARGS__)
#define M_DO_9(...) M_DO_8(__VA_ARGS__)
#define M_DO_10(...) M_DO_9(__VA_ARGS__)
#define M_DO_11(...) M_DO_10(__VA_ARGS__)
#define M_DO_12(...) M_DO_11(__VA_ARGS__)
#define M_DO_13(...) M_DO_12(__VA_ARGS__)
#define M_DO_14(...) M_DO_13(__VA_ARGS__)
#define M_DO_15(...) M_DO_14(__VA_ARGS__)
#define M_DO_16(...) M_DO_15(__VA_ARGS__)
#define M_DO_17(...) M_DO_16(__VA_ARGS__)
#define M_DO_18(...) M_DO_17(__VA_ARGS__)
#define M_DO_19(...) M_DO_18(__VA_ARGS__)
#define M_DO_20(...) M_DO_19(__VA_ARGS__)
#define M_DO_21(...) M_DO_20(__VA_ARGS__)
#define M_DO_22(...) M_DO_21(__VA_ARGS__)
#define M_DO_23(...) M_DO_22(__VA_ARGS__)
#define M_DO_24(...) M_DO_23(__VA_ARGS__)
#define M_DO_25(...) M_DO_24(__VA_ARGS__)
#define M_DO_26(...) M_DO_25(__VA_ARGS__)
#define M_DO_27(...) M_DO_26(__VA_ARGS__)
#define M_DO_28(...) M_DO_27(__VA_ARGS__)
#define M_DO_29(...) M_DO_28(__VA_ARGS__)
#define M_DO_30(...) M_DO_29(__VA_ARGS__)
#define M_DO_31(...) M_DO_30(__VA_ARGS__)
#define M_DO_32(...) M_DO_31(__VA_ARGS__)

#define M_DIV2_2 1
#define M_DIV2_4 2
#define M_DIV2_6 3
#define M_DIV2_8 4
#define M_DIV2_10 5
#define M_DIV2_12 6
#define M_DIV2_14 7
#define M_DIV2_16 8
#define M_DIV2_18 9
#define M_DIV2_20 10
#define M_DIV2_22 11
#define M_DIV2_24 12
#define M_DIV2_26 13
#define M_DIV2_28 14
#define M_DIV2_30 15
#define M_DIV2_32 16


#endif

