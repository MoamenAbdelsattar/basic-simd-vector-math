#ifndef __VECTOR_SIMD_H__
#define __VECTOR_SIMD_H__
//#include "global_defines.h"
#include <math.h>
#include <stdint.h>
//#include "immintrin.h"

#define Square(x) ((x)*(x))
#define Cubic(x) (x)*(x)*(x)

typedef float vector3d __attribute__((vector_size(4 * sizeof(float))));
typedef int32_t int_vector3d  __attribute__((vector_size(4 * sizeof(int32_t))));
#define TO_VEC4(f) ((vector3d){f, f, f, f})
static inline void distance_vectors(vector3d v1, vector3d v2, float* result){
    vector3d squared = (v1 - v2);
    squared = squared * squared;
    (*result) = sqrt(squared[0] + squared[1] + squared[2]);
}
static inline float distance_vectors_return(vector3d v1, vector3d v2){
    vector3d squared = (v1 - v2);
    squared = squared * squared;
    return sqrt(squared[0] + squared[1] + squared[2]);
}
#define ANY3(vec) (vec[0] || vec[1] || vec[2])
#define ALL3(vec) (vec[0] && vec[1] && vec[2])


//#define dot_product(v1,v2) (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z)
#define DOT_PRODUCT_VEC(dist,v1,v2) (dist = (v1) * (v2)) //then sum 0, 1 and 2
static inline float dot_product(vector3d v1, vector3d v2){
    vector3d dot = v1 * v2;
    return dot[0] + dot[1] + dot[2];
}

#define is_same_location_VEC(loc1, loc2) ((loc1 == loc2))

static inline void sub_vectors(vector3d* dist, vector3d v1, vector3d v2){
    (*dist) = v1 - v2;
}

/*#define CROSS_PROCUCT(dest,v1,v2) \
          dest.x=v1.y*v2.z-v1.z*v2.y; \
          dest.y=v1.z*v2.x-v1.x*v2.z; \
          dest.z=v1.x*v2.y-v1.y*v2.x;*/
static int_vector3d  cr_mask0 = {1, 2, 0, 3};
static int_vector3d  cr_mask1 = {2, 0, 1, 3};
static inline void cross_product(vector3d* dist, vector3d v1, vector3d v2){
    /*vector3d tmp0 = __builtin_shuffle (v1, cr_mask0); 
    vector3d tmp1 = __builtin_shuffle (v2, cr_mask1);
    vector3d tmp2 = __builtin_shuffle (v1, cr_mask1); 
    vector3d tmp3 = __builtin_shuffle (v2, cr_mask0);
    (*dist) = (tmp0 * tmp1) - (tmp2 * tmp3);*/
    (*dist) = (__builtin_shuffle (v1, cr_mask0) * __builtin_shuffle (v2, cr_mask1)) -
              (__builtin_shuffle (v1, cr_mask1) * __builtin_shuffle (v2, cr_mask0)) ;
}
#define CROSS_PRODUCT(dist, v1, v2 )\
    dist = (__builtin_shuffle (v1, cr_mask0) * __builtin_shuffle (v2, cr_mask1)) -\
           (__builtin_shuffle (v1, cr_mask1) * __builtin_shuffle (v2, cr_mask0)) ;

/*#define CROSS_PROCUCT_AM(dest,v1,v2) \
          dest.z=v1.x*v2.y-v1.y*v2.x;\
          dest.x=v1.y*v2.z-v1.z*v2.y; \
          dest.y=v1.z*v2.x-v1.x*v2.z; \
          */

static int_vector3d  cr_mask0_am = {1, 2, 0, 3}; //another method
static int_vector3d  cr_mask1_am = {1, 2, 0, 3}; //another method
static inline void cross_product_am(vector3d* dist, vector3d v1, vector3d v2){ //another method, 3 shuffles instead of 4
    /*vector3d tmp0 = __builtin_shuffle (v1, cr_mask0_am); 
    vector3d tmp1 = __builtin_shuffle (v2, cr_mask0_am);
    (*dist) = ((v1 * tmp1) - (v2 * tmp0));
    (*dist) = __builtin_shuffle ((*dist), cr_mask1_am);*/
    (*dist) = __builtin_shuffle (
                                ((v1 *  __builtin_shuffle (v2, cr_mask0_am))
                              -  (v2 * __builtin_shuffle (v1, cr_mask0_am))) , cr_mask1_am);
}
#define CROSS_PRODUCT_AM(dist, v1, v2)\
    dist =__builtin_shuffle (\
                            ((v1 *  __builtin_shuffle (v2, cr_mask0_am))\
                         -  (v2 * __builtin_shuffle (v1, cr_mask0_am))) , cr_mask1_am);

static inline void center_position_calc(vector3d* dist, vector3d v1, vector3d v2){
    (*dist) = (v1 + v2)/((vector3d){2, 2, 2, 2});
}
#define CENTER_POSITION_CALC(dist, v1, v2)( dist = ((v1) + (v2))/((vector3d){2, 2, 2, 2})s)
#define SUB_VECTORS(dist, v1, v2)(dist = v1 - v2)
#define ADD_VECTORS(dist, v1, v2)(dist = v1 + v2)
#define MULTIPLE_VECTOR(dist, v1, factor)(dist =  v1 * (vector3d){factor, factor, factor, factor})
//void center_position_calc_f(location3d* loc1, location3d loc2);


#endif