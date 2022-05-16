#include "s21_math.h"

#include <math.h>
#include <stdio.h>

long double s212_log(double x);

// 1
int s21_abs(int x) { return (x < 0) ? -x : x; }
// 2
long double s21_acos(double x) { return s21_PI / 2 - asin(x); }
// 3
long double s21_asin(double x) {
    double tmp = x;
    double result;
    int status = 0;
    x<-1 || x> 1 ? (result = s21_NAN, status = 1) : (status = 0);
    x == -1 || x == 1 ? (result = s21_PI / 2 * x), (status = 1) : (status = 0);
    result = x;
    for (long double count = 1; count < 1000000 && status == 0; count++) {
        tmp *= ((x * x) * (2 * count - 1) * (2 * count - 1)) /
               ((2 * count) * (2 * count + 1));
        result += tmp;
    }
    return result;
}
// 4
long double s21_atan(double x) {
    return s21_asin(x / (s21_sqrt(1 + s21_pow(x, 2))));
}

// 5
long double s21_ceil(double x) {
    return (int)x != x
               ? ((x < 0) ? (long double)((int)x) : (long double)((int)x + 1))
               : (double)((int)x);
}
// 6
long double s21_cos(double x) {
    while (x > s21_PI || x < -s21_PI) {
        x += x > s21_PI ? -2 * s21_PI : 2 * s21_PI;
    }
    return s21_sin(s21_PI / 2 - x);
}

// 7
long double s21_exp(double x) {
    long double result = 1;
    long double temp = 1;
    long double i = 1;
    int flag = 0;
    if (x < 0) {
        x *= -1;
        flag = 1;
    }
    while (s21_fabs(result) > s21_EPS) {
        result *= x / i;
        i += 1;
        temp += result;
        if (temp > s21_MAX_double) {
            temp = s21_INF;
            break;
        }
    }
    (temp = flag == 1 ? (temp > s21_MAX_double ? 0 : 1. / temp) : temp);
    return temp > s21_MAX_double ? s21_INF : temp;
}
// 8
long double s21_fabs(double x) { return (x < 0) ? -x : x; }
// 9
long double s21_floor(double x) {
    return (int)x != x
               ? ((x < 0) ? (long double)((int)x - 1) : (long double)((int)x))
               : (long double)((int)x);
}
// 10
long double s21_fmod(double x, double y) {
    return y != 0 ? (x - ((long double)((int)(x / y))) * y) : s21_NAN;
}
// 11
long double s21_log(double x) {
    long double sign = 1;
    long double degree = 0;
    long double count = 2;
    long double result;
    long double temp;
    x < 0 ? (x *= -1, sign *= -1) : (x *= 1, sign *= 1);
    while ((x >= 10) || (x < 1 && x > 0))
        x<1 && x> 0 ? (x *= 10, degree -= 1) : (x *= 0.1, degree += 1);
    x = sign * x / 10;
    if (x < 0) {
        result = -s21_NAN;
    } else if (x == 0) {
        result = -s21_INF;
    } else {
        x--;
        result = x;
        temp = x;
        while (s21_fabs(result) > s21_EPS) {
            result *= -x*(count - 1)/count;
            count += 1;
            temp += result;
        }
        result = temp + (degree + 1) * s21_LN10;
    }
    return result;
}
// 12
long double s21_pow(double base, double exp) {
    return (long double)s21_exp(exp * s21_log(base));
}
// 13
long double s21_sin(double x) {
    while (x > s21_PI || x < -s21_PI) {
        x += x > s21_PI ? -2 * s21_PI : 2 * s21_PI;
    }
    long double result = x, temp = x;
    long double i = 1.;
    while (s21_fabs(result) > s21_EPS) {
        result = -1 * result * x * x / (2 * i * (2 * i + 1));
        i += 1;
        temp += result;
    }
    return temp;
}
// 14
long double s21_sqrt(double x) {
    return s21_pow(S21_E, (long double)0.5 * s21_log((long double)x));
}
// 15
long double s21_tan(double x) { return (long double)(s21_sin(x) / s21_cos(x)); }
