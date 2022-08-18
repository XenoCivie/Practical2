#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Dylan Fanner"
#define DATE "2022"

void Dec2RadixI(int decValue, int radValue);

int main(void) {
    int radix, q, n;
    int input = 1;

    printf("*****************************\n");
    printf("%s\n", TITLE);
    printf("Written by: %s\n", AUTHOR);
    printf("Date: %s\n", DATE);
    printf("*****************************\n");

    while (1) {
        printf("Enter a decimal number: ");
        scanf("%d", &input);

        if (input <= 0) {
            break;
        }

        printf("The number you have entered is %d\n", input);

        printf("Enter a radix for the converter between 2 and 16: ");
        scanf("%d", &radix);
        printf("The radix you have entered is %d\n", radix);

        Dec2RadixI(input, radix);

    }

    printf("EXIT");

}

void Dec2RadixI(int decValue, int radValue) {
    const char dic[16] = {'0', '1','2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};  
    int q, msb;
    float n; 

    n = log(decValue + 1)/log(radValue); // Find log_radix(decimal value) from input and base
    msb = ceil(n - 1); // round up and subtract 1 to find most significant bit (msb)
    char output[msb + 1]; // set up output string for converted number
    
    printf("The log%d of the number is %.2f\n", radValue, n);

    for (int i = msb; i >= 0; i--) {
        q = (decValue / (pow(radValue, i))); // Find quotient for given power 
        output[msb - i] = dic[q]; // Convert quotient to character representation from dic add msb -1 
        decValue -= (q * pow(radValue, i)); // Reduce decValue for next loop
    }

    printf("The radix-%d value is %s\n", radValue, output);

}