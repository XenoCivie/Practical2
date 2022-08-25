#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define TITLE "DECIMAL TO RADIX-i converter"
#define AUTHOR "Dylan Fanner"
#define DATE "2022"

void Dec2RadixI(int decValue, int radValue);

int main(void) {
    int radix, input;

    printf("*****************************\n");
    printf("%s\n", TITLE);
    printf("Written by: %s\n", AUTHOR);
    printf("Date: %s\n", DATE);
    printf("*****************************\n");

    while (1) {
        printf("Enter a decimal number: ");
        scanf("%d", &input);

        if (input < 0) {
            printf("EXIT");
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
}

void Dec2RadixI(int decValue, int radValue) {
    const char dic[16] = {'0', '1','2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};  
    int q, r, i = 0, out_len;
    float n; 

    if (decValue == 0) { // Checks if decValue is 0 
        printf("The log2 of the number is -inf\n");
        printf("The integer result of the number divided by %d is 0\n", radValue);
        printf("The radix-%d value is 0\n", radValue);
    }

    else { // If decValue != 0, run converstion to radix-n
        n = log2(decValue); 
        out_len = ceil(n) + 1;
        char output[out_len]; 
    
        printf("The log2 of the number is %.2f\n", n);

        while (decValue > 0) {

            q = (decValue/radValue); // Find integer result of decValue/radValue
            printf("The integer result of the number divided by %d is %d\n", radValue, q);
            r = decValue - q*radValue; // Find remainder after division
            printf("The remainder is %d\n", r);

            output[i] = dic[r]; // Attach character to output string
            decValue = q;

            i++;
        }

        printf("The radix-%d value is ", radValue); // Code for printing string - printf("%s") had strange issues 
        for (int j = 1; j <= i; j++) {
            printf("%c", output[i - j]);
        }
        printf("\n");
    }
}