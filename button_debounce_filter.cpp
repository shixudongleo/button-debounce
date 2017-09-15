#include "button_debounce_filter.h"

ButtonDebounceFilter::ButtonDebounceFilter() {
    button_state_ = LOW;
    last_voltage_state_ = LOW;

    last_voltage_change_time_ = 0;
    debounce_interval_ = 50; //ms
}

void ButtonDebounceFilter::begin(int button_pin) {
    button_pin_ = button_pin;
    pinMode(button_pin_, INPUT);
}

void ButtonDebounceFilter::monitorButtonState() {
    reading_ = digitalRead(button_pin_);

    if (reading_ != last_voltage_state_) {
        last_voltage_change_time_ = millis();
    }
}

void ButtonDebounceFilter::updateButtonState() {
    reading_ = digitalRead(button_pin_);

    last_voltage_state_ = reading_;

}

void ButtonDebounceFilter::isReliableHighLow(bool &is_high, bool &is_low) {
    is_high = false;
    is_low  = false;

    if (millis() - last_voltage_change_time_ > debounce_interval_) {

        if (reading_ != button_state_) {
            button_state_ = reading_;

            if (button_state_ == HIGH) {
                is_high = true;
            }

            if (button_state_ == LOW) {
                is_low = true;
            }
        }
    }

}


void ButtonDebounceFilter::setDebounceInterval(int interval) {
  debounce_interval_ = interval;
}

