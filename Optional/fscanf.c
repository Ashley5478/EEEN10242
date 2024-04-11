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


    for(int i = 0; i < 10; i++) {
        scanf(" %c", &array[i]);
    }

    for(int i = 0; i < 10; i++) {
        printf("%c", array[i]);
    }

    return 0;
}