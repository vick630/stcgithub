#include <superkarel.h>
#define SPEED 200
void roh();
void middle();
void back();
void turn_right();

int main(){
    turn_on("task_5.kw");
	set_step_delay(SPEED);
	roh();
	while (no_beepers_present())
	{
		if (front_is_clear())
		{
			put_beeper();
			step();
		}
		else if (front_is_blocked())
		{
			turn_left();
			put_beeper();
			step();
		}
		else
		{
			middle();
		}
		
	}

	turn_left();
	middle();
	step();
	turn_left();
	middle();
	step();
	turn_right();
    turn_off();
    return 0;
}

void roh(){
while (not_facing_east()){
        turn_left();
    }
    while (front_is_clear()){
        step();
    }
    while (not_facing_south()){
        turn_left();
    }
    while (front_is_clear()){
        step();
    }
    while (not_facing_north()){
        turn_left();
    }
	
}
void turn_right(){
	turn_left();
	turn_left();
	turn_left();
}
void back(){
	turn_left();
	turn_left();
}
void middle(){
	if(front_is_clear()){
		step();
		step();
		middle();
	}

	back();
	step();
	back();

}
