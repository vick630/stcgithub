#include <superkarel.h>
#define SPEED 200

void turn_right();
void mark();
void kontrola();
void sklad();
void turn_2left();

int main(){

    set_step_delay(SPEED);
    turn_on("task_7.kw");
    mark();
    while (front_is_clear()){
      if (front_is_blocked()){
        break;
      }
      else {
        if (left_is_blocked()){
            step();
        }
        else {
            turn_left();
            step();
            put_beeper();
            step();
            sklad();
            while (not_facing_south()){
                turn_left();
            }
            if (front_is_blocked()){
                turn_2left();
                step();
                if (no_beepers_present()){
                    put_beeper();
                }
                turn_2left();
                step();
                turn_left();
                if (front_is_clear()){
                    step();
                }
            }
            else {
                pick_beeper();
                step();
                turn_left();
                if (front_is_clear()){
                    step();
                }
            }
        }
    }
  }
    kontrola();
    turn_off();
    return 0;

}
void mark(){
    put_beeper();
    while (front_is_clear()){
        step();
        put_beeper();
    }
    turn_2left();
    while (front_is_clear()){
        step();
    }
    turn_2left();
}

void sklad(){
    while (no_beepers_present()){
        if (beepers_present()){
            break;
        }
        else {
            while ( front_is_clear() && left_is_blocked() ){
                if (beepers_present()){
                    break;
                }
                else {
                    step();
                }
            }   
            if (left_is_clear()){
                if (beepers_present()){
                    break;
                }
                else {
                    turn_left();
                    step();
                    sklad();
                }
            }
            if ( front_is_blocked() && left_is_blocked() ){
                turn_right();
                sklad();
            }   
        }
    }
}


void kontrola(){
    pick_beeper();
    turn_2left();
    while (front_is_clear()){
        step();
        pick_beeper();
    }
    turn_2left();
    while (front_is_clear()){
        step();
    }
}

void turn_2left(){
    turn_left();
    turn_left();
}
void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}
