#include <stdio.h>
#include <math.h>
float lift_a_car(const int stick_length, const int human_weight, const int car_weight);
float unit_price(const float pack_price, const int rolls_count, const int pieces_count);
int collatz(const int number);

int main(){
printf("%.2f\n",(lift_a_car(2,80,1400)));
printf("%.2f\n",(unit_price(4.79,16,150)));
printf("%d\n", collatz(35));
}

float lift_a_car(const int stick_lenght, const int human_weight, const int car_weight){
float hodnota= (float) stick_lenght * (float) human_weight/ ((float)human_weight+ (float)car_weight);
hodnota=hodnota*100;
hodnota=round(hodnota);
hodnota=hodnota/100;
return hodnota;}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
float hodnotaa=( float) pack_price/((float) rolls_count * (float) pieces_count);
hodnotaa=hodnotaa*100;
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
