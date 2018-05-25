#ifndef _DEBUG_PRINT_H
#define  _DEBUG_PRINT_H

#include <stdio.h>

#define DEBUG_PRINT_ON

#ifdef DEBUG_PRINT_ON
#define DEBUG_PRINT printf
#else
#define DEBUG_PRINT
#endif

#endif