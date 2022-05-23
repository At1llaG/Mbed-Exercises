#include "mbed.h"

DigitalOut red_led(p5);
DigitalOut blue_led(p6);

InterruptIn button_1(p7);
InterruptIn button_2(p8);

int blue_controll=0;
int red_controll=0;

void inc_redcontroll(){
    red_controll++;
    printf("red=%d\n",red_controll);
    if(red_controll==6){
       red_led=!red_led;
       wait_ms(200);
       red_controll=0;
   }
}

void inc_bluecontroll(){
    blue_controll++;
    printf("blue=%d\n",blue_controll);
    if(blue_controll==4){
       blue_led=!blue_led;
       wait_ms(200);
       blue_controll=0;
   }
}
int main() {
   button_1.fall(callback(&inc_redcontroll));
   button_2.fall(callback(&inc_bluecontroll));
   wait_ms(osWaitForever);
}