#include <Arduino.h>

IRAM_ATTR void handleInterrupt();
const int IDLE = 0;
const int PRESS = 1;
int flag = false;
int state;
void setup() { 
	state = IDLE;
	pinMode(D4, OUTPUT); 
	pinMode(D6, INPUT); 
	attachInterrupt(digitalPinToInterrupt(D6), handleInterrupt, CHANGE); 
} 
void loop() { 
	if (state == IDLE){
		digitalWrite(D4, HIGH); 
		if (flag == true){
			flag = false;
			state = PRESS;
		}
	}else if (state == PRESS){
		digitalWrite(D4, LOW); 
		if (flag == true){
			flag = false;
			state = IDLE;
		}

	}
} 
IRAM_ATTR void handleInterrupt() { 
	flag = true;
}
