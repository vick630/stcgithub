#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include "hangman.h"

int main(){
    srand(time(NULL));
    char secret[30];
    get_word(secret);
    hangman(secret);
    
    return 0;
}
