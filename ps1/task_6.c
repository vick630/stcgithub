#include <superkarel.h>
#define SPEED 200
void south();
void north();
void west();
void east();

int zbieraj();

int main(){
    turn_on("task_6.kw");
    set_step_delay(SPEED);
    
    while (no_beepers_present()){
        step();
    }
    while (zbieraj() == 1){
        if (no_beepers_present()){
            step();
        }
        else {
            zbieraj();
        }
    }
    turn_off();
    return 0;
}

int zbieraj(){
        if (beepers_present()){
            pick_beeper();
                if (beepers_present()){
                    pick_beeper();
                    if (beepers_present()){
                        pick_beeper();
                        if (beepers_present()){
                            pick_beeper();
                            if (beepers_present()){
                                pick_beeper();
                                return 0;
                            }

                            else {
                                east();
                                
                                return 1;
                            }
                        }
                        else {
                            south();
                            return 1;
                        }
                    }
                    else {
                        west();
                        return 1;
                    }
                }
                else {
                    north();
                    return 1;
                }
        }
         else {
            return 1;
         }
}



void east(){

    while (not_facing_east()){
        turn_left();}
}

void north(){
while (not_facing_north()){
    turn_left();
                    }
}


void south(){
    while (not_facing_south()){
                                turn_left();
                            }
}

void west(){
    while (not_facing_west()){
                            turn_left();
                        }
}
