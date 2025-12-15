#include "calculator.h"
#include <errno.h>
#include <math.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double division(int a, int b) {
    if (b == 0) {
        errno = EDOM;
        return NAN;
    }
    return (double)a / b;
}

int modulo(int a, int b) {
    return a % b;
}

int absolute(int a) {
    return (a < 0) ? -a : a;
}

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double average(int a, int b) {
    return (double)(a + b) / 2;
}

int is_even(int a) {
    return (a % 2 == 0);
}
