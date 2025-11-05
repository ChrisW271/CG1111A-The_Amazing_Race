#include <MeMCore.h>

void setup() {
    Serial.begin(9600);
    initialize_PID();
}

bool FORWARD = true;
String g_color = "";

void loop() {
    if (FORWARD) {
        float speedPID = calculate_PID();
        moveForward(speedPID);

        // if (detected color) g_color = getcolor(); 
    } 
    else {
        String s = String(g_color);
        if (s == "RED") turnLeft();
        else if (s == "GREEN") turnRight();
        else if (s == "ORANGE") uTurn();
        else if (s == "Pink") doubleLeftTurn();
        else if (s == "LIGHTBLUE") doubleRightTurn();
        FORWARD = true;
    }
    delay(10);
}