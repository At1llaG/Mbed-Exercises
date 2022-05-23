#include "mbed.h"
 
InterruptIn button(p5);
DigitalOut led(LED1);
DigitalOut flash(LED4);
 
void flip() {
    led = !led;
}
 
int main() {
    button.rise(&flip);  // attach the address of the flip function to the rising edge
    while(1) {           // wait around, interrupts will interrupt this!
        flash = !flash;
        wait(0.25);
    }
}