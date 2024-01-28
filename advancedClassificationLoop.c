#include "NumClass.h"



int power(int base, int exponent) {
    int result = 1;
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    return result;
}

int isPalindrome(int i) {
    int temp = i;
    int revers = 0;
    int r;

    while (temp != 0) {
        r = temp % 10;
        revers = revers * 10 + r;
        temp /= 10;
    }

    if (i == revers) {
        return 1;
    }

    return 0;
}

int isArmstrong(int i) {
    int num = i;
    int cd = 0;
    int count = 0;

    while (num > 0) {
        cd++;
        num /= 10;
    }

    num = i;
    int a = cd;
    while (a > 0) {
        count += power(num % 10, cd);
        num /= 10;
        a--;
    }
    if (count == i) {
        return 1;
    }

    return 0;
}
