#include <superkarel.h>

void turn_right();
void find();
void control();

int main(){
	turn_on("task_1.kw");
	set_step_delay(100);
	if (front_is_blocked()){
		turn_left();
		step();
	}
	else{
		step();
	}
    find();
    pick_beeper();
	while(not_facing_north()){
    	turn_left();
    }
	step();
	step();
	
    control();
    turn_off();
    return 0;
}

void turn_right(){
	turn_left();
	turn_left();
	turn_left();
}

void find(){
	while(no_beepers_present()){
		if(front_is_clear() && right_is_blocked()){
			step();
		}
		if(right_is_clear()){
			turn_right();
			step();
		}
		if(front_is_blocked() && right_is_blocked() && left_is_blocked()){
			turn_left();
			turn_left();
		}
		if(front_is_blocked() && right_is_blocked() && left_is_clear()){
			turn_left();
		}
	}
}

void control(){
	
	while(no_beepers_present()){
		
        if (front_is_clear())
        {
           step();
	
        }		
		
        if (front_is_blocked())
        {
           turn_left();
        }
		
		
        while (right_is_blocked() && left_is_blocked() && front_is_clear())
        { step();
		}

		if (right_is_blocked() && left_is_blocked() && front_is_blocked()){
		turn_right();
		break;
		       }           
    
        
}}
