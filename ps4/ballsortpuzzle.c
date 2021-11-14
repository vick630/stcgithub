#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>

void generator(const int rows, const int columns, char field[rows][columns]);

int main(){
    srand(time(NULL));
    int rows=4;
    int columns=6;
    char field[rows][columns];
    generator(rows,columns,field);
    return 0;
}

void generator(const int rows, const int columns, char field[rows][columns]){
int a, b;
    a=rand() % columns;

    do{
        b=rand() % columns;
        }while(a==b);
    printf ("%i\n", a);
    printf ("%i\n", b);

    char fidesz[rows][columns];
    char lol=' ';
    char tarhaz[4];
    tarhaz[1]='*';
    tarhaz[0]='+';
    tarhaz[2]='@';
    tarhaz[3]='^';
    
    int j=0;
    
    for (int i=0; i<rows; i++){
        printf ("%c", ' ');
        printf ("%i", i+1);
        printf ("%c", ' ');        printf ("%c", '|');printf ("%c", ' ');
        
        for(int j=0; j<columns ; j++){
            fidesz[i][j]=' ';
            if((j!=a) && (j!=b)){
                fidesz[i][j]=tarhaz[rand() % 4];
            }
            printf ("%c", fidesz[i][j]);
            printf ("%c", ' ');
            printf ("%c", '|');
            printf ("%c", ' ');
        }
        printf("%c\n",lol);
    }
    printf ("   %c", ' ');
        
    for(int k=0;k<columns;k++){
        printf ("%c", '-');
        printf ("%c", '-');
        printf ("%c", '-');
        printf ("%c", ' ');
    }
    
         printf("%c\n",lol);
         printf ("   %c", ' ');
         
    for(int k=1;k<columns+1;k++){
        printf ("%c", ' ');
        printf ("%i", k);
        printf (" %c", ' ');
        
    }
    
     printf("%c\n",lol);

}
