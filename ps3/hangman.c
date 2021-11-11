#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "hangman.h"


int main(){
return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[])
{
int value;

 value=strcmp(secret,letters_guessed);  

if (secret==NULL ||letters_guessed==NULL)
{
	return 0;
}

	if (value==0)
	{
		return 1; 
	}
else{

	return 0;
}
}

void get_available_letters(const char letters_guessed[], char available_letters[]){

int  zhoda, pismeno=0;
int len, len2;
int i;

char abeceda[] = "abcdefghijklmnopqrstuvwxyz";


len=strlen(abeceda);
len2=strlen(letters_guessed);
//printf("len =%d\n",len );
//printf("len2 =%d\n",len2 );


i=0;
while(i!=len)
{
    zhoda=0;
    //int x=0;
    int j=0;
    while(j!=len2)
    {
     //   printf("ciklus 1\n");
      //  printf("j=%d\n",j );
      //  printf("x=%d\n",x );

        if(abeceda[i] == letters_guessed[j])
        {
          //  printf("ciklus2\n");
            zhoda = 1;
            break;
        }
        j=j+1;
       // x++;
    }
    if(zhoda!=1)
    {
        
        available_letters[pismeno]=abeceda[i];
        //printf("menim znak na %c\n",available_letters[i] );
        //printf("ciklus3\n");
        pismeno++;
    }
    i++;
        //printf("pismeno abeceda %c\n",abeceda[i] );
        //printf("pismeno letters_guessed %c\n",letters_guessed[i] );

}
available_letters[pismeno]= '\0';

printf("%s",available_letters );
}


void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
int len=strlen(letters_guessed);
int l=strlen(secret);

char jo[l+1];
for (int i = 0; i < l; ++i)
{
	jo[i]='_';
}
jo[l]='\0';
//printf("%s\n",jo );

for (int i = 0; i < l; ++i)
{
	for (int o = 0; o< len; ++o)
	{
		if (secret[i]==letters_guessed[o])
		{
		//	printf("%c\n", secret[i] );
			jo[i]=secret[i];
		}
	}
}
printf("%s\n", jo);
}


