// Do not remove the include below
#include "Keen.h"

// 这里设置步进电机旋转一圈是多少步
#define STEPS 100

// attached to设置步进电机的步数和引脚
Stepper stepper(STEPS, 8, 9, 10, 11);

//The setup function is called once at startup of the sketch
void setup() {
    Serial.begin(9600);
    // 设置电机每分钟的转速为90步
    stepper.setSpeed(90);
}

// The loop function is called in an endless loop
void loop() {
    while (Serial.available()) {
        char c = Serial.read();
        if (c == 'A') {
            int step = Serial.readString().toInt();
            stepper.step(step);
            Serial.println(step);
        }
    }
    delay(100);
}
