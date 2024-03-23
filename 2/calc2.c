#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void add() {
    float a, b;
    printf("Enter two numbers to add: ");
    scanf("%f %f", &a, &b);
    printf("Result: %f\n", a + b);
}
void sub() {
    float a, b;
    printf("Enter two numbers to subtract: ");
    scanf("%f %f", &a, &b);
    printf("Result: %f\n", a - b);
}
void mul() {
    float a, b;
    printf("Enter two numbers to multiply: ");
    scanf("%f %f", &a, &b);
    printf("Result: %f\n", a * b);
}
void divi() {
    float a, b;
    printf("Enter two numbers to divide: ");
    scanf("%f %f", &a, &b);
    if (b != 0) {
        printf("Result: %f\n", a / b);
    } else {
        printf("Error!\n");
    }
}
int main() {
    void (*commands[])(void) = {add, sub, mul, divi};
    char command[20];
    while (1) {
        printf("Input command: add, sub, mul, divi\n");
        printf("Command: ");
        scanf("%s", command);
        int commandFound = 0;
        for (int i = 0; i < 4; i++) {
            if (strcmp(command, (i == 0 ? "add" : (i == 1 ? "sub" : (i == 2 ? "mul" : "divi"))) ) == 0) {
                commands[i]();
                commandFound = 1;
                break;
            }
        }
        if (!commandFound) {
            printf("Error!\n");
        }
    }
    return 0;
}
