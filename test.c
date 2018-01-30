#include <stdio.h>
#include <stdlib.h>

int sums(int* numbers, int numbersCount)
{  
    if (numbersCount <= 1 )
        return (0);

    int total = 0;
    int big = numbers[0]; int small = numbers[0];
    for (int i = 0; i < numbersCount; i++)
    {
        // printf("%d\n", *numbers);
        if (*numbers > big)
        {
            total += *numbers;
            big = *numbers;
        }
        else if (*numbers < small)
        {
            total += *numbers;
            small = *numbers;
        }
        else
            total += *numbers;
        numbers++;
    }
    return total - big - small;
}


int main()
{
    int arr[] = { 6, 2, 1, 8, 10 };

    int *ptr = arr;

    printf("%d\n", sums(ptr, 5)); 

    printf("Bitwise shifting and shit. =%d\n", 10 >>1);

    return 0;
}
