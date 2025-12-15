#include "calculator.h"
#include "unity.h"
#include <math.h>
#include <errno.h>


void setUp(void) {}
void tearDown(void) {}


void test_add(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(1, add(-2, 3));
}

void test_subtract(void) {
    TEST_ASSERT_EQUAL(2, subtract(5, 3));
    TEST_ASSERT_EQUAL(-2, subtract(3, 5));
}

void test_multiply(void) {
    TEST_ASSERT_EQUAL(8, multiply(4, 2));
    TEST_ASSERT_EQUAL(-8, multiply(-4, 2));
}

void test_division_normal(void) {
    TEST_ASSERT_EQUAL_DOUBLE(5.0, division(10, 2));
    TEST_ASSERT_EQUAL_DOUBLE(0.5, division(1, 2));
}

void test_division_by_zero_nan(void) {
    errno = 0;
    double r = division(10, 0);

    TEST_ASSERT_TRUE(isnan(r));
    TEST_ASSERT_EQUAL(EDOM, errno);
}

void test_is_even(void) {
    TEST_ASSERT_TRUE(is_even(2));
    TEST_ASSERT_FALSE(is_even(3));
    TEST_ASSERT_TRUE(is_even(0));
}

void test_module(void) {
    TEST_ASSERT_EQUAL(1, modulo(5,2));
}

void test_absolute(void) {
    TEST_ASSERT_EQUAL(1,absolute(-1));
}

void test_power(void){
    TEST_ASSERT_EQUAL(4,power(2,2));
}

void test_average(void){
    TEST_ASSERT_EQUAL(15,average(10,20));
}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_add);
    RUN_TEST(test_subtract);
    RUN_TEST(test_multiply);
    RUN_TEST(test_division_normal);
    RUN_TEST(test_division_by_zero_nan);
    RUN_TEST(test_is_even);
    RUN_TEST(test_module);
    RUN_TEST(test_absolute);
    RUN_TEST(test_power);
    RUN_TEST(test_average);

    return UNITY_END();
}
