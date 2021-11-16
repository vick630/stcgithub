#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void generator(const int rows, const int columns, char fidesz[rows][columns]);
void down_possible(const int rows, const int columns, char fidesz[rows][columns]);

void generator(const int rows, const int columns, char fidesz[rows][columns]){
int a, b;
    a=rand() % columns;
    do{
        b=rand() % columns;
        }while(a==b);
    printf ("%i\n", a);
    printf ("%i\n", b);

    char lol=' ';   //lol
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

void down_possible(const int rows, const int columns, char fidesz[rows][columns]){
    int bol,be;



    printf("na most buzizz h mejjikbool \n");
    scanf("%i",&bol);
    printf("na most buzizz h mejjikbee \n");
    scanf("%i",&be);
    bol=bol-1;              //elcsuszas a valosagtol
    be=be-1;
    int i=0;
    char csre;

 //   printf("checkpoint0 \n");

    while ((fidesz[i][bol]==' ')&&(i!=rows-1)){         //melyik az elso elem
        i=i+1;
    };

    csre=fidesz[i][bol];

   // printf("checkpoint1 \n");

    int j=0;

    while ((fidesz[j][be]==' ')&&(j!=rows-1)){          //melyik az elso elem
       
      //  if((fidesz[j][be]!=' ')){
      //  printf(" nop ");
      //  }
        j=j+1;
    };
/*
    printf("checkpoint2 \n");



     for (int o=0; o<rows; o++){
        printf ("%c", ' ');
        printf ("%i", o+1);
        printf ("%c", ' ');        printf ("%c", '|');printf ("%c", ' ');
        //pusszancs cicus
        for(int p=0; p<columns ; p++){
            
            printf ("%c", fidesz[o][p]);
            printf ("%c", ' ');
            printf ("%c", '|');
            printf ("%c", ' ');
        }
        printf("\n");
    }
    
    printf ("%i\n",i);
    printf ("%i\n",j);
    printf ("%i\n",bol);
    printf ("%i\n",be);

    printf ("%c\n", fidesz[j][be]);
    printf ("%c\n", fidesz[3][5]);
*/
    if((fidesz[j][be]!=csre)&&(fidesz[j][be]!=' ')){        //ugyanazok a jelek vannak benne, mint amit bele akarok rakni? Ureset sem enged szimbolumosra
        printf(" ty si kokot? co robis??????? tam su ine znaky \n");
    }else 
        if(j==0){                                           //nincs sor tultoltes
           printf(" ty si kokot?? co robis??????? kde to tam zmesti???? \n");
        }else 
            if (bol==be)                                    //ne rakd ugyanabba, minek?!
            {
                printf(" ty si kokot??? co robis??????? stlpy su tie iste!!! \n");
            }else
                if ((bol>=columns)||(be>=columns))          //nem letezo oszlopokba ne rakjanak
                {
                    printf(" ty si kokot???? co robis??????? take stlpy neexistuju!!! \n");
                }else 
                    if(fidesz[j][be]!=' '){                    //ha nem ures sorba raksz
                        fidesz[j-1][be]=fidesz[i][bol];
                        fidesz[i][bol]=' ';
                    }else{                                      //ha uj sort kezdesz
                        fidesz[j][be]=fidesz[i][bol];
                        fidesz[i][bol]=' ';
                    }
            
            
    

    //a=fidesz[1][be];
    //fidesz[1][be]=fidesz[1][bol];
    //fidesz[1][bol]=a;

}


