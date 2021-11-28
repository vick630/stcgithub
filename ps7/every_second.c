#include <stdio.h>

    int main(int argc, char* argv[])
    {FILE *subor=fopen (argv[1],"r+");
        FILE *suboor=fopen (argv[2],"w");
        int pit=0,a=0;
        char ch=fgetc(subor);
        while (ch != EOF )
        {
                if(ch==83)
                {

                    ch=fgetc(subor);
                    if(ch==84)
                    {

                        ch=fgetc(subor);
                        if(ch==65)
                        {

                            ch=fgetc(subor);
                            if(ch==82)
                            {

                                ch=fgetc(subor);
                                if(ch==84)
                                {

                                    ch=fgetc(subor);
                                    while ( ch != EOF )
                                    {

                                        if (ch==83)
                                        {

                                            a++;
                                            ch=fgetc(subor);
                                            if (ch==84)
                                            {

                                                a++;
                                                ch=fgetc(subor);
                                                if (ch==79)
                                                {

                                                    a++;
                                                    ch=fgetc(subor);
                                                    if (ch==80)
                                                    {

                                                        break;
                                                        
                                                    }

                                                }

                                            }

                                        }


                                        if (pit%2 ==0 && pit>3)
                                        {

                                            fputc(32, suboor);

                                        }


                                        if (a==1 && pit%2==0)
                                        {

                                            fputc(83, suboor);

                                        }

                                        if (a==2 && pit%2==0)
                                        {

                                            fputc(83, suboor);
                                            fputc(84, suboor);

                                        }

                                        if (a==3 && pit%2==0)
                                        {

                                            fputc(83, suboor);
                                            fputc(84, suboor);
                                            fputc(79, suboor);

                                        }

                                        a=0;

                                        while (ch !=32)
                                        {

                                            if (pit%2 == 0)
                                            {

                                                fputc(ch, suboor);

                                            }

                                            ch=fgetc(subor);
                                        }

                                        pit++;
                                        ch=fgetc(subor);
                                    }

                                }

                            }

                        }

                    }

                }

    ch=fgetc(subor);}
    fclose(subor);
    fclose(suboor);	
    }
