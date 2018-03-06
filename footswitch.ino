#include <TrinketKeyboard.h>

const int CTRL_SWITCH = 0;
const int ALT_SWITCH = 2;  // skip using pin 1 because it's mapped to the reset LED

void setup()
{
    // Set button pin as input with an internal pullup resistor
    // The button is active-low, they read LOW when they are not pressed
    pinMode(CTRL_SWITCH, INPUT_PULLUP);
    pinMode(ALT_SWITCH, INPUT_PULLUP);
 
    TrinketKeyboard.begin();
}
 
void loop()
{
    TrinketKeyboard.poll();
    // the poll function must be called at least once every 10 ms
    // or the computer may think that the device
    // has stopped working, and give driver errors

    if(digitalRead(CTRL_SWITCH) == LOW || digitalRead(ALT_SWITCH) == LOW)
    {
        if(digitalRead(CTRL_SWITCH) == LOW) //pin 0
        {
            TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_CONTROL, 0);
        }
        if(digitalRead(ALT_SWITCH) == LOW) // pin 2
        {
            TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_ALT, 0);
        }
    }
    else
    {
        TrinketKeyboard.pressKey(0,0);
    }

    // for testing
    /*
    if(digitalRead(CTRL_SWITCH) == LOW)
    {
        TrinketKeyboard.print("CTRL");
    }
    if(digitalRead(ALT_SWITCH) == LOW)
    {
        TrinketKeyboard.print("ALT");
    }*/
  
}
