#include <stdio.h>

int main(int argc, char* argv[]){
char ok[]={'a','n','a','n','a','s'};
FILE *suboor = fopen (argv[1],"r+");
if(argc!=2)
{
    return 0;
}

int p=0;
int o=0;

char ch = fgetc(suboor);
while(ch != EOF)
{
    if(ch<97)
    {
        ch=ch+32;
    }
    if(ok[o]==ch)
    {
        o=o+1;
    }
    else
    {
        o=0;
    }
    if(o==6)
    {
        p=p+1;
        o=0;
    }
    ch = fgetc(suboor);
}
printf("%i\n",p);
fclose(suboor);

FILE *subor = fopen (argv[1],"w");
int b=(p-(p%10))/10;
if(p<10)
{
    fputc( (p)+48 , subor );
}
if(p<100 && p>9 ){
    fputc( (b)+48 , subor );
    fputc( (p%10)+48 , subor ); 
    }

fclose(subor);
}
