#include "button_debounce_filter.h"

const int ledPin = 13;

const int buttonPin = 2;
ButtonDebounceFilter buttonDebounce; 

void setup() {
  // inital ButtonDebounceFilter with buttonPin
  buttonDebounce.begin(buttonPin);
  buttonDebounce.setDebounceInterval(100);

  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  

}

void loop() {

  buttonDebounce.monitorButtonState();

  bool is_high; 
  bool is_low;

  buttonDebounce.isReliableHighLow(is_high, is_low);

  if (is_high) {
    Serial.println("button turn high");
    digitalWrite(ledPin, HIGH);
  }

  if (is_low) {
    Serial.println("button turn low");
    digitalWrite(ledPin, LOW);
  }

  buttonDebounce.updateButtonState();
}
