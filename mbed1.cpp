#include "mbed.h"

DigitalOut myled1(p5);
DigitalOut myled2(p6);

DigitalIn pb1(p8);
DigitalIn pb2(p9);


int main() {
    
    int count1 = 0;
    int old_pb1 =0;
    int new_pb1 = 1;
    bool led1 = false;

    int count2 = 0;
    int old_pb2 = 0;
    int new_pb2 = 1;
    bool led2 = false;
    
    pb1.mode(PullUp);
    wait_ms(1);
    while(1) {
        
        new_pb1 = pb1;
        if ((new_pb1==0) && (old_pb1==1))
        {
            count1++;
            wait_ms(1);
            if(count1%4==0) led1 = !led1;
        }
        
        new_pb2 = pb2;
        if ((new_pb2==0) && (old_pb2==1))
        {
            count2++;
            wait_ms(1);
            if(count2%6==0) led2 = !led2;
        }
        
        printf("count1 = %d\n count2 = %d\n", count1, count2);
        wait_ms(1);
        
        //if(count1%4==0 && old_pb1 != new_pb1) led1 = !led1;
        //    //myled1 = pb1;
        
        //if(count2%6==0 && old_pb2 != new_pb2) led2 = !led2;
        
        myled1 = led1;
        myled2 = led2;
        //myled2 = pb2;
        
        //printf("%d", pb1);
        wait(0.2);
        
        
        old_pb1 = new_pb1;
        old_pb2 = new_pb2;
    }
}