#ifndef __VECTOR_SIMD_C__
#define __VECTOR_SIMD_C__
//#include "global_defines.h"
#include <math.h>
#include "vector_simd.h"
#include <stdio.h>
int main(){
    vector3d first_vector = {1, 1, 1, 0};
    vector3d second_vector = {-0.5, -0.5, 1, 0};
    printf("successful made vectors\n");
    int_vector3d check = is_same_location_VEC(first_vector, second_vector);
    printf("same position result is (%i, %i, %i, %i)\n", check[0], check[1], check[2], check[3]);
    if (ANY3(check))
    {
        printf("any is true\n");
    }else
    {
        printf("any is false\n");
    }
    if (ALL3(check))
    {
        printf("all is true\n");
    }else
    {
        printf("all is false\n");
    }
    vector3d center;
    center_position_calc(&center, first_vector, second_vector);
    printf("center is (%f, %f, %f)\n", center[0], center[1], center[2]);
    float dot = dot_product(first_vector, second_vector);
    printf("dot product is %f\n", dot);
    vector3d cross;
    cross_product(&cross, first_vector, second_vector);
    printf("cross product is (%f, %f, %f)\n", cross[0], cross[1], cross[2]);
    cross_product_am(&cross, first_vector, second_vector);
    printf("cross product another method is (%f, %f, %f)\n", cross[0], cross[1], cross[2]);
    float distance = distance_vectors_return(first_vector, second_vector);
    printf("distance is %f\n", distance);
    printf("\n");
    printf("Press enter to continue...\n");
    getchar();
}

#endif