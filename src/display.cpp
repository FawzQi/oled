#include "display.h"

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String OLED::show() {
    return "Battery : " + OLED::battery + "Choosen mode:\n" + OLED::currMode + "Now Playing :\n" + OLED::modePlayed;
    ;
}

String OLED::getCurrmodeStr() {
    return OLED::currMode;
}

void OLED::setBatteryStr(String s) {
    OLED::battery = s;
}

void OLED::setCurmodeStr(String s) {
    OLED::currMode = s;
}

void OLED::setModeplayedStr(String s) {
    OLED::modePlayed = s;
}

void setupOled() {
    Serial.begin(9600);

    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("failed to start SSD1306 OLED"));
    }

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 2);
    oled.println("VI-ROSE");
    oled.display();
}

void display(String s) {
    oled.setTextSize(1);
    oled.setTextColor(WHITE);
    oled.setCursor(0, 2);
    oled.clearDisplay();
    oled.println(s);
    oled.display();
}
