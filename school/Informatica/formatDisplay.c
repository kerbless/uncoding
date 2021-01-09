#include <stdio.h>
#include <stdlib.h>

int main() {
    float num = 999;
    printf("%2s", (*char)num);
    printf ("\n%-6s%-6s", "no", "where");
    return 0;
}