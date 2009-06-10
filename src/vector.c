#include "vector.h"
#include "math.h"


// constants
const vec3_t v3_unit_x = { 1, 0, 0 };
const vec3_t v3_unit_y = { 0, 1, 0 };
const vec3_t v3_unit_z = { 0, 0, 1 };
const vec3_t v3_zero_vector = { 0, 0, 0 };
const vec3_t v3_unit_scale = { 1, 1, 1 };

const vec2_t v2_unit_x = { 1, 0 };
const vec2_t v2_unit_y = { 0, 1 };
const vec2_t v2_zero_vector = { 0, 0 };
const vec2_t v2_unit_scale = { 1, 1 };


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

/// vec2_t ----------------------------
// a = (x,y)
void Vec2Set(vec2_t a, const float x, const float y)
{
    a[0] = x;
    a[1] = y;
}

// a = (0,0)
void Vec2Zero(vec2_t a)
{
    a[0] = a[1] = 0;
}

// a = b
void Vec2Copy(vec2_t a, const vec2_t b)
{
    a[0] = b[0];
    a[1] = b[1];
}

// a = b - c
void Vec2Subtract(vec2_t a, const vec2_t b, const vec2_t c)
{
    a[0] = b[0] - c[0];
    a[1] = b[1] - c[1];
}

// a = b + c
void Vec2Add(vec2_t a, const vec2_t b, const vec2_t c)
{
    a[0] = b[0] + c[0];
    a[1] = b[1] + c[1];
}

// a = s*b
void Vec2Scale(vec2_t a, const vec2_t b, const float s)
{
    a[0] = s*b[0];
    a[1] = s*b[1];
}

// a = -a
void Vec2Negate(vec2_t a)
{
    a[0] = -a[0];
    a[1] = -a[1];
}

// a.b
float Vec2DotProduct(const vec2_t a, const vec2_t b)
{
    return a[0]*b[0] + a[1]*b[1];
}


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


