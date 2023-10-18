/* 
 * File:   application.c
 * Author: AyaAli
 * Created on September 22, 2023, 10:24 AM
 */
#include "application.h"

led_t led_1 = {
.Port_Name = PORTC_INDEX,
.pin = PIN0,
.led_statues = LED_OFF,
};

button_t btn_high= {
.button_pin.port = PORTD_INDEX,
.button_pin.pin = PIN0,
.button_pin.direction = Input,
.button_pin.logic = LOW,
.button_connection = BUTTON_ACTIVE_HIGH,
.button_state= BUTTON_RELEASED,
};

led_t led_2= {
.Port_Name = PORTC_INDEX,
.pin = PIN1,
.led_statues = LED_OFF,
};

button_t btn_low= {
.button_pin.port = PORTD_INDEX,
.button_pin.pin = PIN1,
.button_pin.direction = Input,
.button_pin.logic = LOW,
.button_connection = BUTTON_ACTIVE_LOW,
.button_state= BUTTON_RELEASED,
};



button_state_t btn_high_st = BUTTON_RELEASED;
button_state_t btn_low_st = BUTTON_RELEASED;

int main() {
    
Std_ReturnType ret = E_NOT_OK;
application_initialize();


while(1){
  
ret = Button_Read_State(&btn_high,&btn_high_st);
ret = Button_Read_State(&btn_low,&btn_low_st);

if(btn_high_st == BUTTON_PRESSED){
    led_turn_on(&led_1);
}
else {
led_turn_off(&led_1);
}
if(btn_low_st == BUTTON_PRESSED){
    led_turn_on(&led_2);
}
else {
led_turn_off(&led_2);
}
  }
  return (EXIT_SUCCESS);
}
void application_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
ret = Button_Initialize(&btn_high);
ret = Button_Initialize(&btn_low);

ret = led_initialize(&led_1);
ret = led_initialize(&led_2);

}