#include <windows.h>
#include <stdio.h>
#include <string.h>

int main() {
    HANDLE hSerial;                      // Handle for the serial port
    DCB dcbSerialParams = {0};           // Device Control Block (DCB) to configure serial settings
    COMMTIMEOUTS timeouts = {0};         // Timeouts structure for read/write operations
    char szBuffer[100];                  // Buffer to store the received data
    DWORD bytesRead;                     // Number of bytes read from the COM port
    int length;                          // Length of the received string

    // Open COM4 for reading and writing
    hSerial = CreateFile(
        "\\\\.\\COM4",                  // Path to the COM4 port
        GENERIC_READ | GENERIC_WRITE,   // Allow both read and write operations
        0,                              // No sharing
        NULL,                           // No security attributes
        OPEN_EXISTING,                  // Open existing port
        0,                              // Non-overlapped I/O
        NULL);                          // No template file

    // Check if the serial port opened successfully
    if (hSerial == INVALID_HANDLE_VALUE) {
        printf("Error opening COM4\n");
        return 1;
    }

    // Initialize the DCB structure and get the current serial port settings
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        printf("Error getting state\n");
        return 1;
    }

    // Set the serial port parameters
    dcbSerialParams.BaudRate = CBR_9600;  // Set baud rate to 9600
    dcbSerialParams.ByteSize = 8;         // Set byte size to 8 bits
    dcbSerialParams.StopBits = ONESTOPBIT; // Use one stop bit
    dcbSerialParams.Parity   = NOPARITY;  // No parity bit

    // Apply the serial port settings
    if (!SetCommState(hSerial, &dcbSerialParams)) {
        printf("Error setting state\n");
        return 1;
    }

    // Set timeouts for serial communication
    timeouts.ReadIntervalTimeout         = 50;   // Maximum time between two characters
    timeouts.ReadTotalTimeoutConstant    = 50;   // Constant time-out for read operations
    timeouts.ReadTotalTimeoutMultiplier  = 10;   // Multiplier for total time-out for read operations
    timeouts.WriteTotalTimeoutConstant   = 50;   // Constant time-out for write operations
    timeouts.WriteTotalTimeoutMultiplier = 10;   // Multiplier for total time-out for write operations

    // Apply the timeout settings
    if (!SetCommTimeouts(hSerial, &timeouts)) {
        printf("Error setting timeouts\n");
        return 1;
    }

    // Read data from the serial port
    if (!ReadFile(hSerial, szBuffer, sizeof(szBuffer) - 1, &bytesRead, NULL)) {
        printf("Error reading from COM4\n");
        return 1;
    }

    // Null-terminate the received string
    szBuffer[bytesRead] = '\0';

    // Calculate the length of the received string
    length = strlen(szBuffer);

    // Print the received string and its length
    printf("Received string: %s\n", szBuffer);
    printf("String length: %d\n", length);

    // Close the serial port
    CloseHandle(hSerial);

    return 0;
}
