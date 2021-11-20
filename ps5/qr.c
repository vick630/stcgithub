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
	/*
    bool bits1[8];
encode_char('a', bits1);
int i;
for( i = 0; i < 8; i++){
    printf("%d", bits1[i]);
}
printf("\n");
*/
/*
bool bits2[8] = {0,1,0,0,0,0,0,1};
printf("%c\n", decode_byte(bits2));
*/
/*
char* text = "Hello, how are you?";
const int len = strlen(text);
bool bytes1[len+1][8];
encode_string(text, bytes1);
int j;
for( j = 0; j <= len; j++){
    printf("%c: ", text[j]);
    int i;
    for( i = 0; i < 8; i++){
        printf("%d", bytes1[j][i]);
    }
    printf("\n");
}
*/

/*
bool bytes2[7][8] = {
    {0,1,0,0,1,0,0,0},
    {0,1,1,0,0,1,0,1},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,0,0},
    {0,1,1,0,1,1,1,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,0,0,0,0,0}
};
char string[7];
decode_bytes(7, bytes2, string);
printf("%s\n", string);




int length = 4+1, cols = 3, offset = 2;
bool bytes1[4+1][8] = {
    {0,1,0,0,0,0,0,1},
    {0,1,1,0,1,0,0,0},
    {0,1,1,0,1,1,1,1},
    {0,1,1,0,1,0,1,0},
    {0,0,0,0,0,0,0,0}
};
bool blocks1[offset*8][cols];
bytes_to_blocks(cols, offset, blocks1, length, bytes1);
int i,j;
for( j = 0; j < offset*8; j++){
    for( i = 0; i < cols; i++){
        printf("%d ", (blocks1[j][i] == true) ? 1 : 0);
    }
    printf("\n");
    
    if(j % 8 == 7){
        printf("\n");
    }
}

*/
bool blocks2[2*8][3] = {
    {0,0,0},
    {1,1,1},
    {0,1,1},
    {0,0,0},
    {0,1,1},
    {0,0,1},
    {0,0,1},
    {1,0,1},
    {0,0,0},
    {1,0,0},
    {1,0,0},
    {0,0,0},
    {1,0,0},
    {0,0,0},
    {1,0,0},
    {0,0,0}
};
bool bytes2[length][8];
blocks_to_bytes(3, 2, blocks2, length, bytes2);
for(int j = 0; j < length; j++){
    for(int i = 0; i < 8; i++){
        printf("%d", bytes2[j][i]);
    }
    printf("\n");
}
*/}
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
    printf()
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
	int i,j,a=0;
	for(i=0;i<(offset*8);i++)
	{
		if(i%8==0 && i>0)
		{
			a+=cols;
		}	
		for(j=a;j<cols+a;j++)
		{
			if(j>rows-1)
			{
				blocks[i][j%3]=0;
				continue;
			}			
			blocks[i][j%3]=bytes[j][i%8];
		}
				
	}
	
	
}


void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8])
{
    int i,j,a=0;
    for(i=a;i<8+a;i++)
    {
        for(j=0;j<rows;j++)
        {
            if(j%3 && i<0)
            {
                a+=8;
            }
            bytes[j][i%8]= blocks[i][j%3];
        }
    }
}