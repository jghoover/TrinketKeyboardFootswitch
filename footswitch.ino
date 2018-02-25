#include <TrinketKeyboard.h>

// const int SHIFT_SWITCH = 4;
const int CTRL_SWITCH = 0;
const int ALT_SWITCH = 2;  // skip using pin 1 because it's mapped to the reset LED

void setup()
{
    // Set button pin as input with an internal pullup resistor
    // The button is active-low, they read LOW when they are not pressed

    // pinMode(SHIFT_SWITCH, INPUT_PULLUP);
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
  
    // todo: check and see if it will just work with the MOD_LEFT_CONTROL, with a 0 in the second arg
    if(digitalRead(CTRL_SWITCH) == LOW || digitalRead(ALT_SWITCH) == LOW)
    {
        if(digitalRead(CTRL_SWITCH) == LOW)
        {
            TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_CONTROL, KEYCODE_LEFT_CONTROL);
        }
        if(digitalRead(ALT_SWITCH) == LOW)
        {
            TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_ALT, KEYCODE_LEFT_ALT);
        }
    }
    else
    {
        TrinketKeyboard.pressKey(0,0);
    }

    // for testing
    /*if(digitalRead(SHIFT_SWITCH) == LOW)
    {
        TrinketKeyboard.print("SHIFT");
    }
    if(digitalRead(CTRL_SWITCH) == LOW)
    {
        TrinketKeyboard.print("CTRL");
    }
    if(digitalRead(ALT_SWITCH) == LOW)
    {
        TrinketKeyboard.print("ALT");
    }*/
  
}
