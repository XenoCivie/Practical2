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

        while (-1*(radix - 2)*(radix - 16) < 0) {
            printf("That radix isn't between 2 and 16 you silly goose, please enter a valid radix:\n");
            scanf("%d", &radix);
        }
        printf("The radix you have entered is %d\n", radix);

        Dec2RadixI(input, radix);

    }

    printf("EXIT");

}

void Dec2RadixI(int decValue, int radValue) {
    const char dic[16] = {'0', '1','2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};  
    int q, msb;
    float n; 

    msb = ceil(log2(decValue + 1)/log2(radValue) - 1);  // find most significant bit from decimal input and radix
    char output[msb + 1]; // set up output string for converted number
    
    printf("The most significant bit (for base %d) for the number is %.2f\n", radValue, msb); // Printing MSB as use a char array of that length rather than log2(decValue)

    for (int i = msb; i >= 0; i--) {
        q = (decValue / (pow(radValue, i))); // find quotient for given power 
        printf("The integer result of the number divided by %d to the power %d is %d\n", radValue, i, q);
        output[msb - i] = dic[q]; // convert quotient to character representation from dic add msb -1 
        decValue -= (q * pow(radValue, i)); // reduce decValue for next loop
        printf("The remainder is %d\n", decValue);

        if ((decValue == 0)&&(i != 0)) { // in the case that the remainder is zero, fill array with zeroes and exit loop
            for (int n = (i-1); n >= 0; n--) {
                output[msb - n] = '0';
            }
        break;
        }
    }
    printf("The radix-%d value is %s\n", radValue, output);
}