#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void sendKey(char key) {
    // Simulate a key press
    keybd_event((BYTE)key, 0, 0, 0);
    // Simulate a key release
    keybd_event((BYTE)key, 0, KEYEVENTF_KEYUP, 0);
}
void simulateVolumeDown() {
    keybd_event(VK_VOLUME_DOWN, 0, 0, 0);         // Press Volume Down key
    keybd_event(VK_VOLUME_DOWN, 0, KEYEVENTF_KEYUP, 0);  // Release Volume Down key
}
void simulateVolumeUp() {
    keybd_event(VK_VOLUME_UP, 0, 0, 0);  // Press Volume Up key
    keybd_event(VK_VOLUME_UP, 0, KEYEVENTF_KEYUP, 0);  // Release Volume Up key
}

bool readSerial(HANDLE hSerial, char* szBuffer, DWORD bufferSize) {
    DWORD bytesRead;
    if (!ReadFile(hSerial, szBuffer, bufferSize - 1, &bytesRead, NULL)) {
        printf("Error reading from COM4\n");
        return false;
    }
    szBuffer[bytesRead] = '\0';  // Null-terminate the string
    return true;
}

double getTimeInSeconds() {
    return (double)clock() / CLOCKS_PER_SEC;
}

int main() {
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};
    char szBuffer[100];
    bool waitingForPower = true;
    double lastInputTime = 0.0;
    double delay = 0.2;  // 0.2 seconds delay between inputs
    double delayB=.8; //delay between power press

    // Open COM4
    hSerial = CreateFile("\\\\.\\COM4", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hSerial == INVALID_HANDLE_VALUE) {
        printf("Error opening COM4\n");
        return 1;
    }

    // Set serial port parameters
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        printf("Error getting state\n");
        return 1;
    }
    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity   = NOPARITY;
    if (!SetCommState(hSerial, &dcbSerialParams)) {
        printf("Error setting state\n");
        return 1;
    }

    // Set timeouts
    timeouts.ReadIntervalTimeout         = 50;
    timeouts.ReadTotalTimeoutConstant    = 50;
    timeouts.ReadTotalTimeoutMultiplier  = 10;
    timeouts.WriteTotalTimeoutConstant   = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;
    if (!SetCommTimeouts(hSerial, &timeouts)) {
        printf("Error setting timeouts\n");
        return 1;
    }

    while (1) {
        printf("Waiting for input...\n");  // Output message indicating the program is running

        // Read data from the serial port
        if (!readSerial(hSerial, szBuffer, sizeof(szBuffer))) {
            continue;
        }

        // Trim newline characters from the input
        szBuffer[strcspn(szBuffer, "\r\n")] = 0;

        // Check the time elapsed since the last input
        double currentTime = getTimeInSeconds();
        if (currentTime - lastInputTime < delay) {
            continue;  // Skip input if it hasn't been 0.2 seconds
        }

        if (waitingForPower) {
            if (currentTime-lastInputTime > delayB){
                // Check for "POWER" command to toggle state
                if (strcmp(szBuffer, "POWER") == 0) {
                    waitingForPower = false;  // Toggle to waiting for keys
                    printf("Entered key input mode\n");
                }
            }
        } else {
            // In key input mode
            if (strcmp(szBuffer, "1") == 0) {
                sendKey('1');  // Output keyboard key '1'
                printf("Key '1' sent\n");
            } else if (strcmp(szBuffer, "2") == 0) {
                sendKey('2');  // Output keyboard key '2'
                printf("Key '2' sent\n");
            } else if (strcmp(szBuffer, "3") == 0) {
                sendKey('3');  // Output keyboard key '3'
                printf("Key '3' sent\n");
            } else if (strcmp(szBuffer, "5") == 0) {
                system("taskmgr");
                printf("OpeningTasManger\n");
            }else if (strcmp(szBuffer, "LEFT") == 0) {
                simulateVolumeDown();
                printf("Lowering Volume\n");
            }else if (strcmp(szBuffer, "RIGHT") == 0) {
                simulateVolumeUp();
                printf("Raising Volume\n");
            }else if (strcmp(szBuffer, "POWER") == 0) {
                waitingForPower = true;  // Toggle back to waiting for "POWER"
                printf("Exited key input mode, waiting for 'POWER'\n");
            }

            // Update the last input time
            lastInputTime = currentTime;
        }
    }

    // Close the serial port11132322222212121122
    CloseHandle(hSerial);

    return 0;
}
