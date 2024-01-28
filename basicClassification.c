#include "NumClass.h"


int isqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }

    int start = 1;
    int end = x;
    int result;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (mid * mid == x) {
            return mid;
        }

        if (mid * mid < x) {
            start = mid + 1;
            result = mid;
        } else {
            end = mid - 1;
        }
    }

    return result;
}

int isPrime(int i){
    int temp = isqrt(i); // Assuming you have an isqrt function.
    int prime = 0;
    
    if (i == 0) {
        prime = 1;
    }
    
    for (int j = 2; j <= temp; j++) {
        if (i % j == 0) {
            prime = 1;
            break;
        }
    }
    
    if (prime == 0) {
        return 1;
    }
    return 0;
}

int fact(int n){
    int theFactorial = 1;
    for (int i = 1; i <= n; i++) {
        theFactorial *= i;
    }
    return theFactorial;
}

int isStrong(int i){
    int temp = i;
    int temp2;
    int sum = 0;
    int factorial;
    
    while (temp != 0) {
        temp2 = temp % 10;
        factorial = fact(temp2);
        temp /= 10;
        sum += factorial;
    }
    if (sum == i) {
        return 1;
    }
    return 0;
}

