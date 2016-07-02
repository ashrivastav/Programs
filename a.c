#include <stdio.h>
int main()
{
    unsigned short submit = 0;
    unsigned short complete = 65535;
    unsigned short d = submit - complete;
    unsigned short c = 0;
    if (d < c)
        printf("Working fine: %u %u\n", submit - complete, d);
}
