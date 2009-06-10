#ifndef __VECTOR_H__
#define __VECTOR_H__

#include "defs.h"

//-----------------------------------------
// constants
extern const vec3_t v3_unit_x;
extern const vec3_t v3_unit_y;
extern const vec3_t v3_unit_z;
extern const vec3_t v3_zero_vector;
extern const vec3_t v3_unit_scale;

extern const vec2_t v2_unit_x;
extern const vec2_t v2_unit_y;
extern const vec2_t v2_zero_vector;
extern const vec2_t v2_unit_scale;

//-----------------------------------------
// vector operations

/// vec4_t ----------------------------
// a = (x,y,z,w)
#define Vec4Set(a,x,y,z,w) { (a)[0]=(x); (a)[1]=(y); (a)[2]=(z); (a)[2]=(w); }


/// vec3_t ----------------------------
// a = (x,y,z)
#define Vec3Set(a,x,y,z) { (a)[0]=(x); (a)[1]=(y); (a)[2]=(z); }

// a = (0,0,0)
#define Vec3Zero(a) { (a)[0] = (a)[1] = (a)[2] = 0; }

// a = b
#define Vec3Copy(a,b) { (a)[0]=(b)[0]; (a)[1]=(b)[1]; (a)[2]=(b)[2]; }

// a = b - c
#define Vec3Subtract(a,b,c) { (a)[0]=(b)[0]-(c)[0]; (a)[1]=(b)[1]-(c)[1]; (a)[2]=(b)[2]-(c)[2]; }

// a = b + c
#define Vec3Add(a,b,c) { (a)[0]=(b)[0]+(c)[0]; (a)[1]=(b)[1]+(c)[1]; (a)[2]=(b)[2]+(c)[2]; }

// a = s*b
#define Vec3Scale(a,b,s) { (a)[0]=(s)*(b)[0]; (a)[1]=(s)*(b)[1]; (a)[2]=(s)*(b)[2]; }

// a = -a
#define	Vec3Negate(a) { (a)[0]=-(a)[0]; (a)[1]=-(a)[1]; (a)[2]=-(a)[2]; }

// a.b
#define Vec3DotProduct(a,b) ((a)[0]*(b)[0]+(a)[1]*(b)[1]+(a)[2]*(b)[2])

// a : result vector
// b : input vector
void Vec3Normalize( vec3_t a, vec3_t b );

//      a : input vector
// return : length of vector
float Vec3Length( vec3_t a );

//      a : input vector
// return : length of vector, squared
float Vec3SquareLength( vec3_t a );

//   a, b : input vectors
// return : distance from a to b
float Vec3Distance( vec3_t a, vec3_t b );

//   a, b : input vector
// return : distance from a to b, squared
float Vec3SquareDistance( vec3_t a, vec3_t b );

// a = b x c
//   b, c : input vector
//      a : result vector
void Vec3CrossProduct( vec3_t a, vec3_t b, vec3_t c );


/// vec2_t ----------------------------
// a = (x,y)
inline void Vec2Set(vec2_t a, const float x, const float y);

// a = (0,0)
inline void Vec2Zero(vec2_t a);

// a = b
inline void Vec2Copy(vec2_t a, const vec2_t b);

// a = b - c
inline void Vec2Subtract(vec2_t a, const vec2_t b, const vec2_t c);

// a = b + c
inline void Vec2Add(vec2_t a, const vec2_t b, const vec2_t c);

// a = s*b
inline void Vec2Scale(vec2_t a, const vec2_t b, const float s);

// a = -a
inline void Vec2Negate(vec2_t a);

// a.b
inline float Vec2DotProduct(const vec2_t a, const vec2_t b);

// a : result vector
// b : input vector
void Vec2Normalize( vec2_t a, const vec2_t b );

//      a : input vector
// return : length of vector
float Vec2Length( const vec2_t a );

//      a : input vector
// return : length of vector, squared
float Vec2SquareLength( const vec2_t a );

//   a, b : input vectors
// return : distance from a to b
float Vec2Distance( const vec2_t a, const vec2_t b );

//   a, b : input vector
// return : distance from a to b, squared
float Vec2SquareDistance( const vec2_t a, const vec2_t b );

/*
This function returns the cross product magnitude between pVec0 and pVec1
*/
//float Vec2CrossProductMag(Vec2 *pVec0, Vec2 *pVec1);


#endif  // __VECTOR_H__
