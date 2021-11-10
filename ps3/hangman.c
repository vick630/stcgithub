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



void hangman(const char secret[]){
    char h[26], alpha[30], given[50]="", writen[30]="";
    int go_on=1, tries=8;
    int l=0;
    get_guessed_word(secret,given,writen);
    
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %ld letters long.", strlen(secret));
    printf("\n-------------");
    while(go_on){
        printf("\nYou have %d guesses left.",tries);
        printf("\nAvailable letters: ");
        get_available_letters(given,alpha);
        printf("%s",alpha);
        printf("\nPlease guess a letter: ");
        scanf("%s",h);
        while (getchar()!='\n')
            ;
        for(int i=0;i<strlen(h);i++){
            h[i]=tolower(h[i]);
        }
        if(strlen(h)==1){
            char lett=h[0];
            if(lett<'a' || lett>'z'){
                printf("Oops! '%c' is not a valid letter:", lett);
                for(int i=0;i<strlen(writen);i++){
                    printf(" %c",writen[i]);
                }
                printf("\n-------------");
                continue;
            }
            if(!strchr(alpha,lett)){
                printf("Oops! You've already guessed that letter:");
                get_guessed_word(secret,given,writen);
                for(int i=0;i<strlen(writen);i++){
                    printf(" %c",writen[i]);
                }
                printf("\n-------------");
                continue;
            }
            given[l++]=lett;
            if(strchr(secret,lett)){
                printf("Good guess:");
                get_guessed_word(secret,given,writen);
                for(int i=0;i<strlen(writen);i++){
                    printf(" %c",writen[i]);
                }
                if(is_word_guessed(secret,given)==1){
                    printf("\n-------------");
                    printf("\nCongratulations, you won!\n");
                    break;
                }
            }
            else{
                printf("Oops! That letter is not in my word:");
                get_guessed_word(secret,given,writen);
                for(int i=0;i<strlen(writen);i++){
                    printf(" %c",writen[i]);
                }
                tries--;
                if(tries==0){
                    printf("\n-------------");
                    printf("\nSorry, you ran out of guesses. The word was %s.\n",secret);
                    break;
                }
            }
            printf("\n-------------");
        }
        else if(strlen(h)==strlen(secret)){
            if(*h==*secret){
                printf("Congratulations, you won!\n");
                break;   
            }
            else{
                printf("Sorry, bad guess. The word was %s.\n",secret);
                break;
            }
        }
        else{
            printf("Oops! '%s' is not a valid entry:",h);
            for(int i=0;i<strlen(writen);i++){
                    printf(" %c",writen[i]);
                }
                printf("\n-------------");
                continue;
        }
    }
}

