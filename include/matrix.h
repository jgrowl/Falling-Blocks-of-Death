#ifndef __MATRIX_H__
#define __MATRIX_H__


#include "defs.h"
#include "vector.h"

void Mtx44Zero( mtx44_t result );
void Mtx44Identity( mtx44_t result );

void Mtx44Scale3f( mtx44_t result, float x, float y, float z );
void Mtx44UniformScale( mtx44_t result, float s );
void Mtx44Scale( mtx44_t result, vec3_t a );
void Mtx44Transpose( mtx44_t result,mtx44_t m );
void Mtx44Concat( mtx44_t result, mtx44_t M, mtx44_t N );
void Mtx44Translate3f( mtx44_t result, float x, float y, float z );
void Mtx44Translate( mtx44_t result, vec3_t a );
void Mtx44RotateDeg( mtx44_t result, vec3_t axis, float deg );
void Mtx44RotateRad( mtx44_t result, vec3_t axis, float rad );
void Mtx44RotateRad_x( mtx44_t result, float rad );
void Mtx44RotateRad_y( mtx44_t result, float rad );
void Mtx44RotateRad_z( mtx44_t result, float rad );
void Mtx44MultiplyVec3( vec3_t result, vec3_t a, mtx44_t m );


#endif  // __MATRIX_H__
