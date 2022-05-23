#include "mbed.h"
 
DigitalOut myled(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);
 
InterruptIn pb(p8);
// SPST Pushbutton count demo using interrupts
// no external PullUp resistor needed
// Pushbutton from P8 to GND.
// A pb falling edge (hit) generates an interrupt and activates the interrupt routine
 
// Global count variable
int volatile count=0;
 
// pb Interrupt routine - is interrupt activated by a falling edge of pb input
void pb_hit_interrupt (void) {
    count++;
    myled4 = count & 0x01;
    myled3 = (count & 0x02)>>1;
    myled2 = (count & 0x04)>>2;
}
 
int main() {
    // Use internal pullup for pushbutton
    pb.mode(PullUp);
    // Delay for initial pullup to take effect
    wait(.01);
    // Attach the address of the interrupt handler routine for pushbutton
    pb.fall(&pb_hit_interrupt);
    // Blink myled in main routine forever while responding to pb changes
    // via interrupts that activate pb_hit_interrupt routine
    while (1) {
        myled = !myled;
        wait(.5);
    }
}
 