#include "mbed.h"

Ticker flipper;

//DigitalOut red_led(p5);
//DigitalOut blue_led(p6);

DigitalOut led1(LED1);
DigitalOut led2(LED2);

InterruptIn button_1(p7);

int button_press=0;
int ticker_count=0;

void ticker_void() {
    ticker_count++;
    led1 = !led1;
    printf("Button %d Ticker %d\n", button_press, ticker_count);
    if(ticker_count==4){
        ticker_count=0;
        button_press=0;
        led1=0;
        led2=0;
    }
}

void button_void(){
    button_press++;
    //printf("Button %d\n",button_press);
    if(button_press==4){
       // printf("LED2 OUTPUT TOGGLED\n");
       led2=!led2;
   }
}

int main() {
   button_1.fall(callback(&button_void));
   flipper.attach(&ticker_void, 0.5);

}
