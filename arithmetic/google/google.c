#include <stdio.h>
#include <stdbool.h>
#include "google.h"

bool isValueValid(CharItem ci, CharValue cv)
{
    if (cv.used == true)
    {
        return false;
    }
    return true;
}

void SearchingResult(CharItem ci[MAX_CHAR_COUNT],
                CharValue cv[MAX_VALUE_COUNT],
                int index)
{
    int i = 0;
    if (index == MAX_CHAR_COUNT)
    {
        OnCharListReady(ci);
        return;
    }
    
    for (i = 0; i < MAX_VALUE_COUNT; i++)
    {
        if (isValueValid(ci[index], cv[i]))
        {
            cv[i].used = true;
            ci[index].value = cv[i].value;
            SearchingResult(ci, cv, index + 1);
            cv[i].used = false;
        }
    }
}

int MakeIntegerValue(CharItem ci[MAX_CHAR_COUNT], char *str)
{
    int value = 0;
    int i = 0;
    while(str[0] != '\0')
    {
        for(i = 0; i < MAX_CHAR_COUNT; i++)
        {
            if (str[0] == ci[i].c)
            {
                if (ci[i].value < 0)
                {
                    value = 0;
                    goto out;
                }
                value = value *10 + ci[i].value;
            }
        }
        str++;
    }

out:
    return value;
}

void OnCharListReady(CharItem ci[MAX_CHAR_COUNT])
{
    char *minuend = "WWWDOT";
    char *subtrahend = "GOOGLE";
    char *diff = "DOTCOM";

    int m = MakeIntegerValue(ci, minuend);
    int s = MakeIntegerValue(ci, subtrahend);
    int d = MakeIntegerValue(ci, diff);
    
    if((m - s) == d)
    {
        printf("%d - %d = %d\n", m, s, d);
    }
}