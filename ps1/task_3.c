#include <superkarel.h>

#define SPEED 200

void pick();
void control();
void ukladanie();
void turn_right();
void otoc();
void left2();

int main(){
	turn_on("task_3.kw");
	set_step_delay(SPEEd);
	pick();
	while(front_is_clear()){
		if(  front_is_clear() && right_is_blocked()){
			if(beepers_in_bag()){
				put_beeper();
			}
			step();
		}
		if ( front_is_clear() &&  right_is_clear()){
			step();
		}

	}
	control();
	while(not_facing_north()){
		turn_left();
	}
	while(front_is_clear()){
		step();
	}
	turn_right();
	while(no_beepers_present()){
		step();
		if( facing_east() && front_is_blocked()){
			left2();
		}
		if( facing_west() && front_is_blocked() ){
			otoc();
		}
	}
	turn_left();
	turn_left();
	while(front_is_clear()){
		step();
	}
	left2();
	turn_off();
    return 0;
}
void pick(){
	while (front_is_clear()){
		if (beepers_present()){
			pick_beeper();
		}
		step();
	}
	if (beepers_present()){
		pick_beeper();
	}
	left2();
}

void turn_right(){
	turn_left();
	turn_left();
	turn_left();
}

void otoc(){
	turn_left();
		step();
		turn_left();
}

void left2(){
turn_left();
	turn_left();
}

void control(){
	while (left_is_clear()){
		otoc();
		while (front_is_clear()){
			if (beepers_present()){
				pick_beeper();
			}
			step();
			if (beepers_present()){
				pick_beeper();
			}
		}
		left2();
		ukladanie();
	}	
}

void ukladanie(){
	
	while(front_is_clear()){
		turn_right();
		step();
		left2();
		if(beepers_present()){
			step();
			if(beepers_in_bag()){
				put_beeper();
			}
			turn_right();
			if (front_is_clear()){
				step();
			}
		}
		else{
			step();
			turn_right();
			if(front_is_clear()){
				step();
			}
		}
	}
}
