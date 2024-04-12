#include <stdio.h>

int main(){
    char array[10];

/*
    char* MAP = "a b c d e f g  h i k ";
    //for(int i = 0; i < 21; i++){
        sscanf(MAP, " %c", array);
    //}

    for(int i = 0; i < 21; i++){
        printf("%c", array[i]);
    }
    */

/*
    for(int i = 0; i < 10; i++) {
        scanf(" %c", &array[i]);
    }

    for(int i = 0; i < 10; i++) {
        printf("%c", array[i]);
    }
*/

FILE *fin;

    fin = fopen( "Test.txt", "r" );
    if( fin == NULL )
        return 1;

    printf( "Character count: %d.\n", charcount( fin ) );

    fclose( fin );

    return 0;
}

int charcount( FILE *const fin )
{
    int c, count;

    count = 0;
    for( ;; )
    {
        c = fgetc( fin );
        if( c == EOF || c == '\n' )
            break;
        ++count;
    }

    return count;
}