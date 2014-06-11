
#include "zip.h"    // PP_ZIP

// Given 2 lists:
PP_ZIP( (a), (n) )
PP_ZIP( (a), (n,o) )
PP_ZIP( (a,b), (n,o) )
PP_ZIP( (a,b), (n,o,p,q) )
PP_ZIP( (a,b,c), (n,o,p) )
PP_ZIP( ((a,b),(c,d)), (n,(o,p)) )

// Given 3 lists:
PP_ZIP( (a), (j), (r) )
PP_ZIP( (a), (j,k), (r) )
PP_ZIP( (a), (j,k), (r,s) )
PP_ZIP( (a,b), (j,k), (r,s) )
PP_ZIP( (a,b), (j,k,l), (r,s) )
PP_ZIP( (a,b), (j,k), (r,s,t) )
PP_ZIP( (a,b,c), (j,k,l), (r,s,t) )
PP_ZIP( (a,b,c), (j,k,l), (r,s,t,u) )
PP_ZIP( (a,b,c), (j,k,l,m), (r,s,t) )
PP_ZIP( (a,b,c), (j,k,l,m), (r,s,t, u ) )

// Given 4 lists:
PP_ZIP( (a), (f), (m), (v) )
PP_ZIP( (a), (f,g), (m,n,o), (v) )
PP_ZIP( (a,b), (f,g), (m,n), (v,w) )
PP_ZIP( (a,b), (f,g), (m,n,o,p), (v,w) )
PP_ZIP( (a,b,c), (f,g,h), (m,n,o), (v,w,x) )
PP_ZIP( (a,b,c), (f,g,h), (m,n,o,p), (v,w,x) )

// Given 5 lists:
PP_ZIP( (a), (e), (j), (q), (v) )
PP_ZIP( (a), (e,f), (j,k,l), (q,r), (v) )
PP_ZIP( (a,b), (e,f), (j,k), (q,r), (v,w) )
PP_ZIP( (a,b), (e,f,g), (j,k), (q,r,s,t), (v,w) )
PP_ZIP( (a,b,c), (e,f,g), (j,k,l), (q,r,s), (v,w,x) )
PP_ZIP( (a,b,c), (e,f,g,h), (j,k,l,m,n), (q,r,s), (v,w,x,y) )

// Given 6, 7 and 8 lists:
PP_ZIP( (10,11), (20,21), (30,31), (40,41), (50,51), (60,61) )
PP_ZIP( (10,11), (20,21), (30,31), (40,41), (50,51), (60,61), (70,71) )
PP_ZIP( (10,11), (20,21), (30,31), (40,41), (50,51), (60,61), (70,71), (80,81) )

