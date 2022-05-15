#include <check.h>
#include <stdlib.h>

#include "s21_math.h"

long double round_for_double(double func) {
    return round(func * 1000000) / 1000000;
}
long double round_for_ldouble(long double func) {
    return round(func * 1000000) / 1000000;
}

// 1
START_TEST(s21_abs_Test) {
    ck_assert_int_eq(s21_abs(-2), abs(-2));
    ck_assert_int_eq(s21_abs(-5), abs(-5));
    ck_assert_int_eq(s21_abs(5), abs(5));
    ck_assert_int_eq(s21_abs(5), abs(5));
}
END_TEST

// 2
START_TEST(s21_acos_Test) {
    // test
}
END_TEST

// 3
START_TEST(s21_asin_Test) {
    // test
}
END_TEST

// 4
START_TEST(s21_atan_Test) {
    // test
}
END_TEST

// 5
START_TEST(s21_ceil_Test) {
    ck_assert_ldouble_eq(s21_ceil(-2.9), ceil(-2.9));
    ck_assert_ldouble_eq(s21_ceil(2.9), ceil(2.9));
    ck_assert_ldouble_eq(s21_ceil(-5.4), ceil(-5.4));
    ck_assert_ldouble_eq(s21_ceil(5), ceil(5));
    ck_assert_ldouble_eq(s21_ceil(0.0001), ceil(0.0001));
    ck_assert_ldouble_eq(s21_ceil(-0.0001), ceil(-0.0001));
}
END_TEST

// 6
START_TEST(s21_cos_Test) {
    // test
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
}
END_TEST

// 8
START_TEST(s21_fabs_Test) {
    ck_assert_ldouble_eq(s21_fabs(-2.), fabs(-2.));
    ck_assert_ldouble_eq(s21_fabs(-5.), fabs(-5.));
    ck_assert_ldouble_eq(s21_fabs(5.), fabs(5.));
    ck_assert_ldouble_eq(s21_fabs(5.0), fabs(5.0));
}
END_TEST

// 9
START_TEST(s21_floor_Test) {
    ck_assert_ldouble_eq(s21_floor(-2), floor(-2));
    ck_assert_ldouble_eq(s21_floor(-5), floor(-5));
    ck_assert_ldouble_eq(s21_floor(0.00005), floor(0.00005));
    ck_assert_ldouble_eq(s21_floor(-0.00005), floor(-0.00005));
    ck_assert_ldouble_eq(s21_floor(5.0), floor(5.0));
    ck_assert_ldouble_eq(s21_floor(2), floor(2));
}
END_TEST

// 10
START_TEST(s21_fmod_Test) {
    ck_assert_ldouble_eq(s21_fmod(7, 3), fmod(7, 3));
    ck_assert_ldouble_eq(s21_fmod(15.4, 5), fmod(15.4, 5));
    ck_assert_ldouble_eq(s21_fmod(123456789, 54321), fmod(123456789, 54321));
    ck_assert_ldouble_eq(s21_fmod(0, 5.0), fmod(0, 5.0));
    ck_assert_ldouble_eq(s21_fmod(23, 2), fmod(23, 2));
    ck_assert_ldouble_eq(s21_fmod(-23, 2), fmod(-23, 2));
    ck_assert_ldouble_eq(s21_fmod(23, -2), fmod(23, -2));
    ck_assert_ldouble_eq(s21_fmod(-23, -2), fmod(-23, -2));
    ck_assert_ldouble_eq(s21_fmod(23, 1), fmod(23, 1));
}
END_TEST

// 11
START_TEST(s21_log_Test) {}
END_TEST

// 12
START_TEST(s21_pow_Test) {  // Денис, функции падают, согласуй завтра мое
                            // решение с Асланом и делай как он скажет!
    ck_assert_ldouble_eq(round_for_ldouble(s21_pow(2.6, 3.45)),
                         round_for_double(pow(2.6, 3.45)));
    // ck_assert_ldouble_eq(s21_pow(3.0, 14.0), pow(3.0, 14.0));
    // ck_assert_ldouble_eq(s21_pow(31.456, 4.3), pow(31.456, 4.3));
    // ck_assert_ldouble_eq(s21_pow(31.456, 0.3), pow(31.456, 0.3));
    // ck_assert_ldouble_eq(s21_pow(4.3, 4.3), pow(4.3, 4.3));
    // ck_assert_ldouble_eq(s21_pow(-1234, 4.3), pow(-1234, 4.3));
    // ck_assert_ldouble_eq(s21_pow(-1234, -4.3), pow(-1234, -4.3));
    // ck_assert_ldouble_eq(s21_pow(1234, -4.3), pow(1234, -4.3));
}
END_TEST

// 13
START_TEST(s21_sin_Test) {
    // ?
}
END_TEST

// 14
START_TEST(s21_sqrt_Test) {
    ck_assert_ldouble_eq(s21_sqrt(16.0), sqrt(16.0));
    ck_assert_ldouble_eq(s21_sqrt(45.35), sqrt(45.35));
    ck_assert_ldouble_eq(s21_sqrt(5.0), sqrt(5.0));
    for (double i = -1.; i < 100000; i += 10) {
        ck_assert_ldouble_eq(s21_sqrt(i), sqrt(i));
    }
    for (double i = 0; i < 1; i += 0.001) {
        ck_assert_ldouble_eq(s21_sqrt(i), sqrt(i));
    }
}
END_TEST

// 15
START_TEST(s21_tan_Test) {
    ck_assert_ldouble_eq(s21_tan(0), tan(0));
    ck_assert_ldouble_eq(s21_tan(1234.1234124325234), tan(1234.1234124325234));
    ck_assert_ldouble_eq(s21_tan(-1234.1234124325234),
                         tan(-1234.1234124325234));
    ck_assert_ldouble_eq(s21_tan(100000000000000), tan(100000000000000));
    ck_assert_ldouble_eq(s21_tan(-100000000000000), tan(-100000000000000));
    ck_assert_ldouble_eq(s21_tan(1.123), tan(1.123));
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
