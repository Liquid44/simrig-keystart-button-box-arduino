#include <Joystick.h>

// key switch
#define keySwitchActive 6
#define keySwitchIgnition 9 

#define pressSwitch1 4
#define pressSwitch2 2
#define pressSwitch3 A0
#define pressSwitch4 14
#define pressSwitch5 20

Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD,
  7, 0,                  // Button Count, Hat Switch Count
  false, false, false,     // X and Y, but no Z Axis
  false, false, false,   // No Rx, Ry, or Rz
  false, false,          // No rudder or throttle
  false, false, false);  // No accelerator, brake, or steering

void setup() {
  // initialize key switch
  pinMode(keySwitchActive, INPUT_PULLUP);
  pinMode(keySwitchIgnition, INPUT_PULLUP);
  // initialize press switches
  pinMode(pressSwitch1, INPUT_PULLUP);
  pinMode(pressSwitch2, INPUT_PULLUP);
  pinMode(pressSwitch3, INPUT_PULLUP);
  pinMode(pressSwitch4, INPUT_PULLUP);
  pinMode(pressSwitch5, INPUT_PULLUP);

  Joystick.begin(false);
}

void loop() {
  if (digitalRead(keySwitchActive) == 0)  Joystick.pressButton(0);
  if (digitalRead(keySwitchIgnition) == 0)  Joystick.pressButton(1);
  if (digitalRead(pressSwitch1) == 0)  Joystick.pressButton(2);
  if (digitalRead(pressSwitch2) == 0)  Joystick.pressButton(3);
  if (digitalRead(pressSwitch3) == 0)  Joystick.pressButton(4);
  if (digitalRead(pressSwitch4) == 0)  Joystick.pressButton(5);
  if (digitalRead(pressSwitch5) == 0)  Joystick.pressButton(6);

  // could check if state even changed before clearing.. 
  
  Joystick.sendState();//send state 1st before we clear the button states
  ClearButtons();
}

void ClearButtons()
{
  Joystick.releaseButton(0);
  Joystick.releaseButton(1);
  Joystick.releaseButton(2);
  Joystick.releaseButton(3);
  Joystick.releaseButton(4);
  Joystick.releaseButton(5);
  Joystick.releaseButton(6);
  Joystick.releaseButton(7);
  delay(150);
}
