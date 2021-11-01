#include <superkarel.h>
#define SPEED 200
void kontrola();
void otoc_180();

int main(){
	turn_on("task_4.kw");
	set_step_delay(SPEED);
	kontrola();
	turn_left();
	while(front_is_clear() && no_beepers_present()){
			step();
		}
		if(beepers_present()){
			otoc_180();
			while(front_is_clear()){
				step();
			}
			otoc_180();
			while(front_is_clear()){
				if(no_beepers_present()){
					put_beeper();
					step();
				}
				else{
					step();
				}
			}
			if(no_beepers_present()){
				put_beeper();
			}
			otoc_180();
			while(front_is_clear()){
				step();
			}
			turn_left();
		}
		else{
			otoc_180();
			while(front_is_clear()){
				step();
			}
			turn_left();
		}
	turn_off();
    return 0;
}

void otoc_180(){
    turn_left();
	turn_left();
}

void kontrola(){
	while(front_is_clear()){
		turn_left();
		while(front_is_clear() && no_beepers_present()){
			step();
		}
		if(beepers_present()){
			otoc_180();
			while(front_is_clear()){
				step();
			}
			otoc_180();
			while(front_is_clear()){
				if(no_beepers_present()){
					put_beeper();
					step();
				}
				else{
					step();
				}
			}
			if(no_beepers_present()){
				put_beeper();
			}
			otoc_180();
			while(front_is_clear()){
				step();
			}
			turn_left();
			step();
		}
		else{
			otoc_180();
			while(front_is_clear()){
				step();
			}
			turn_left();
			step();
		}
	}
}
