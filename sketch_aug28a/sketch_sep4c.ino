#include <Arduino.h>
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
    Serial.begin(9600);  // Initialize serial communication at 9600 baud
    irrecv.enableIRIn(); // Start the receiver
}

void loop() {
    if (irrecv.decode(&results)) {
        sendCommand(results.value);  // Send the received IR code over serial
        irrecv.resume();             // Receive the next value
    }
}

void sendCommand(unsigned long id) {
    switch(id) {
        case 0xE0E040BF: // power
            Serial.println("POWER");
            break;
        case 0xE0E048B7: // up
            Serial.println("UP");
            break;
        case 0xE0E0D02F: // left
            Serial.println("LEFT");
            break;
        case 0xE0E0F00F: // ok/middle
            Serial.println("OK");
            break;
        case 0xE0E0E01F: // right
            Serial.println("RIGHT");
            break;
        case 0xE0E0F807: // menu
            Serial.println("MENU");
            break;
        case 0xE0E008F7: // down
            Serial.println("DOWN");
            break;
        case 0xE0E0C837: // back/exit
            Serial.println("BACK");
            break;
        case 0xE0E0A857: // A
            Serial.println("A");
            break;
        case 0xE0E06897: // B
            Serial.println("B");
            break;
        case 0xE0E036C9: // C
            Serial.println("C");
            break;
        case 0xE0E028D7: // D
            Serial.println("D");
            break;
        case 0xE0E0A25D: // reverse
            Serial.println("REVERSE");
            break;
        case 0xE0E0E21D: // play
            Serial.println("PLAY");
            break;
        case 0xE0E012ED: // forward
            Serial.println("FORWARD");
            break;
        case 0xE0E0926D: // record
            Serial.println("RECORD");
            break;
        case 0xE0E0629D: // stop
            Serial.println("STOP");
            break;
        case 0xE0E052AD: // pause
            Serial.println("PAUSE");
            break;
        case 0xE0E020DF: // 1
            Serial.println("1");
            break;
        case 0xE0E0A05F: // 2
            Serial.println("2");
            break;
        case 0xE0E0609F: // 3
            Serial.println("3");
            break;
        case 0xE0E010EF: // 4
            Serial.println("4");
            break;
        case 0xE0E0906F: // 5
            Serial.println("5");
            break;
        case 0xE0E050AF: // 6
            Serial.println("6");
            break;
        case 0xE0E030CF: // 7
            Serial.println("7");
            break;
        case 0xE0E0B04F: // 8
            Serial.println("8");
            break;
        case 0xE0E0708F: // 9
            Serial.println("9");
            break;
        case 0xE0E0C43B: // Dot
            Serial.println("DOT");
            break;
        case 0xE0E08877: // 0
            Serial.println("0");
            break;
        case 0xE0E016E9: // enter
            Serial.println("ENTER");
            break;
        default:
            Serial.println("UNKNOWN");
            break;
    }
}
