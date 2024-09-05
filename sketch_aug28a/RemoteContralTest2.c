#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void sendKeyChar(char key) {
    keybd_event((BYTE)key, 0, 0, 0);         // Simulate a key press like 1,2,3 and a,b,c
    keybd_event((BYTE)key, 0, KEYEVENTF_KEYUP, 0); // Simulate a key release
}
void sendKeyValue(WORD key) {
    keybd_event((BYTE)key, 0, 0, 0);         // Simulate key press using value for things like f13,play,pause
    keybd_event((BYTE)key, 0, KEYEVENTF_KEYUP, 0); // Simulate key release
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
    double lastPowerPressTime = 0.0;
    double powerDelay = 2.0; // 2-second delay between "POWER" presses

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
            // Check for "POWER" command, ensuring 5 seconds between presses
            if (strcmp(szBuffer, "POWER") == 0 && currentTime - lastPowerPressTime >= powerDelay) {
                waitingForPower = false;  // Enter key input mode
                lastPowerPressTime = currentTime;
                printf("Entered key input mode\n");
            }
        } else {
            // In key input mode
            if (strcmp(szBuffer, "1") == 0) {
                sendKeyChar('1');  // Output keyboard key '1'
                printf("Key '1' sent\n");
            } else if (strcmp(szBuffer, "2") == 0) {
                sendKeyChar('2');  // Output keyboard key '2'
                printf("Key '2' sent\n");
            } else if (strcmp(szBuffer, "OK") == 0) {
                sendKeyValue(0x7E);  // press f13
                printf("Key 'f13' sent\n");
            } else if (strcmp(szBuffer, "PLAY") == 0) {
                sendKeyValue(0xB3); 
                printf("Pausing\n");
            } else if (strcmp(szBuffer, "A") == 0) {
                system("taskmgr");
                printf("Opening Task Manager\n");
            } else if (strcmp(szBuffer, "B") == 0) {
                const char *command = "\"E:\\My Appes\\Microsoft VS Code\\Code.exe\"";
                system(command);  // Launch the application
                printf("Launching Visual Studio Code...\n");
            } else if (strcmp(szBuffer, "REVERSE") == 0) {
                sendKeyValue(0xB1);
                printf("Skipping\n");
            } else if (strcmp(szBuffer, "FORWARD") == 0) {
                sendKeyValue(0xB0);
                printf("Skipping\n");
            } else if (strcmp(szBuffer, "LEFT") == 0) {
                sendKeyValue(0xAE);
                printf("Lowering Volume\n");
            } else if (strcmp(szBuffer, "RIGHT") == 0) {
                sendKeyValue(0xAF);
                printf("Raising Volume\n");
            }

            // Check if "POWER" was pressed again to exit key input mode
            if (strcmp(szBuffer, "POWER") == 0 && currentTime - lastPowerPressTime >= powerDelay) {
                waitingForPower = true;  // Exit key input mode
                lastPowerPressTime = currentTime;
                printf("Exited key input mode, waiting for 'POWER'\n");
            }
        }

        // Update the last input time
        lastInputTime = currentTime;
    }

    // Close the serial port
    CloseHandle(hSerial);

    return 0;
}
