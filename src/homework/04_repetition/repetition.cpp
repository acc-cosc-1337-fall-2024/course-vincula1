//add include statements
#include "repetition.h"


//add function(s) code here

int factorial(int num) {
    int sum = 1;
    while (num > 0) {
        sum *= num;
        num --;

    }

    return sum;
}


int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;

    }
    return a;
}