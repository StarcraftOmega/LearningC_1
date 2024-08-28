#include <Arduino.h>
#include <IRremote.h>

const int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

const int MAX_CODES = 100;  // Maximum number of IR codes to store
unsigned long myList[MAX_CODES];  // Array to store IR codes
int codeIndex = 0;  // Current index in the array

int loopA = 0; // To start and stop the loop
unsigned long lastToggleTime = 0; // Time of the last toggle
unsigned long debounceDelay = 1000; // 1 second debounce delay

void setup(){
  Serial.begin(9600);  // Start serial communication at 9600 baud
  irrecv.enableIRIn(); // Enable the IR receiver
}

bool isDuplicate(unsigned long code) {
  for (int i = 0; i < codeIndex; i++) {
    if (myList[i] == code) {
      return true; // Code is already in the list
    }
  }
  return false;
}

void loop(){
  if (irrecv.decode(&results)) {
    unsigned long currentTime = millis();

    if (results.value == 0xE0E040BF && currentTime - lastToggleTime > debounceDelay) {
      // Debounced toggle
      loopA = !loopA;
      lastToggleTime = currentTime;

      if (loopA == 1) {
        Serial.println("Loop started");
      } else {
        Serial.println("Loop stopped");

        // Print the stored values
        for (int i = 0; i < codeIndex; i++) {
          Serial.print(myList[i], HEX); 
          Serial.print(" "); 
        }
        Serial.println();
        codeIndex = 0; // Reset the index for future use
      }
    }

    if (loopA == 1) { // Inside the loop
      // Save any IR value starting with 0xE0E0, if space is available and it's not a duplicate
      if ((results.value & 0xFFFF0000) == 0xE0E00000 && codeIndex < MAX_CODES) {
        if (!isDuplicate(results.value)) {
          myList[codeIndex] = results.value;
          Serial.print("Saved value: ");
          Serial.println(results.value, HEX);
          codeIndex++;
        }
      }
    }

    irrecv.resume(); // Receive the next value
  }
}
