#include <superkarel.h>
#define SPEED 200

void turn_right();
void back();

int main(){

    set_step_delay(SPEED);
    turn_on("task_2.kw");

    while (no_beepers_present()){
         while (front_is_clear() && no_beepers_present()){
        step();
    }
    turn_left();
    }
    pick_beeper();
    turn_left();
    while (front_is_clear()){
        back();
    }

    turn_off();
    return 0;

}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void back(){
    while (front_is_clear()){
        step();
    }
    turn_right();
}
