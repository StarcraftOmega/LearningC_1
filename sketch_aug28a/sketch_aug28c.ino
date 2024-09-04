#include <Arduino.h>
#include <IRremote.h>
#include <SerialTransfer.h>

// Define sensor pin
const int RECV_PIN = 4;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

// Initialize SerialTransfer object
SerialTransfer myTransfer;

void setup() {
    Serial.begin(9600);  // Initialize serial communication
    irrecv.enableIRIn(); // Start the receiver
    myTransfer.begin(Serial); // Initialize SerialTransfer
}

void loop() {
    if (irrecv.decode(&results)) {
        sendCommand(results.value);  // Send the received IR code over serial
        irrecv.resume();             // Receive the next value
    }
}

void sendCommand(unsigned long id) {
    char buffer[16]; // Buffer to store the command string
    int length = 0;

    switch(id) {
        case 0xE0E040BF: // power
            strcpy(buffer, "POWER");
            length = strlen(buffer);
            break;
        case 0xE0E048B7: // up
            strcpy(buffer, "UP");
            length = strlen(buffer);
            break;
        case 0xE0E0D02F: // left
            strcpy(buffer, "LEFT");
            length = strlen(buffer);
            break;
        case 0xE0E0F00F: // ok/middle
            strcpy(buffer, "OK");
            length = strlen(buffer);
            break;
        case 0xE0E0E01F: // right
            strcpy(buffer, "RIGHT");
            length = strlen(buffer);
            break;
        case 0xE0E0F807: // menu
            strcpy(buffer, "MENU");
            length = strlen(buffer);
            break;
        case 0xE0E008F7: // down
            strcpy(buffer, "DOWN");
            length = strlen(buffer);
            break;
        case 0xE0E0C837: // back/exit
            strcpy(buffer, "BACK");
            length = strlen(buffer);
            break;
        case 0xE0E0A857: // A
            strcpy(buffer, "A");
            length = strlen(buffer);
            break;
        case 0xE0E06897: // B
            strcpy(buffer, "B");
            length = strlen(buffer);
            break;
        case 0xE0E036C9: // C
            strcpy(buffer, "C");
            length = strlen(buffer);
            break;
        case 0xE0E028D7: // D
            strcpy(buffer, "D");
            length = strlen(buffer);
            break;
        case 0xE0E0A25D: // reverse
            strcpy(buffer, "REVERSE");
            length = strlen(buffer);
            break;
        case 0xE0E0E21D: // play
            strcpy(buffer, "PLAY");
            length = strlen(buffer);
            break;
        case 0xE0E012ED: // forward
            strcpy(buffer, "FORWARD");
            length = strlen(buffer);
            break;
        case 0xE0E0926D: // record
            strcpy(buffer, "RECORD");
            length = strlen(buffer);
            break;
        case 0xE0E0629D: // stop
            strcpy(buffer, "STOP");
            length = strlen(buffer);
            break;
        case 0xE0E052AD: // pause
            strcpy(buffer, "PAUSE");
            length = strlen(buffer);
            break;
        case 0xE0E020DF: // 1
            strcpy(buffer, "1");
            length = strlen(buffer);
            break;
        case 0xE0E0A05F: // 2
            strcpy(buffer, "2");
            length = strlen(buffer);
            break;
        case 0xE0E0609F: // 3
            strcpy(buffer, "3");
            length = strlen(buffer);
            break;
        case 0xE0E010EF: // 4
            strcpy(buffer, "4");
            length = strlen(buffer);
            break;
        case 0xE0E0906F: // 5
            strcpy(buffer, "5");
            length = strlen(buffer);
            break;
        case 0xE0E050AF: // 6
            strcpy(buffer, "6");
            length = strlen(buffer);
            break;
        case 0xE0E030CF: // 7
            strcpy(buffer, "7");
            length = strlen(buffer);
            break;
        case 0xE0E0B04F: // 8
            strcpy(buffer, "8");
            length = strlen(buffer);
            break;
        case 0xE0E0708F: // 9
            strcpy(buffer, "9");
            length = strlen(buffer);
            break;
        case 0xE0E0C43B: // Dot
            strcpy(buffer, "DOT");
            length = strlen(buffer);
            break;
        case 0xE0E08877: // 0
            strcpy(buffer, "0");
            length = strlen(buffer);
            break;
        case 0xE0E016E9: // enter
            strcpy(buffer, "ENTER");
            length = strlen(buffer);
            break;
        default:
            strcpy(buffer, "UNKNOWN");
            length = strlen(buffer);
            break;
    }
    
    // Send the command string via SerialTransfer
    myTransfer.txObj(buffer, length);
    myTransfer.sendData();
}
