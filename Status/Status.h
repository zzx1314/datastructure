#ifndef STATUS_H
#define STATUS_H
#include <stdio.h>

/*状态码*/
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

#ifndef OVERFLOW
#define OVERFLOW -2
#endif

#ifndef NULL
#define NULL ((void*) 0)
#endif

typedef int Status;

typedef int Boolean;

extern Boolean debug;

int ReadData(FILE* fp, char* format, ...);

/**
 * 按下回车继续
 */
void PressEnterToContinue(Boolean debug);

/**
 * 函数暂停一段时间
 */
void Wait(long time);

void skipBlank(FILE* fp);

#endif
