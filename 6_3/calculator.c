//calculator.c
//gcc -shared -o libcalculator.so libcalculator.c
//gcc -o calculator calculator.c -ldl
//./calculator
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void *handle;
    int (*add)(int, int);
    int (*subtract)(int, int);
    int (*multiply)(int, int);
    int (*divide)(int, int);

    handle = dlopen("./libcalculator.so", RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    add = dlsym(handle, "add");
    subtract = dlsym(handle, "subtract");
    multiply = dlsym(handle, "multiply");
    divide = dlsym(handle, "divide");

    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Sum: %d\n", add(a, b));
    printf("Sub: %d\n", subtract(a, b));
    printf("Mul: %d\n", multiply(a, b));
    printf("Div: %d\n", divide(a, b));

    dlclose(handle);

    return 0;
}

