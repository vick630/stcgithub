#include <stdio.h>

    int main(int argc, char* argv[])
    {
        FILE *subor=fopen (argv[1],"r+");
        FILE *suboor=fopen (argv[2],"w");
        int p=0;
        int a=0;
        char ok=fgetc(subor);
        while (ok != EOF )
        {  if(ok==83)
                { ok=fgetc(subor);
                    if(ok==84)
                    { ok=fgetc(subor);
                        if(ok==65)
                        {

                            ok=fgetc(subor);
                            if(ok==82)
                            {

                                ok=fgetc(subor);
                                if(ok==84)
                                {
                                    ok=fgetc(subor);
                                    while ( ok != EOF )
                                    {

                                        if (ok==83)
                                        {

                                            a=a+1;
                                            ok=fgetc(subor);
                                            if (ok==84)
                                            {
                                                a=a+1;
                                                ok=fgetc(subor);
                                                if (ok==79)
                                                {

                                                    a++;
                                                    ok=fgetc(subor);
                                                    if (ok==80)
                                                    {

                                                        break;
                                                        
                                                    }

                                                }

                                            }

                                        }


                                        if (p%2 ==0 && p>3)
                                        {

                                            fputc(32, suboor);

                                        }


                                        if (a==1 && p%2==0)
                                        {

                                            fputc(83, suboor);

                                        }

                                        if (a==2 && p%2==0)
                                        {

                                            fputc(83, suboor);
                                            fputc(84, suboor);

                                        }

                                        if (a==3 && p%2==0)
                                        {

                                            fputc(83, suboor);
                                            fputc(84, suboor);
                                            fputc(79, suboor);

                                        }
                                        a=0;
                                        while (ok !=32)
                                        {
                                            if (p%2 == 0)
                                            {
                                                fputc(ok, suboor);
                                            }
                                            ok=fgetc(subor);
                                        }
                                        p=p+1;
                                        ok=fgetc(subor);
                                    }}}}}}

    ok=fgetc(subor);}
    fclose(suboor);
    fclose(subor);
    	
    }
