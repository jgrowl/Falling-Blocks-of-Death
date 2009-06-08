#ifndef __DEFS_H__
#define __DEFS_H__

// ---------------------------------------------------------------------------
// typdef types

typedef void (*fp_void)(void);

typedef signed char         s8;
typedef unsigned char       u8;
typedef signed short        s16;
typedef unsigned short      u16;
typedef signed int          s32;
typedef unsigned int        u32;
typedef signed long long    s64;
typedef unsigned long long  u64;
typedef float               f32;
typedef double              f64;

// vector types
typedef float vec2_t[2];
typedef float vec3_t[3];
typedef float vec4_t[4];

// matrix types
typedef float mtx33_t[9];
typedef float mtx44_t[16];

// ---------------------------------------------------------------------------
// constants

#define PI 3.1415926535897932384626433832795f
#define EPSILON 0.0001f


#endif // __DEFS_H__
