#ifndef _display_h
#define _display_h

#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <EasyButton.h>

#define SCREEN_WIDTH 128  // OLED width,  in pixels
#define SCREEN_HEIGHT 64  // OLED height, in pixels

/* Push Button */
#define BLACK_BUTTON_PIN 19
#define GREY_BUTTON_PIN 18
#define RED_BUTTON_PIN 5

class OLED {
   private:
    String battery;     // Battery percentage
    String currMode;    // Current mode
    String modePlayed;  // Mode played

   public:
    OLED(String a, String b, String c) : battery(a), currMode(b), modePlayed(c) {}

    String show();                    // Returns the string to be displayed on the OLED
    String getCurrmodeStr();          // Returns the current mode
    void setBatteryStr(String s);     // Sets the battery percentage
    void setCurmodeStr(String s);     // Sets the current mode
    void setModeplayedStr(String s);  // Sets the mode played
};

void setupDisplay();     // Initializes the OLED display
void display(String s);  // Displays the string on the OLED

/* Callbacks for the push buttons */
void Button_Mode_A_Callback();
void Button_Mode_A_Hold_Callback();
void Button_Mode_A_2_Sequence_Callback();
void Button_Mode_A_3_Sequence_Callback();
void Button_Mode_B_Callback();
void Button_Mode_B_Hold_Callback();
void Button_Mode_B_2_Sequence_Callback();
void Button_Mode_B_3_Sequence_Callback();
void Button_Trig_Callback();
void Button_Trig_Hold_Callback();

extern OLED displayRobot;

#endif
