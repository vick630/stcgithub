#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
<<<<<<< HEAD

=======
>>>>>>> 02575adf56265e1f5c3b9303dd8bb8d11bb2797d
#include <time.h>
#include "hangman.h"

int main(){
    srand(time(NULL));
    char secret[30];
    get_word(secret);
    hangman(secret);
    
<<<<<<< HEAD
}
=======
    return 0;
}
>>>>>>> 02575adf56265e1f5c3b9303dd8bb8d11bb2797d
