// Sample main.cpp file. Blinks the built-in LED, sends messages out
// USART 1, 2, 3, USB and turns on PWM on pin 2.

#include <wirish/wirish.h>

#define PWM_PIN  2
#define LED_PIN  27 // PB0


void setup() {
    // Set up the LED to blink
    pinMode(LED_PIN, OUTPUT);

    // Turn on PWM on pin PWM_PIN
    pinMode(PWM_PIN, PWM);
    pwmWrite(PWM_PIN, 0x8000);

    // Send a message out USART1
    Serial1.begin(9600);
    Serial1.println("Hello world 1");
    
    // Send a message out USART2
    Serial2.begin(9600);
    Serial2.println("Hello world 2");
    
    // Send a message out USART3
    Serial3.begin(9600);
    Serial3.println("Hello world 3");

    // Send a message out the usb virtual serial port
    SerialUSB.begin();
    delay(1000); // wait a while for the the CDC to enumerate
    SerialUSB.println("Hello world USB"); 
}

void loop() {
    Serial1.println("loop serial 1");
    SerialUSB.println("loop USB");
    digitalWrite(LED_PIN, 0);
    delay(500);
    digitalWrite(LED_PIN, 1);
    delay(500);
}

// Force init to be called *first*, i.e. before static object allocation.
// Otherwise, statically allocated objects that need libmaple may fail.
__attribute__((constructor)) void premain() {
    init();
}

int main(void) {
    setup();

    while (true) {
        loop();
    }

    return 0;
}
