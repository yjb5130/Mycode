#ifndef __GOOGLE_H__
#define __GOOGLE_H__

#include <stdbool.h>

#define MAX_CHAR_COUNT 9
#define MAX_VALUE_COUNT 10

typedef struct
{
    char c;
    int value;
    bool leading;
} CharItem;

typedef struct
{
    bool used;
    int value;
} CharValue;

void SearchingResult(CharItem ci[MAX_CHAR_COUNT], CharValue cv[MAX_VALUE_COUNT], int index);
void OnCharListReady(CharItem ci[MAX_CHAR_COUNT]);
int MakeIntegerValue(CharItem ci[MAX_CHAR_COUNT], char *str);

#endif