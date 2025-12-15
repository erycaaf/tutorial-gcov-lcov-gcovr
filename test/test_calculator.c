#include "../src/calculator.h"
#include <assert.h>
#include <stdio.h>
#include <math.h>

int main() {

    assert(add(2, 3) == 5);
    assert(add(-2, 3) == 1);
    assert(add(0, 0) == 0);

    assert(subtract(5, 3) == 2);
    assert(subtract(3, 5) == -2);
    assert(subtract(0, 5) == -5);

    assert(multiply(4, 2) == 8);
    assert(multiply(-4, 2) == -8);
    assert(multiply(0, 100) == 0);

    assert(division(10, 2) == 5.0);
    assert(division(-10, 2) == -5.0);
    assert(division(1, 2) == 0.5);
    assert(isnan(division(1, 0)));

    assert(modulo(10, 3) == 1);
    assert(modulo(9, 3) == 0);
    assert(modulo(-10, 3) == -1);

    assert(absolute(10) == 10);
    assert(absolute(-10) == 10);
    assert(absolute(0) == 0);

    assert(power(2, 0) == 1);
    assert(power(2, 3) == 8);
    assert(power(5, 1) == 5);

    assert(average(10, 20) == 15.0);
    assert(average(1, 2) == 1.5);
    assert(average(-2, 2) == 0.0);

    assert(is_even(2) == 1);
    assert(is_even(3) == 0);
    assert(is_even(0) == 1);
    assert(is_even(-4) == 1);

    printf("Todos os testes passaram com sucesso!\n");
    return 0;
}