#include "core/powerSave.h"
#include <interface.h>

/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
#if defined(SEL_BTN) && SEL_BTN >= 0
    pinMode(SEL_BTN, INPUT_PULLUP);
#endif
#if defined(UP_BTN) && UP_BTN >= 0
    pinMode(UP_BTN, INPUT_PULLUP);
#endif
#if defined(DOWN_BTN) && DOWN_BTN >= 0
    pinMode(DOWN_BTN, INPUT_PULLUP);
#endif
#if defined(BACK_BTN) && BACK_BTN >= 0
    pinMode(BACK_BTN, INPUT_PULLUP);
#endif
#if defined(LEFT_BTN) && LEFT_BTN >= 0
    pinMode(LEFT_BTN, INPUT_PULLUP);
#endif
#if defined(RIGHT_BTN) && RIGHT_BTN >= 0
    pinMode(RIGHT_BTN, INPUT_PULLUP);
#endif
}

/***************************************************************************************
** Function name: getBattery()
** location: display.cpp
** Description:   Delivers the battery value from 1-100
***************************************************************************************/
int getBattery() { return 0; }

/***************************************************************************************
** Function name: isCharging()
** Description:   Default implementation that returns false
***************************************************************************************/
bool isCharging() { return false; }

/*********************************************************************
** Function: setBrightness
** location: settings.cpp
** set brightness value
**********************************************************************/
void _setBrightness(uint8_t brightval) {}

/*********************************************************************
** Function: InputHandler
** Handles the variables PrevPress, NextPress, SelPress, AnyKeyPress and EscPress
**********************************************************************/
void InputHandler(void) {
#if defined(SEL_BTN) && SEL_BTN >= 0
    if (digitalRead(SEL_BTN) == BTN_ACT) {
        delay(50);
        if (digitalRead(SEL_BTN) == BTN_ACT) {
            SelPress = true;
            AnyKeyPress = true;
            while (digitalRead(SEL_BTN) == BTN_ACT) delay(10);
        }
    }
#endif
#if defined(UP_BTN) && UP_BTN >= 0
    if (digitalRead(UP_BTN) == BTN_ACT) {
        delay(50);
        if (digitalRead(UP_BTN) == BTN_ACT) {
            PrevPress = true;
            AnyKeyPress = true;
            while (digitalRead(UP_BTN) == BTN_ACT) delay(10);
        }
    }
#endif
#if defined(DOWN_BTN) && DOWN_BTN >= 0
    if (digitalRead(DOWN_BTN) == BTN_ACT) {
        delay(50);
        if (digitalRead(DOWN_BTN) == BTN_ACT) {
            NextPress = true;
            AnyKeyPress = true;
            while (digitalRead(DOWN_BTN) == BTN_ACT) delay(10);
        }
    }
#endif
#if defined(BACK_BTN) && BACK_BTN >= 0
    if (digitalRead(BACK_BTN) == BTN_ACT) {
        delay(50);
        if (digitalRead(BACK_BTN) == BTN_ACT) {
            EscPress = true;
            AnyKeyPress = true;
            while (digitalRead(BACK_BTN) == BTN_ACT) delay(10);
        }
    }
#endif
#if defined(LEFT_BTN) && LEFT_BTN >= 0
    if (digitalRead(LEFT_BTN) == BTN_ACT) {
        delay(50);
        if (digitalRead(LEFT_BTN) == BTN_ACT) {
            PrevPress = true;
            AnyKeyPress = true;
            while (digitalRead(LEFT_BTN) == BTN_ACT) delay(10);
        }
    }
#endif
#if defined(RIGHT_BTN) && RIGHT_BTN >= 0
    if (digitalRead(RIGHT_BTN) == BTN_ACT) {
        delay(50);
        if (digitalRead(RIGHT_BTN) == BTN_ACT) {
            NextPress = true;
            AnyKeyPress = true;
            while (digitalRead(RIGHT_BTN) == BTN_ACT) delay(10);
        }
    }
#endif

#if defined(USE_TFT_eSPI_TOUCH) && defined(HAS_TOUCH)
    uint16_t tx, ty;
    if (tft.getTouch(&tx, &ty)) {
        AnyKeyPress = true;
        // Map touch zones ke navigasi
        if (ty < tft.height() / 3) {
            PrevPress = true;  // Top zone = UP
        } else if (ty > (tft.height() * 2 / 3)) {
            NextPress = true;  // Bottom zone = DOWN
        } else if (tx < tft.width() / 3) {
            EscPress = true;   // Left zone = BACK
        } else if (tx > (tft.width() * 2 / 3)) {
            SelPress = true;   // Right zone = SELECT
        } else {
            SelPress = true;   // Center zone = SELECT
        }
        while (tft.getTouch(&tx, &ty)) delay(10); // tunggu release
    }
#endif
}

/*********************************************************************
** Function: powerOff
** location: mykeyboard.cpp
** Turns off the device (or try to)
**********************************************************************/
void powerOff() {}

/*********************************************************************
** Function: checkReboot
** location: mykeyboard.cpp
** Btn logic to turnoff the device (name is odd btw)
**********************************************************************/
void checkReboot() {}
