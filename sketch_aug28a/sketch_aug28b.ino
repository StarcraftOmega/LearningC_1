/*
Keyboard.write(65);         // sends ASCII value 65, or A
Keyboard.write('A');            // same thing as a quoted character
*/
#include <Arduino.h>
#include <Keyboard.h>
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 4;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

// Function to handle hotkeys based on received ID
void hotkey(unsigned long id) {
    switch(id) {
        case 0xE0E040BF: // power
            // ctrl + alt + delete
            break;
        case 0xE0E048B7: // up
            // Command for up
            break;
        case 0xE0E0D02F: // left
            // Command for left
            break;
        case 0xE0E0F00F: // ok/middle
            // Command for ok/middle
            break;
        case 0xE0E0E01F: // right
            // Command for right
            break;
        case 0xE0E0F807: // ?/menu
            // Command for ?/menu
            break;
        case 0xE0E008F7: // down
            // Command for down
            break;
        case 0xE0E0C837: // back/exit
            // Command for back/exit
            break;
        case 0xE0E0A857: // A
            // Command for A
            break;
        case 0xE0E06897: // B
            // Command for B
            break;
        case 0xE0E036C9: // C
            // Command for C
            break;
        case 0xE0E028D7: // D
            // Command for D
            break;
        case 0xE0E0A25D: // reverse
            // Command for reverse
            break;
        case 0xE0E0E21D: // play
            // Command for play
            break;
        case 0xE0E012ED: // forward
            // Command for forward
            break;
        case 0xE0E0926D: // record
            // Command for record
            break;
        case 0xE0E0629D: // stop
            // Command for stop
            break;
        case 0xE0E052AD: // pause
            // Command for pause
            break;
        case 0xE0E020DF: // 1
            // Command for 1
            break;
        case 0xE0E0A05F: // 2
            // Command for 2
            break;
        case 0xE0E0609F: // 3
            // Command for 3
            break;
        case 0xE0E010EF: // 4
            // Command for 4
            break;
        case 0xE0E0906F: // 5
            // Command for 5
            break;
        case 0xE0E050AF: // 6
            // Command for 6
            break;
        case 0xE0E030CF: // 7
            // Command for 7
            break;
        case 0xE0E0B04F: // 8
            // Command for 8
            break;
        case 0xE0E0708F: // 9
            // Command for 9
            break;
        case 0xE0E0C43B: // Dot
            // Command for Dot
            break;
        case 0xE0E08877: // 0
            // Command for 0
            break;
        case 0xE0E016E9: // enter
            // Command for enter
            break;
        default:
            // Unknown ID
            break;
    }
}

void setup() {
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop() {
    if (irrecv.decode(&results)) {
        hotkey(results.value);  // Pass the received IR code to hotkey
        irrecv.resume();        // Receive the next value
    }
}
