#ifndef LIBCOMPAT_H
#define LIBCOMPAT_H
#include <Types.h>
#include <Files.h>
#include <OSUtils.h>

#include <size_t.h>

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "snprintf.h"

/*
 * We use C99 types to help out portability,
 * but our compiler doesn't define them, at 
 * least not with the same names.
 */
typedef unsigned long long uint64_t;
typedef UInt32 uint32_t;
typedef UInt16 uint16_t;
typedef UInt8   uint8_t;

typedef signed long long int64_t;
typedef SInt32 int32_t;
typedef SInt16 int16_t;
typedef SInt8   int8_t;

/*
 * We need time() to show UNIX time, so we
 * implement our own
 */
time_t __time(time_t *);

/*
 * CWPro1 needs this
 */
char *strdup(const char *);
int strcasecmp(const char *, const char *);

#endif
