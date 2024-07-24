#include <Arduino.h>

IRAM_ATTR void handleInterrupt();
const int IDLE = 0;
const int PRESS = 1;
int flag = false;
int count = -1;
int state;
void setup() { 
  Serial.begin(115200);
	state = IDLE;
	pinMode(D4, OUTPUT); 
	pinMode(D6, INPUT); 
	attachInterrupt(digitalPinToInterrupt(D6), handleInterrupt, RISING); 
} 
void loop() { 
	if (state == IDLE){
		digitalWrite(D4, HIGH); 
		if (flag == true){
			flag = false;
			state = PRESS;
		}
	}else if (state == PRESS){
    count++;
    if (count > 9){
      count = 0;
    }
    Serial.println(count);
    state = IDLE;
	}
} 
IRAM_ATTR void handleInterrupt() { 
	flag = true;
}
