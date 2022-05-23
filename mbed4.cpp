#include "mbed.h"

Ticker flipper;

//DigitalOut red_led(p5);
//DigitalOut blue_led(p6);

DigitalOut led1(LED1);
DigitalOut led2(LED2);

InterruptIn button_1(p7);
//InterruptIn button_2(p8);

int button_press=0;
//int red_controll=0;

void flip() {
    led2 = !led2;
}

void inc_redcontroll(){
    red_controll++;
    printf("red=%d\n",red_controll);
    if(red_controll==6){
       red_led=!red_led;
       wait_ms(200);
       red_controll=0;
   }
}

int main() {
    led2 = 1;
    
   button_1.fall(callback(&inc_redcontroll));
   
   flipper.attach(&flip, 2.0); // the address of the function to be attached (flip) and the interval (2 seconds)
   
   
   //button_2.fall(callback(&inc_bluecontroll));
   wait_ms(osWaitForever);
   
   
    //flipper.attach(&flip, 2.0); // the address of the function to be attached (flip) and the interval (2 seconds)
 
    // spin in a main loop. flipper will interrupt it to call flip
    //while(1) {
    //    led1 = !led1;
    //    wait(0.2);
    //}
    
    
}