#ifndef _BUTTON_DEBOUNCE_FILTER
#define _BUTTON_DEBOUNCE_FILTER

#include <Arduino.h>

/*
 * @author: shixudong
 * @since:  2017-09-14
 *
 * ButtonDebounceFilter encapulate function to handle reliable button push  */

class ButtonDebounceFilter {
    public:
        ButtonDebounceFilter();
        void begin(int button_pin);
        void monitorButtonState();
        void updateButtonState();
        void isReliableHighLow(bool &is_high, bool &is_low);
        void setDebounceInterval(int interval);

    private:
        int button_pin_;
        int button_state_;

        int last_voltage_state_;
        int last_voltage_change_time_;

        int debounce_interval_;

        int reading_;
};


#endif
