/*
Marching tetrahedra algorithm for meshing

Copyright (C) 2020 Moamen Mohammad Abdelsattar Mohammed, Aswan, Egypt

E-mail: moemen0101@gmail.com
*/
#ifndef VECTOR_H
#define VECTOR_H
#include <math.h>
typedef struct {
	double x,y,z;
} vector3d_nonSimd;
#define cross_product_nonSimd(dest,v1,v2) \
          dest.x=v1.y*v2.z-v1.z*v2.y; \
          dest.y=v1.z*v2.x-v1.x*v2.z; \
          dest.z=v1.x*v2.y-v1.y*v2.x;
#endif
