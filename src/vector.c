#include "vector.h"
#include "math.h"

void Vec3Normalize( vec3_t a, vec3_t b )
{
    float length = Vec3Length( b );
    if ( length < EPSILON )
        return;
    a[0] /= length;
    a[1] /= length;
    a[2] /= length;
}

float Vec3Length( vec3_t a )
{
    return sqrt( pow(a[0], 2) + pow(a[1], 2) + pow(a[2], 2) );
}

float Vec3SquareLength( vec3_t a )
{
    return pow(a[0], 2) + pow(a[1], 2) + pow(a[2], 2);
}

float Vec3Distance( vec3_t a, vec3_t b )
{
    vec3_t c;
    Vec3Subtract(c,b,a);
    return Vec3Length(c);
}

float Vec3SquareDistance( vec3_t a, vec3_t b )
{
    vec3_t c;
    Vec3Subtract(c,b,a);
    return Vec3SquareLength(c);
}

void Vec3CrossProduct( vec3_t a, vec3_t b, vec3_t c )
{
    vec3_t result;
    result[0] = b[1]*c[2] - b[2]*c[1];
    result[1] = b[2]*c[0] - b[0]*c[2];
    result[2] = b[0]*c[1] - b[1]*c[0];

    Vec3Copy(a, result);
}

/// ------------------------------------------------

// a : result vector
// b : input vector
void Vec2Normalize( vec2_t a, const vec2_t b )
{
    float length = Vec2Length( a );
    if ( length < EPSILON )
        return;
    a[0] /= length;
    a[1] /= length;
}

//      a : input vector
// return : length of vector
float Vec2Length( const vec2_t a )
{
    return sqrtf( pow(a[0],2) + pow(a[1],2) );
}

//      a : input vector
// return : length of vector, squared
float Vec2SquareLength( const vec2_t a )
{
    return pow(a[0],2) + pow(a[1],2);
}

//   a, b : input vectors
// return : distance from a to b
float Vec2Distance( const vec2_t a, const vec2_t b )
{
    vec2_t c;
    Vec2Subtract(c, b, a);
    return Vec2Length(c);
}

//   a, b : input vector
// return : distance from a to b, squared
float Vec2SquareDistance( const vec2_t a, const vec2_t b )
{
    vec2_t c;
    Vec2Subtract(c,b,a);
    return Vec2SquareLength(c);
}


