#include <stdio.h>

int main(int argc, char* argv[]){
if(argc!=2)
{
    printf("nope");
    return 0;
}
FILE *suboor = fopen (argv[1],"r+");
int p=0,o=0;
char ok[]={'a','n','a','n','a','s'};
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
if(p>9 && p<100){
    fputc( (p%10)+48 , subor ); 
    fputc( (b)+48 , subor );
    }
fclose(subor);
}
