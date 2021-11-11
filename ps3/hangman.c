#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <sys/stat.h>
#include <string.h>

int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]){
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
}}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
int l=strlen(secret);
int ll=strlen(letters_guessed);

    if(strlen(letters_guessed)==0){
        for(int i=0;i<l;i=i+1){
            guessed_word[i]='_';
        }}
    for(int i=0;i<l;i=i+1){
        for(int o=0;o<ll;o=o+1){
            if(secret[i]==letters_guessed[o]){
                guessed_word[i]=secret[i];
                break;
            }
            guessed_word[i]='_';   
        }    
    }
int end=strlen(secret);
guessed_word[end]='\0';
}


void get_available_letters(const char letters_guessed[], char available_letters[]){
int  z, p=0;
char abeceda[] = "abcdefghijklmnopqrstuvwxyz";
int l=strlen(abeceda);
int ll=strlen(letters_guessed);
int i=0;
while(i!=l)
{
    z=0;
    int j=0;
    while(j!=ll)
    {
        if(abeceda[i] == letters_guessed[j])
        {
            z= 1;
            break;
        }
        j=j+1;
    }
    if(z!=1)
    {
        available_letters[p]=abeceda[i];
        p=p+1;
    }
    i=i+1;

}
available_letters[p]= '\0';
}     

void hangman(const char secret[]){ 
    char h[26], alpha[30], given[50]="", writen[30]="";
    int n=1
int t=8;
    int l=0;
    get_guessed_word(secret,given,writen);
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %ld letters long.", strlen(secret));
    printf("\n-------------");
    while(n){
        printf("\nYou have %d guesses left.",t);
        printf("\nAvailable letters: ");
        get_available_letters(given,alpha);
        printf("%s",alpha);
        printf("\nPlease guess a letter: ");
        scanf("%s",h);
        while (getchar()!='\n')
            ;
        for(int i=0;i<strlen(h);i=i+1){
            h[i]=tolower(h[i]);
        }
        if(strlen(h)==1){
            char lett=h[0];
            if(lett<'a' || lett>'z'){
                printf("Oops! '%c' is not a valid letter:", lett);
                for(int i=0;i<strlen(writen);i=i+1){
                    printf(" %c",writen[i]);
                }
                printf("\n-------------");
                continue;
            }
            if(!strchr(alpha,lett)){
                printf("Oops! You've already guessed that letter:");
                get_guessed_word(secret,given,writen);
                for(int i=0;i<strlen(writen);i=i+1){
                    printf(" %c",writen[i]);
                }
                printf("\n-------------");
                continue;
            }
            given[l++]=lett;
            if(strchr(secret,lett)){
                printf("Good guess:");
                get_guessed_word(secret,given,writen);
                for(int i=0;i<strlen(writen);i=i+1){
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
                t=t-1;
                if(t==0){
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

















