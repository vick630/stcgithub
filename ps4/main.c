#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>



int main(){
    srand(time(NULL));
    int rows=4;
    int columns=6;
    char field[rows][columns];
    game_field(rows,columns,field);
    return 0;
}

