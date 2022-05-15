#include "s21_math.h"

#include <math.h>

// 1
int s21_abs(int x) { return (x < 0) ? -x : x; }
// 2
long double s21_acos(double x) {
    return s21_PI/2-asin(x);
}
// 3
long double s21_asin(double x) {
    double tmp = x;
    double result = x;
    int status = 0;
    x<-1 || x> 1 ? (result = s21_NAN), (status = 1) : (status = 0);
    x == -1 || x == 1 ? (result = s21_PI / 2 * x), (status = 1) : (status = 0);
    for (long double count = 1; count < 10000000 && status == 0; count++) {
        tmp *= ((x * x) * (2 * count - 1) * (2 * count - 1)) /
               ((2 * count) * (2 * count + 1));
        result += tmp;
    }
    return result;
}
// 4
long double s21_atan(double x) { return asin(x / (sqrt(1 + pow(x, 2)))); }

// 5
long double s21_ceil(double x) {
    return (int)x != x
               ? ((x < 0) ? (long double)((int)x) : (long double)((int)x + 1))
               : (double)((int)x);
}
// 6
long double s21_cos(double x) { return s21_sin(s21_PI / 2 - x); }

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
    return (long double)(x > 0 && x < 2) ? log_0_2(x) : log_other(x);
}

// 12
long double s21_pow(double base, double exp) {
    return (long double)s21_exp(exp * s21_log(base));
}
// 13
long double s21_sin(double x) {
    x = delete (x);
    long double result = x, temp = x;
    long double i = 1.;
    while (s21_fabs(result) > s21_EPS) {
        result = -1 * result * x * x / (2 * i * (2 * i + 1));
        i += 1.;
        temp += result;
    }
    return temp;
}

// 14
long double s21_sqrt(double x) {
    return s21_pow(S21_E, (long double)0.5 * s21_log((long double)x));
}
// 15
long double s21_tan(double x) {
    return (s21_sin(delete (x)) / s21_cos(delete (x)));
}

long double log_0_2(double x) {
    x--;
    long double result = x, temp = x;
    long double i = 2;
    while (s21_fabs(result) > s21_EPS) {
        result *= -x * (i - 1) / i;
        i += 1;
        temp += result;
    }
    return temp;
}

long double log_other(double x) {
    struct special _special;
    translate(x, &_special);
    x = _special.mantisa * _special.sign / 10;
    long double result;
    result = x < 0    ? -s21_NAN
             : x == 0 ? -s21_INF
                      : log_0_2(x) + (_special.e + 1) * s21_LN10;
    return result;
}

void translate(double x, struct special *_special) {
    long double i = 1;
    int es = 0;
    _special->sign = x < 0 ? -1 : 1;
    x *= _special->sign;
    if (x >= 10) {
        while (x >= 10) {
            x /= 10.;
            i *= 10;
            es++;
        }
    } else if (x < 1 && x > 0) {
        while (x < 1) {
            x *= 10;
            i /= 10;
            es--;
        }
    }
    _special->mantisa = x;
    _special->pow = i;
    _special->e = es;
}

double delete (double x) {
    while (x > s21_PI || x < -s21_PI) {
        x += x > s21_PI ? -2 * s21_PI : 2 * s21_PI;
    }
    return x;
}

long double factorial(double lim) {
    long double fact = 1;
    for (long double count = 1; count <= lim; count++) {
        fact *= count;
    }
    return fact;
}
