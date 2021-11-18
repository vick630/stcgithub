#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "ballsortpuzzle.h"


int main(){
    srand(time(NULL));
    int rows=4;
    int columns=6;
    char fidesz[rows][columns];
    bool ellenor;
    generator(rows,columns,field);

    int main(){
    srand(time(NULL));
    int rows=4;
    int columns=6;
    char field[rows][columns];
    bool ellenor;
    int x=2;
    int y=1;
    generator(rows,columns,field);

    do{
        down_possible(rows,columns,field,x,y);
  
        ellenor=true;
                        //innentol csak kiiratas a while vegeig
        for (int i=0; i<rows; i++){
            printf ("%c", ' ');
            printf ("%i", i+1);
            printf ("%c", ' ');        
            printf ("%c", '|');
            printf ("%c", ' ');
            
            for(int j=0; j<columns ; j++){
                
                    if(field[0][j]!=field[i][j]){             
                        //megegyezik-e az 1. (0.) elemmel a tobbi az oszlopban, azert a legelsovel hasonlitjuk ossze, hogy csak akkor legyen true, ha az egesz sor tele van (amig nincs tele addig az elso sorban szokoz van, tehat nem egyezik meg, ha meg teljesen ures akkor meg mar ujra jo)
                        ellenor=false;                          
                        //helyes sorrend ellenorzese
                    }
                
                printf ("%c", field[i][j]);
                printf ("%c", ' ');
                printf ("%c", '|');
                printf ("%c", ' ');
            }
            printf("\n");
        }
            printf("   ");
        for(int k=0;k<columns;k++){
            printf ("%c", '-');
            printf ("%c", '-');
            printf ("%c", '-');
            printf ("%c", ' ');
        }
        
            printf("\n");
            printf ("   %c", ' ');
            
        for(int k=1;k<columns+1;k++){
            printf ("%c", ' ');
            printf ("%i", k);
            printf (" %c", ' ');
            
        }
        
        printf("\n");

    }while(ellenor==false);

    printf("No konecne! trvalo to dlho ty tupak :)");
    return 0;
}
