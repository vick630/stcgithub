#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "ballsortpuzzle.h"


void generator(const int rows, const int columns, char field[rows][columns]);
void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y);


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

void generator(const int rows, const int columns, char field[rows][columns]){
int a, b;
    a=rand() % columns;
    do{
        b=rand() % columns;
        }while(a==b);
    printf ("%i\n", a);
    printf ("%i\n", b);

    char lol=' ';   
    //lol
    char tarhaz[4];
    tarhaz[1]='*';
    tarhaz[0]='+';
    tarhaz[2]='@';
    tarhaz[3]='^';
    
    
    for (int i=0; i<rows; i++){
        printf ("%c", ' ');
        printf ("%i", i+1);
        printf ("%c", ' ');        
        printf ("%c", '|');
        printf ("%c", ' ');
        
        for(int j=0; j<columns ; j++){
            field[i][j]=' ';
            if((j!=a) && (j!=b)){
                field[i][j]=tarhaz[rand() % 4];
            }
            printf ("%c", field[i][j]);
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

void down_possible(const int rows, const int columns, char field[rows][columns], int x, int y){



    printf("na most buzizz h mejjikbool \n");
    scanf("%i",&x);
    printf("na most buzizz h mejjikye \n");
    scanf("%i",&y);
    x--;              
    //elcsuszas a valosagtol
    y--;
    int i=0;
    char csre;

 //   printf("checkpoint0 \n");

    while ((field[i][x]==' ')&&(i!=rows-1)){         
        //melyik az elso elem
        i++;
    };

    csre=field[i][x];

   // printf("checkpoint1 \n");

    int j=0;

    while ((field[j][y]==' ')&&(j!=rows-1)){          
        //melyik az elso elem
       
      //  if((field[j][y]!=' ')){
      //  printf(" nop ");
      //  }
        j--;
    };
/*
    printf("checkpoint2 \n");

     for (int o=0; o<rows; o++){
        printf ("%c", ' ');
        printf ("%i", o+1);
        printf ("%c", ' ');        printf ("%c", '|');printf ("%c", ' ');
        //pusszancs cicus
        for(int p=0; p<columns ; p++){
            
            printf ("%c", field[o][p]);
            printf ("%c", ' ');
            printf ("%c", '|');
            printf ("%c", ' ');
        }
        printf("\n");
    }
    
    printf ("%i\n",i);
    printf ("%i\n",j);
    printf ("%i\n",x);
    printf ("%i\n",y);

    printf ("%c\n", field[j][y]);
    printf ("%c\n", field[3][5]);
*/
    if((field[j][y]!=csre)&&(field[j][y]!=' ')){        
        //ugyanazok a jelek vannak ynne, mint amit yle akarok rakni? Ureset sem enged szimxumosra
        printf(" ty si kokot? co robis??????? tam su ine znaky \n");
    }else 
        if(j==0){                                           
            //nincs sor tultoltes
           printf(" ty si kokot?? co robis??????? kde to tam zmesti???? \n");
        }else 
            if (x==y)                                    
            //ne rakd ugyanabba, minek?!
            {
                printf(" ty si kokot??? co robis??????? stlpy su tie iste!!! \n");
            }else
                if ((x>=columns)||(y>=columns))          
                //nem letezo oszlopokba ne rakjanak
                {
                    printf(" ty si kokot???? co robis??????? take stlpy neexistuju!!! \n");
                }else 
                    if(field[j][y]!=' '){                    
                        //ha nem ures sorba raksz
                        field[j-1][y]=field[i][x];
                        field[i][x]=' ';
                    }else{                                      
                        //ha uj sort kezdesz
                        field[j][y]=field[i][x];
                        field[i][x]=' ';
                    }
                        
    

    //a=field[1][y];
    //field[1][y]=field[1][x];
    //field[1][x]=a;

}
