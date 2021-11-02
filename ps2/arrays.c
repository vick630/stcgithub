#include <stdio.h>
#include <math.h>
float lift_a_car(const int stick_length, const int human_weight, const int car_weight);

int main(){
printf("%.2f\n",(lift_a_car(2,80,1400)));
}

float lift_a_car(const int stick_lenght, const int human_weight, const int car_weight){
float hodnota= (float) stick_lenght * (float) human_weight/ ((float)human_weight+ (float)car_weight);
hodnota=hodnota*100;
hodnota=round(hodnota);
hodnota=hodnota/100;
return hodnota;}
