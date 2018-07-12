#ifndef H22DE04EF_0DD2_4DAE_B0FA_021A08AE572D
#define H22DE04EF_0DD2_4DAE_B0FA_021A08AE572D

#define __DO_JOIN_AGAIN(s1, s2) s1##s2
#define __DO_JOIN(s1, s2) __DO_JOIN_AGAIN(s1, s2)

#define JOIN(s1, s2) __DO_JOIN(s1, s2)
#define UNIQUE_NAME(prefix) JOIN(prefix, __COUNTER__)

#endif
