#include <stdio.h>
#include <sys/time.h>

#define SIZE 5

int main() {
    int vectorA[SIZE] = {1, 2, 3, 4, 5};
    int vectorB[SIZE] = {6, 7, 8, 9, 10};
    int vectorC[SIZE] = {11, 12, 13, 14, 15};
    int vectorD[SIZE] = {16, 17, 18, 19, 20};
    int dotProductAB = 0;
    int dotProductCD = 0;

    struct timeval start, end;
    double tiempo;

    gettimeofday(&start, NULL);

    // Calculate the dot product of A with B
    for (int i = 0; i < SIZE; i++) {
        dotProductAB += vectorA[i] * vectorB[i];
    }

    // Calculate the dot product of C with D
    for (int i = 0; i < SIZE; i++) {
        dotProductCD += vectorC[i] * vectorD[i];
    }

    // Print the results
    printf("The dot product of A with B is: %d\n", dotProductAB);
    printf("The dot product of C with D is: %d\n", dotProductCD);

    gettimeofday(&end, NULL);

    tiempo = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("The execution time is: %f seconds\n", tiempo);

    return 0;
}