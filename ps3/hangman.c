#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"
#include<string.h> 


int main(){

//char hggjg[]="abcd";
//char a[]="a";


//printf("%d\n",is_word_guessed(abeceda,a) );
//get_available_letters(hggjg,a);
//get_guessed_word("tojejedno","tjo","");
hangman("ahoj");

//printf("\nahoj\n");
return 0;
}








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
//printf("%d\n", len);
//printf("%d\n", l);
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
	char available_letters[]="abcdefghijklmnopqrstuvwxyz";
	int a;//dlzka tajneho slova
	int l=8; //pocet pokusov
	char slovo[16]="\0";
	//char abeceda[]="abcdefghijklmnopqrstuvwxyz";
	char letters_guessed[100];

	int i;
	int j;

    for(i=0;i<100;i++){             //vycistenie pola
        letters_guessed[i]='\0';
    }


	printf("%s\n",secret );//sledujes ake slovo bolo zadane

    a=strlen(secret);

    printf("%d\n",a );//kontrolujes dlzku slova
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %d letters long.\n", a);
    while(l!=0){

		printf("You have %d guesses left.\n",l);
		printf("Available letters: ");
		get_available_letters( letters_guessed,  available_letters);
		//tu budes volat funkciu ( letters_guessed,  available_letters);
        printf("\n");
        printf("Please guess a letter:"  );
        scanf("%s", slovo);
        //printf("%s\n",slovo );
        j=0;                     
        do{                                      //zmeni velke pismena na male
            if(isupper(slovo[j])){
                slovo[j]=tolower(slovo[j]);
            }
            j++;
        }
        while(slovo[j]!='\0');

        










    	l=l-1;//toto bude na konci pocita pocet pokusov

    }




}
