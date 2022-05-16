#include <check.h>
#include <stdlib.h>

#include "s21_math.h"

// 1
START_TEST(s21_abs_Test) {
    ck_assert_int_eq(s21_abs(-2), abs(-2));
    ck_assert_int_eq(s21_abs(-5), abs(-5));
    ck_assert_int_eq(s21_abs(5), abs(5));
    ck_assert_int_eq(s21_abs(5), abs(5));
    ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN));
    ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
    ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

// 2
START_TEST(s21_acos_Test) {
    // Доработать s21_acos
    double num = 0.55;
    long double orig_res = acos(num), our_res = s21_acos(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -0.99;
    orig_res = acos(num), our_res = s21_acos(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    orig_res = acos(num), our_res = s21_acos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -INFINITY;
    orig_res = acos(num), our_res = s21_acos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = NAN;
    orig_res = s21_acos(num), our_res = acos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 3
START_TEST(s21_asin_Test) {
    // Доработать s21_asin
    double num = 0.55;
    long double orig_res = asin(num), our_res = s21_asin(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -0.99;
    orig_res = asin(num), our_res = s21_asin(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    orig_res = asin(num), our_res = s21_asin(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -INFINITY;
    orig_res = asin(num), our_res = s21_asin(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = NAN;
    orig_res = asin(num), our_res = s21_asin(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 4
START_TEST(s21_atan_Test) {
    // Доработать s21_atan
    ck_assert_float_eq(s21_atan(-15.01), atan(-15.01));

    double num = -0.99;
    long double orig_res = s21_atan(num), our_res = atan(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    ck_assert_float_eq(-9999999999, -9999999999);

    ck_assert_ldouble_eq(s21_atan(INFINITY), atan(INFINITY));
    ck_assert_ldouble_eq(s21_atan(-INFINITY), atan(-INFINITY));

    num = NAN;
    orig_res = s21_atan(num), our_res = atan(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 5
START_TEST(s21_ceil_Test) {
    // Доработать s21_ceil
    ck_assert_ldouble_eq(s21_ceil(-2.9), ceil(-2.9));
    ck_assert_ldouble_eq(s21_ceil(2.9), ceil(2.9));
    ck_assert_ldouble_eq(s21_ceil(-5.4), ceil(-5.4));
    ck_assert_ldouble_eq(s21_ceil(5), ceil(5));
    ck_assert_ldouble_eq(s21_ceil(0.0001), ceil(0.0001));
    ck_assert_ldouble_eq(s21_ceil(-0.0001), ceil(-0.0001));
    ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
    ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

// 6
START_TEST(s21_cos_Test) {
    // Доработать s21_cos
    double num = 0.55;
    long double orig_res = s21_cos(num), our_res = s21_cos(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -0.999999;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = 628;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    ck_assert_float_eq(s21_cos(0), cos(0));
    ck_assert_float_eq(s21_cos(-1), cos(-1));

    num = NAN;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -INFINITY;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 7
START_TEST(s21_exp_Test) {
    ck_assert_uint_eq(s21_exp(5), exp(5));
    ck_assert_uint_eq(s21_exp(-2), exp(-2));
    ck_assert_uint_eq(s21_exp(1234567), exp(1234567));
    ck_assert_uint_eq(s21_exp(-1234567), exp(-1234567));
    for (double i = -10; i < 10; i++) {
        ck_assert_uint_eq(s21_exp(i), exp(i));
    }
    double num = NAN;
    long double orig_res = exp(num), our_res = s21_exp(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    orig_res = exp(num), our_res = s21_exp(num);
    suc = 0;
    if (isinf(orig_res) && isinf(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -INFINITY;
    orig_res = exp(num), our_res = s21_exp(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 8
START_TEST(s21_fabs_Test) {
    ck_assert_ldouble_eq(s21_fabs(-2.), fabs(-2.));
    ck_assert_ldouble_eq(s21_fabs(-5.), fabs(-5.));
    ck_assert_ldouble_eq(s21_fabs(5.), fabs(5.));
    ck_assert_ldouble_eq(s21_fabs(5.0), fabs(5.0));
    ck_assert_ldouble_eq(s21_fabs(-15.01), fabs(-15.01));
    ck_assert_ldouble_eq(s21_fabs(INFINITY), fabs(INFINITY));
    ck_assert_ldouble_eq(s21_fabs(-INFINITY), fabs(-INFINITY));
}
END_TEST

// 9
START_TEST(s21_floor_Test) {
    // Доработать s21_fmod
    ck_assert_ldouble_eq(s21_floor(-2), floor(-2));
    ck_assert_ldouble_eq(s21_floor(-5), floor(-5));
    ck_assert_ldouble_eq(s21_floor(0.00005), floor(0.00005));
    ck_assert_ldouble_eq(s21_floor(-0.00005), floor(-0.00005));
    ck_assert_ldouble_eq(s21_floor(5.0), floor(5.0));
    ck_assert_ldouble_eq(s21_floor(2), floor(2));
    ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
    ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));

    double num = NAN;
    long double orig_res = floor(num), our_res = s21_floor(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 10
START_TEST(s21_fmod_Test) {
    // Доработать s21_fmod
    ck_assert_ldouble_eq_tol(s21_fmod(7, 3), fmod(7, 3), 1e-6);
    ck_assert_ldouble_eq_tol(s21_fmod(15.4, 5), fmod(15.4, 5), 1e-6);
    ck_assert_ldouble_eq_tol(s21_fmod(123456789, 54321), fmod(123456789, 54321),
                             1e-6);
    ck_assert_ldouble_eq_tol(s21_fmod(0, 5.0), fmod(0, 5.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_fmod(23, 2), fmod(23, 2), 1e-6);
    ck_assert_ldouble_eq_tol(s21_fmod(-23, 2), fmod(-23, 2), 1e-6);
    ck_assert_ldouble_eq_tol(s21_fmod(23, -2), fmod(23, -2), 1e-6);
    ck_assert_ldouble_eq_tol(s21_fmod(-23, -2), fmod(-23, -2), 1e-6);
    ck_assert_ldouble_eq_tol(s21_fmod(23, 1), fmod(23, 1), 1e-6);

    double num = NAN;
    long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = NAN;
    orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));

    num = INFINITY;
    orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    ck_assert_ldouble_eq(s21_fmod(2.0, -INFINITY), fmod(2.0, -INFINITY));

    num = -INFINITY;
    orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 11
START_TEST(s21_log_Test) {
    // Доработать s21_log
    double num = 456.789;
    long double orig_res = log(num), our_res = s21_log(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = NAN;
    orig_res = log(num);
    our_res = s21_log(num);
    suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = 0.001;
    orig_res = log(num);
    our_res = s21_log(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = 0.4;
    orig_res = log(num);
    our_res = s21_log(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -INFINITY;
    orig_res = log(num);
    our_res = s21_log(num);
    suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    orig_res = log(num);
    our_res = s21_log(num);
    suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 12
START_TEST(s21_pow_Test) {
    // s21_pow Доработать
    ck_assert_ldouble_eq_tol(s21_pow(3.0, 14.0), pow(3.0, 14.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(31.456, 4.3), pow(31.456, 4.3), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(31.456, 0.3), pow(31.456, 0.3), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(4.3, 4.3), pow(4.3, 4.3), 1e-6);
    ck_assert_ldouble_eq_tol(s21_pow(1234, -4.3), pow(1234, -4.3), 1e-6);

    double num = 456.789;
    double ex = 1.1;
    long double orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    int suc = 0;
    ck_assert_float_eq(our_res, orig_res);
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    ex = 1.1;
    orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = NAN;
    ex = 1.1;
    orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = NAN;
    ex = NAN;
    orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = 0.001;
    ex = NAN;
    orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    ex = INFINITY;
    orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    ex = INFINITY;
    orig_res = pow(num, ex), our_res = s21_pow(num, ex);
    suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 13
START_TEST(s21_sin_Test) {
    // s21_sin Доработать
    double num = 0.55;
    long double orig_res = s21_sin(num), our_res = s21_sin(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    ck_assert_float_eq(s21_sin(0), sin(0));

    num = 1;
    orig_res = s21_sin(num), our_res = s21_sin(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -1;
    orig_res = s21_sin(num), our_res = s21_sin(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = 0.999999;
    orig_res = s21_sin(num), our_res = s21_sin(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -0.999999;
    orig_res = s21_sin(num), our_res = s21_sin(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = NAN;
    orig_res = sin(num), our_res = s21_sin(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    orig_res = sin(num), our_res = s21_sin(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -INFINITY;
    orig_res = sin(num), our_res = s21_sin(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 14
START_TEST(s21_sqrt_Test) {
    // s21_sqrt Доработать
    ck_assert_ldouble_eq_tol(s21_sqrt(16.0), sqrt(16.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(45.35), sqrt(45.35), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(5.0), sqrt(5.0), 1e-6);
    for (double i = 0; i < 1; i += 0.001) {
        ck_assert_ldouble_eq_tol(s21_sqrt(i), sqrt(i), 1e-6);
    }

    double num = 0.55;
    long double orig_res = s21_cos(num), our_res = s21_cos(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -0.999999;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = 628;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    ck_assert_float_eq(s21_cos(0), cos(0));
    ck_assert_float_eq(s21_cos(-1), cos(-1));

    num = NAN;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -INFINITY;
    orig_res = cos(num), our_res = s21_cos(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

// 15
START_TEST(s21_tan_Test) {
    // Доработать s21_tan
    ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_tan(1234.123412432), tan(1234.123412432),
                             1e-6);
    ck_assert_ldouble_eq_tol(s21_tan(-1234.123412432), tan(-1234.1234124325234),
                             1e-6);
    ck_assert_ldouble_eq_tol(s21_tan(100000), tan(100000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_tan(-100000), tan(-100000), 1e-6);
    ck_assert_ldouble_eq_tol(s21_tan(1.123), tan(1.123), 1e-6);
    ck_assert_float_eq(s21_tan(-15.01), tan(-15.01));

    double num = 0.55;
    long double orig_res = s21_tan(num), our_res = s21_tan(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);

    ck_assert_float_eq(-9999999999, -9999999999);

    num = NAN;
    orig_res = tan(num), our_res = s21_tan(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = INFINITY;
    orig_res = tan(num), our_res = s21_tan(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);

    num = -INFINITY;
    orig_res = tan(num), our_res = s21_tan(num);
    suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

int main() {
    Suite *suite = suite_create("S21_Debuger");
    SRunner *srunner = srunner_create(suite);

    TCase *s21_abs_Case = tcase_create("s21_abs_Case");
    suite_add_tcase(suite, s21_abs_Case);
    tcase_add_test(s21_abs_Case, s21_abs_Test);

    TCase *s21_acos_Case = tcase_create("s21_acos_Case");
    suite_add_tcase(suite, s21_acos_Case);
    tcase_add_test(s21_acos_Case, s21_acos_Test);

    TCase *s21_asin_Case = tcase_create("s21_asin_Case");
    suite_add_tcase(suite, s21_asin_Case);
    tcase_add_test(s21_asin_Case, s21_asin_Test);

    TCase *s21_atan_Case = tcase_create("s21_atan_Case");
    suite_add_tcase(suite, s21_atan_Case);
    tcase_add_test(s21_atan_Case, s21_atan_Test);

    TCase *s21_ceil_Case = tcase_create("s21_ceil_Case");
    suite_add_tcase(suite, s21_ceil_Case);
    tcase_add_test(s21_ceil_Case, s21_ceil_Test);

    TCase *s21_cos_Case = tcase_create("s21_cos_Case");
    suite_add_tcase(suite, s21_cos_Case);
    tcase_add_test(s21_cos_Case, s21_cos_Test);

    TCase *s21_exp_Case = tcase_create("s21_exp_Case");
    suite_add_tcase(suite, s21_exp_Case);
    tcase_add_test(s21_exp_Case, s21_exp_Test);

    TCase *s21_fabs_Case = tcase_create("s21_fabs_Case");
    suite_add_tcase(suite, s21_fabs_Case);
    tcase_add_test(s21_fabs_Case, s21_fabs_Test);

    TCase *s21_floor_Case = tcase_create("s21_floor_Case");
    suite_add_tcase(suite, s21_floor_Case);
    tcase_add_test(s21_floor_Case, s21_floor_Test);

    TCase *s21_fmod_Case = tcase_create("s21_fmod_Case");
    suite_add_tcase(suite, s21_fmod_Case);
    tcase_add_test(s21_fmod_Case, s21_fmod_Test);

    TCase *s21_log_Case = tcase_create("s21_log_Case");
    suite_add_tcase(suite, s21_log_Case);
    tcase_add_test(s21_log_Case, s21_log_Test);

    TCase *s21_pow_Case = tcase_create("s21_pow_Case");
    suite_add_tcase(suite, s21_pow_Case);
    tcase_add_test(s21_pow_Case, s21_pow_Test);

    TCase *s21_sin_Case = tcase_create("s21_sin_Case");
    suite_add_tcase(suite, s21_sin_Case);
    tcase_add_test(s21_sin_Case, s21_sin_Test);

    TCase *s21_sqrt_Case = tcase_create("s21_sqrt_Case");
    suite_add_tcase(suite, s21_sqrt_Case);
    tcase_add_test(s21_sqrt_Case, s21_sqrt_Test);

    TCase *s21_tan_Case = tcase_create("s21_tan_Case");
    suite_add_tcase(suite, s21_tan_Case);
    tcase_add_test(s21_tan_Case, s21_tan_Test);

    srunner_run_all(srunner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
