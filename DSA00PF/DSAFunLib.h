
#ifndef DSAFUNLIB_H
#define DSAFUNLIB_H

typedef int (*cmpFun)(const void *a, const void *b, int flag);

void *getMax(const void *data, int s, int length, cmpFun cmpfun, int flag);

#endif
