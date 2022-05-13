#include "s21_math.h"

#include <math.h>
#include <stdio.h>

//! Not started: 2, 3, 4, 6 4,13, 14, 15
//? In process:
// TODO Need to rewrite: 7, 11 (Сложный алгоритм, необходимо разобрать и
// TODO: зарефакторить)
// *** Complete: 1, 5, 8, 9, 10, 12, 14

// 1
int s21_abs(int x) { return (x < 0) ? -x : x; }

// 5
long double s21_ceil(double x) {
    return (int)x != x
               ? ((x < 0) ? (long double)((int)x) : (long double)((int)x + 1))
               : (double)((int)x);
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

//  11 Danil
// long double s21_log(double x) {
//     long double convert = (x - 1) / (x + 1);
//     long double ln = 0;
//     long double degree = convert;
//     long double count = 1.;
//     while (count <= 900000001.) {
//         ln += degree / count;
//         degree = convert * convert * degree;
//         count += 2.;
//         printf("%Lf || %Lf \n", degree, count);
//     }
//     return 2. * ln;
// }

// 12
long double s21_pow(double base, double exp) {
    return (long double)s21_exp(exp* s21_log(base));
}

// 14 
long double s21_sqrt(double x) {
    return s21_pow(S21_E, (long double)0.5*s21_log((long double)x));
}


// long double s21_log(double x) {
//   long double temp;
//   return log_other(x);
// }

// long double log_0_2(double x) {
//   x--;
//   long double result = x, temp = x;
//   long double i = 2;
//   while (s21_fabs(result) > s21_EPS) {
//     result *= -x * (i - 1) / i;
//     i += 1;
//     temp += result;
//   }
//   return temp;
// }

// long double log_other(double x) {
//     struct special _special;
//     translate(x, &_special);
//     x = _special.mantisa * _special.sign / 10;
//     long double result;
//     result = x < 0 ? -s21_NAN : x == 0 ? -s21_INF : log_0_2(x) + (_special.e + 1) * s21_LN10;
//     return result;
// }


// void translate(double x, struct special *_special) {
//   long double i = 1;
//   int es = 0;
//   _special->sign = x < 0 ? -1 : 1;
//   x *= _special->sign;
//   if (x >= 10) {
//     while (x >= 10) {
//       x /= 10.;
//       i *= 10;
//       es++;
//     }
//   } else if (x < 1 && x > 0) {
//     while (x < 1) {
//       x *= 10;
//       i /= 10;
//       es--;
//     }
//   }
//   _special->mantisa = x;
//   _special->pow = i;
//   _special->e = es;
// }
