// SUM OF WEIGHTS BASE CONVERTER
// Dylan Fanner, FNNDYL001

#include <stdio.h>
#include <math.h>

int main(void) {
    int input, radix, n, q;
    
    const char dic[16] = {'0', '1','2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};   

    printf("Please enter the decimal number and desired radix separated by a space:\n");
    scanf("%d %d", &input, &radix);

    printf("\nThe decimal number %d, converted to base %d is: ", input, radix);

    n = ceil(log(input + 1)/log(radix) - 1); // Find MSB from input and base
    char output[n + 1];

    for (int i = n; i >= 0; i--) {
        q = (input / (pow(radix, i))); // Find quotient for given power 
        output[n - i] = dic[q]; // Convert quotient to character representation from dic
        input -= (q * pow(radix, i)); // Reduce input
    }

    printf("%s", output);
    return 0;
}