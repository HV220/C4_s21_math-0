#include <check.h>
#include <stdlib.h>

#include "s21_math.h"

// 1
START_TEST(s21_abs_Test) {
    // test
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
    // test
}
END_TEST

// 6
START_TEST(s21_cos_Test) {
    // test
}
END_TEST

// 7
START_TEST(s21_exp_Test) {
    // test
}
END_TEST

// 8
START_TEST(s21_fabs_Test) {
    // test
}
END_TEST

// 9
START_TEST(s21_floor_Test) {
    // test
}
END_TEST

// 10
START_TEST(s21_fmod_Test) {
    // test
}
END_TEST

// 11
START_TEST(s21_log_Test) {
    // test
}
END_TEST

// 12
START_TEST(s21_pow_Test) {
    // test
}
END_TEST

// 13
START_TEST(s21_sin_Test) {
    // test
}
END_TEST

// 14
START_TEST(s21_sqrt_Test) {
    // test
}
END_TEST

// 15
START_TEST(s21_tan_Test) {
    // test
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
