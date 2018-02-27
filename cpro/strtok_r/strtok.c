#include <stdio.h>
#include <string.h>

int main(void)
{
    int j, in = 0;
    char buffer[100] = "Fred male 25,John male 62,Anna female 16";
    char *p[20];
    char *buf = buffer;
    char *outer_ptr = NULL;
    char *inner_ptr = NULL;
    
    printf("### old buffer: %s\n", buffer);

    while ((p[in] = strtok_r(buf, ",", &outer_ptr)) != NULL)
    {
        buf = p[in];
        while ((p[in] = strtok_r(buf, " ", &inner_ptr)) != NULL)
        {
            in++;
            buf = NULL;
        }
        buf = NULL;
    }
    printf("Here we have %d strings\n", in);
    for (j = 0; j < in; j++)
    {
        printf(">%s<\n", p[j]);
    }
    
    printf("### new buffer: %s\n", buffer);
    
    return 0;
}