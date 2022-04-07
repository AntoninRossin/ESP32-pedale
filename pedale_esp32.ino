#include <BleKeyboard.h>

BleKeyboard bleKeyboard;
const int LeftArrowPin = 3;
const int RightArrowPin = 1;
int LeftStateBefore = LOW;
int RightStateBefore = LOW;


void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(LeftArrowPin,INPUT_PULLDOWN);
  pinMode(RightArrowPin,INPUT_PULLDOWN);

}

void loop() {
  if(bleKeyboard.isConnected()) {
    
    
    int LeftState = digitalRead(LeftArrowPin);

    if(LeftStateBefore != LeftState && LeftState == HIGH){
      bleKeyboard.press(KEY_LEFT_ARROW);
      bleKeyboard.releaseAll();
      
    }
    LeftStateBefore = LeftState;

    int RightState = digitalRead(RightArrowPin);

    if(RightStateBefore != RightState && RightState == HIGH){
      bleKeyboard.press(KEY_RIGHT_ARROW);
      bleKeyboard.releaseAll();
      
    }
    RightStateBefore = RightState;
    
    

  }
}
