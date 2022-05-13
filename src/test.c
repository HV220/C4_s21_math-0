#include <check.h>

#include "s21_math.h"

// 1
START_TEST(test_s21_abs) {
    ck_assert_int_eq(s21_abs(-2), abs(-2));
    ck_assert_int_eq(s21_abs(-5), abs(-5));
    ck_assert_int_eq(s21_abs(5), abs(5));
    ck_assert_int_eq(s21_abs(5.0), abs(5.0));

}
END_TEST


//5
START_TEST(test_s21_ceil) {
    ck_assert_ldouble_eq(s21_ceil(-2.9), ceil(-2.9));
    ck_assert_ldouble_eq(s21_ceil(2.9), ceil(2.9));
    ck_assert_ldouble_eq(s21_ceil(-5.4), ceil(-5.4));
    ck_assert_ldouble_eq(s21_ceil(5), ceil(5));
    ck_assert_ldouble_eq(s21_ceil(0.0001), ceil(0.0001));
    ck_assert_ldouble_eq(s21_ceil(-0.0001), ceil(-0.0001));

}
END_TEST

// 8 
START_TEST(test_s21_fabs) {
    ck_assert_ldouble_eq(s21_fabs(-2), fabs(-2));
    ck_assert_ldouble_eq(s21_fabs(-5), fabs(-5));
    ck_assert_ldouble_eq(s21_fabs(5), fabs(5));
    ck_assert_ldouble_eq(s21_fabs(5.0), fabs(5.0));

}
END_TEST

// 9
START_TEST(test_s21_floor) {
    ck_assert_ldouble_eq(s21_floor(-2), floor(-2));
    ck_assert_ldouble_eq(s21_floor(-5), floor(-5));
    ck_assert_ldouble_eq(s21_floor(0.00005), floor(0.00005));
    ck_assert_ldouble_eq(s21_floor(-0.00005), floor(-0.00005));
    ck_assert_ldouble_eq(s21_floor(5.0), floor(5.0));
    ck_assert_ldouble_eq(s21_floor(2), floor(2));
}
END_TEST

// 10
START_TEST(test_s21_fmod) {
    ck_assert_ldouble_eq(s21_fmod(7,3), fmod(7,3));
    ck_assert_ldouble_eq(s21_fmod(15.4, 5), fmod(15.4, 5));
    ck_assert_ldouble_eq(s21_fmod(123456789, 54321), fmod(123456789, 54321));
    // ck_assert_ldouble_eq(s21_fmod(32, 0), fmodl(32, 0));
    ck_assert_ldouble_eq(s21_fmod(0, 5.0), fmod(0, 5.0));
    ck_assert_ldouble_eq(s21_fmod(23, 2), fmod(23, 2));
    ck_assert_ldouble_eq(s21_fmod(-23, 2), fmod(-23, 2));
    ck_assert_ldouble_eq(s21_fmod(23, -2), fmod(23, -2));
    ck_assert_ldouble_eq(s21_fmod(-23, -2), fmod(-23, -2));
    ck_assert_ldouble_eq(s21_fmod(23, 1), fmod(23, 1));
    
}
END_TEST

int main() {
    Suite *suite = suite_create("S21_Debuger");
    SRunner *srunner = srunner_create(suite);
    
    // 1
    TCase *s21_absCase = tcase_create("s21_absCase");
    suite_add_tcase(suite, s21_absCase);
    tcase_add_test(s21_absCase, test_s21_abs);
   
    // 5
    TCase *s21_ceilCase = tcase_create("s21_ceilCase");
    suite_add_tcase(suite, s21_ceilCase);
    tcase_add_test(s21_ceilCase, test_s21_ceil);

    //8
    TCase *s21_fabsCase = tcase_create("s21_fabsCase");
    suite_add_tcase(suite, s21_fabsCase);
    tcase_add_test(s21_fabsCase, test_s21_fabs);
    
    //9
    TCase *s21_floorCase = tcase_create("s21_floorCase");
    suite_add_tcase(suite, s21_floorCase);
    tcase_add_test(s21_floorCase, test_s21_floor);

    //10
    TCase *s21_fmodCase = tcase_create("s21_fmodCase");
    suite_add_tcase(suite, s21_fmodCase);
    tcase_add_test(s21_fmodCase, test_s21_fmod);

    srunner_run_all(srunner, CK_VERBOSE);
    int number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
