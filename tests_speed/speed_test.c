#ifndef __VECTOR_SIMD_C__
#define __VECTOR_SIMD_C__
//#include "global_defines.h"
#include <math.h>
#include "vector_simd.h"
#include "vector_non_simd.h"
#include <stdio.h>
#include <time.h>
int main(){
    vector3d first_vector = {1, 1, 1, 0};
    vector3d second_vector = {-0.5, -0.5, 1, 0};
    vector3d cross;
    vector3d_nonSimd first_nonS = {.x = 1, .y = 1, .z  = 1};
    vector3d_nonSimd second_nonS = {.x = -0.5, .y = -0.5, .z  = 1};
    vector3d_nonSimd cross_nonS;
    clock_t start, end;
    start = clock(); //%ld to print
    printf("start time simd is %ld\n", start);
    for (size_t i = 0; i < 50000000; i++)
    {
        CROSS_PRODUCT(cross, first_vector, second_vector);
    }
    end = clock();
    printf("end time simd is %ld\n", end);
    printf("time consumed is %ld\n\n\n\n", end - start);

    start = clock(); //%ld to print
    printf("start time another method simd is %ld\n", start);
    for (size_t i = 0; i < 50000000; i++)
    {
        CROSS_PRODUCT_AM(cross, first_vector, second_vector);
    }
    end = clock();
    printf("end time simd another method is %ld\n", end);
    printf("time consumed is %ld\n\n\n\n", end - start);

    start = clock(); //%ld to print
    printf("start time non-simd is %ld\n", start);
    for (size_t i = 0; i < 50000000; i++)
    {
        cross_product_nonSimd(cross_nonS, first_nonS, second_nonS);
    }
    end = clock();
    printf("end time non-simd is %ld\n", end);
    printf("time consumed is %ld\n\n\n\n", end - start);
    
    printf("\n");
    printf("Press enter to continue...\n");
    getchar();
}

#endif