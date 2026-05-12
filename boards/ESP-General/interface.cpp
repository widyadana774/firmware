#include "core/powerSave.h"
#include <interface.h>

extern bool _boot_done;
/***************************************************************************************
** Function name: _setup_gpio()
** Location: main.cpp
** Description:   initial setup for the device
***************************************************************************************/
void _setup_gpio() {
    // #if defined(SEL_BTN) && SEL_BTN >= 0
    //     pinMode(SEL_BTN, INPUT_PULLUP);
    // #endif
    // #if defined(UP_BTN) && UP_BTN >= 0
    //     pinMode(UP_BTN, INPUT_PULLUP);
    // #endif
    // #if defined(DOWN_BTN) && DOWN_BTN >= 0
    //     pinMode(DOWN_BTN, INPUT_PULLUP);
    // #endif
    // #if defined(BACK_BTN) && BACK_BTN >= 0
    //     pinMode(BACK_BTN, INPUT_PULLUP);
    // #endif
    // #if defined(LEFT_BTN) && LEFT_BTN >= 0
    //     pinMode(LEFT_BTN, INPUT_PULLUP);
    // #endif
    // #if defined(RIGHT_BTN) && RIGHT_BTN >= 0
    //     pinMode(RIGHT_BTN, INPUT_PULLUP);
    // #endif
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
    static unsigned long tm = 0;
    if (millis() - tm < 200 && !LongPress) return;

    #if defined(UP_BTN)
    bool _u = (UP_BTN >= 0)    ? (digitalRead(UP_BTN) == BTN_ACT)    : false;
#else
    bool _u = false;
#endif
#if defined(DOWN_BTN)
    bool _d = (DOWN_BTN >= 0)  ? (digitalRead(DOWN_BTN) == BTN_ACT)  : false;
#else
    bool _d = false;
#endif
#if defined(LEFT_BTN)
    bool _l = (LEFT_BTN >= 0)  ? (digitalRead(LEFT_BTN) == BTN_ACT)  : false;
#else
    bool _l = false;
#endif
#if defined(RIGHT_BTN)
    bool _r = (RIGHT_BTN >= 0) ? (digitalRead(RIGHT_BTN) == BTN_ACT) : false;
#else
    bool _r = false;
#endif
#if defined(SEL_BTN)
    bool _s = (SEL_BTN >= 0)   ? (digitalRead(SEL_BTN) == BTN_ACT)   : false;
#else
    bool _s = false;
#endif
#if defined(BACK_BTN)
    bool _b = (BACK_BTN >= 0)  ? (digitalRead(BACK_BTN) == BTN_ACT)  : false;
#else
    bool _b = false;
#endif

    if (_u) { PrevPress = true; AnyKeyPress = true; }
    if (_d) { NextPress = true; AnyKeyPress = true; }
    if (_l) { PrevPress = true; AnyKeyPress = true; }
    if (_r) { NextPress = true; AnyKeyPress = true; }
    if (_s) { SelPress  = true; AnyKeyPress = true; }
    if (_b) { EscPress  = true; AnyKeyPress = true; }

    tm = millis();

#if defined(HAS_TOUCH)
    static unsigned long _touch_start = 0;
    if (_touch_start == 0) _touch_start = millis();
    if (millis() - _touch_start > 10000) {
        uint16_t tx, ty;
        if (tft.getTouch(&tx, &ty, 500)) {
            AnyKeyPress = true;
            if (ty < tft.height() / 3) { PrevPress = true; }
            else if (ty > (tft.height() * 2 / 3)) { NextPress = true; }
            else if (tx < tft.width() / 3) { EscPress = true; }
            else { SelPress = true; }
            while (tft.getTouch(&tx, &ty)) delay(10);
        }
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
