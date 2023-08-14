/*
    จงแปลงเลขฐาน 16 ที่รับมาจากผู้ใช้ให้กลายเป็นเลขฐาน 2
    
    Test case:
        User input :
            FB
    Output:
        11111011

    Test case:
        User input :
            19
    Output:
        11001
*/
#include <stdio.h>
#include <string.h>

int hexDigitToBinary(char hexDigit) {
    if (hexDigit >= '0' && hexDigit <= '9') {
        return hexDigit - '0';
    } else if (hexDigit >= 'A' && hexDigit <= 'F') {
        return hexDigit - 'A' + 10;
    } else if (hexDigit >= 'a' && hexDigit <= 'f') {
        return hexDigit - 'a' + 10;
    }
    return -1;
}

void hexToBinary(const char *hexString, char *binaryResult) {
    int length = strlen(hexString);
    for (int i = 0; i < length; i++) {
        int digitValue = hexDigitToBinary(hexString[i]);
        if (digitValue >= 0) {
            for (int j = 3; j >= 0; j--) {
                binaryResult[i * 4 + (3 - j)] = (digitValue >> j) & 1 ? '1' : '0';
            }
        } else {
            // Invalid hex digit
            binaryResult[0] = '\0';
            return;
        }
    }
    binaryResult[length * 4] = '\0';
}

int main() {
    char hexString[16];
    char binaryResult[65]; // To hold 16 hex digits * 4 bits/digit + null terminator

    printf("User input :\n");
    scanf("%s", hexString);

    hexToBinary(hexString, binaryResult);

    if (binaryResult[0] != '\0') {
        printf("Output:\n");
        printf("%s\n", binaryResult);
    } else {
        printf("Invalid input\n");
    }

    return 0;
}