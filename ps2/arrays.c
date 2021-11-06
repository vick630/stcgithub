#include <stdio.h>
#include <math.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int collatz(const int number);
int opposite_number(const int n, const int number);
int array_min(const int input_array[], const int array_size);
int array_max(const int input_arra[], const int array_siye);
void counter(const int input_array[], const int array_size, int result_array[2]);
unsigned long sum_squared(const int line);
unsigned long special_counter(const int input_array[],const int array_size);

int main(){
printf("%lu\n", sum_squared(4));

}

float lift_a_car(const int stick_lenght, const int human_weight, const int car_weight){
float hodnota= (float) stick_lenght * (float) human_weight/ ((float)human_weight+ (float)car_weight);
hodnota=hodnota*100;
hodnota=round(hodnota);
hodnota=hodnota/100;
return hodnota;}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
float hodnotaa=(( float) pack_price*100)/((float) rolls_count * (float) pieces_count);
hodnotaa=hodnotaa*100;
hodnotaa=round(hodnotaa);
hodnotaa=hodnotaa/100;
return hodnotaa;}
int collatz(const int number){
int n=( int) number;
int count=0;
while((int) n>1){
if (n%2==0){
n=n/2;
count=count+1;
}
else{
n=n*3+1;
count=count+1;
}
}
return count+1;
return 0;
}

int opposite_number(const int n, const int number){
return (number+(n/2))%n;
}

void counter(const int input_array[], const int array_size, int result_array[2]){
int length= (int) array_size;
int sum=0;
int summ=0;
for(int i=0; i<length;i=i+2){
sum=sum+input_array[i];
result_array[0]=sum;
}
for(int i=1; i<length; i=i+2){
summ=summ+input_array[i];
result_array[1]=summ;}
}


int array_min(const int input_array[], const int array_size){
int length= (int) array_size;
int min=input_array[0];
for(int i=0;i<=length;i=i+1){
if(input_array[i]<min)
min=input_array[i];}
return min;
}

int array_max(const int input_array[], const int array_size){
int i;
int length=(int)array_size;
int max=input_array[0];
for (i=1; i<length; i=i+1){
if (input_array[i]>max)
max=input_array[i];
}
return max;}

unsigned long special_counter(const int input_array[], const int array_size){
int length= (int) array_size;
int sum=0;
int summ=0;
int summm=0;
for(int i=0; i<length; i=i+2){
sum=sum+input_array[i];
}
for(int i=1; i<length; i=i+2){
summ=summ+(int) pow(input_array[i],2);
}
summm=(int)sum+ (int)summ;
return summm;}

unsigned long sum_squared(const int line){
int n= (int) line + 1;
int k=0;
int s=0;
int c=1;
int i=1;

do{
    k=int(c)*(int)c;
    s=(int)s+(int)k;
    c=(int)c*(n-i)/i;
    i++;
}
while(i<=n);
return s;
}

