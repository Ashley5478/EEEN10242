#include <stdio.h>

int main(){
    printf("L%8.3fL\n", 23.4);
    printf("L%8.3fL\n", 2.45);

int a = 100, b = 10000, c = 1000000;
printf( "%12d %12d %12d\n", a, b, c);
printf( "%-12d %-12d %-12d\n", a, b, c);

    return 0;
}