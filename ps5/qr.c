#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

void encode_char(const char character, bool bits[8]);
char decode_byte(const bool bits[8]);
void encode_string(const char string[], bool bytes[strlen(string)+1][8]);
void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);
void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);

int main()
{
    return 0;
}


void encode_char(const char character, bool bits[8])
{
    
    int x =(char) character;
    int p=8;
    while(x>0)
    {
        if(x%2==1)
        {
            bits[p-1]=1;
        }
        else
        {
            bits[p-1]=0;
        }
        x=x/2;
        p--;  
    }
    while(p>0)
    {
        bits[p-1]= 0;
        p--;
    }
}


char decode_byte(const bool bits[8])
{
	int a=0;
	int i;
	int pole[]= {128,64,32,16,8,4,2,1};
	for (i=0;i<8;i++)
	{
		if(bits[i])
		{
			a+=pole[i];
		}
	}
	return (char)a;
}



void encode_string(const char string[], bool bytes[strlen(string)+1][8])
{
    int i;
    int j;
	for(i=0;i<strlen(string)+1; i++)
    {
        bool pole[8];
        encode_char(string[i], pole);
        for(j=0;j<8;j++)
        {
            bytes[i][j]= pole[j];
        }
    }
}



void decode_bytes(const int rows, bool bytes[rows][8], char string[rows])
{
    int i;
    for(i=0;i<rows;i++)
    {
     string[i]=   decode_byte(bytes[i]);
    }

}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
	for(int i = 0; i < offset; i++) {
		for(int j = 0; j < cols; j++) {
			for(int k = 0; k < 8; k++) {
				if(true) {
					blocks[8 * i + k][j] = bytes[i * 3 + cols][k];
				}	
			}
		}
	}
}

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
    for(int i = 0; i < offset; i++) {
        for(int j = 0; j < cols; j++) {
            for (int k = 0; k < 8; k++)
            {
                bytes[cols * i + j][k] = blocks[8 * i + k][j];
                
            }
        }
    }
}
