#include <Arduino.h>

#include "display.h"

OLED displayRobot("xx%\n\n", "Just Started\n\n", "Nothing\n");

EasyButton black(BLACK_BUTTON_PIN, 50, false, true);
EasyButton grey(GREY_BUTTON_PIN, 50, false, true);
EasyButton red(RED_BUTTON_PIN, 50, false, true);

void setup() {
    Serial.begin(9600);

    setupDisplay();

    black.begin();
    black.onPressedFor(1000, Button_Mode_A_Hold_Callback);
    black.onPressed(Button_Mode_A_Callback);
    black.onSequence(2, 1000, Button_Mode_A_2_Sequence_Callback);
    black.onSequence(3, 1000, Button_Mode_A_3_Sequence_Callback);

    grey.begin();
    grey.onPressedFor(1000, Button_Mode_B_Hold_Callback);
    grey.onPressed(Button_Mode_B_Callback);
    grey.onSequence(2, 1000, Button_Mode_B_2_Sequence_Callback);
    grey.onSequence(3, 1000, Button_Mode_B_3_Sequence_Callback);

    red.begin();
    red.onPressed(Button_Trig_Callback);
    red.onPressedFor(1000, Button_Trig_Hold_Callback);
}

void loop() {
    black.read();
    grey.read();
    red.read();
    display(displayRobot.show());
}
