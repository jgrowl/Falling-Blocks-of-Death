#include "matrix.h"
#include <math.h>
#include <string.h>

/// mtx44_t

void Mtx44Zero( mtx44_t result )
{
    memset( result, 0, sizeof(mtx44_t) );
}

void Mtx44Identity( mtx44_t result )
{
    memset( result, 0, sizeof(mtx44_t) );
    result[0] = 1.f;
    result[5] = 1.f;
    result[10]= 1.f;
    result[15]= 1.f;
}

void Mtx44Scale3f( mtx44_t result, float x, float y, float z )
{
    Mtx44Zero( result );
    result[0] = x;
    result[5] = y;
    result[10]= z;
    result[15]= 1;
}

void Mtx44UniformScale( mtx44_t result, float s )
{
    Mtx44Zero( result );
    result[0] =
    result[5] =
    result[10]= s;
    result[15]= 1;
}

void Mtx44Scale( mtx44_t result, vec3_t a )
{
    Mtx44Zero( result );
    result[0] = a[0];
    result[5] = a[1];
    result[10]= a[2];
    result[15]= 1;
}

void Mtx44RotateRad_x( mtx44_t result, float rad )
{
    Mtx44Zero( result );
    result[0] = 1;
    result[5] =  cosf(rad);
    result[6] =  sinf(rad);
    result[9] = -sinf(rad);
    result[10]=  cosf(rad);
    result[15]= 1;
}

void Mtx44RotateRad_y( mtx44_t result, float rad )
{
    Mtx44Zero( result );
    result[0] = cosf(rad);
    result[2] = -sinf(rad);
    result[5] = 1;
    result[8] = sinf(rad);
    result[10]= cosf(rad);
    result[15]= 1;
}

void Mtx44RotateRad_z( mtx44_t result, float rad )
{
    Mtx44Zero( result );
    result[0] = cosf(rad);
    result[1] = sinf(rad);
    result[4] = -sinf(rad);
    result[5] = cosf(rad);
    result[10]= 1;
    result[15]= 1;
}

void Mtx44Translate3f( mtx44_t result, float x, float y, float z )
{
    Mtx44Identity( result );
    result[3] = x;
    result[7] = y;
    result[11]= z;
}

void Mtx44Translate( mtx44_t result, vec3_t a )
{
    Mtx44Identity( result );
    result[3] = a[0];
    result[7] = a[1];
    result[11]= a[2];
}

void Mtx44Concat( mtx44_t result, mtx44_t M, mtx44_t N )
{
    int i, j, k, stop = 4;
    mtx44_t answer;
    Mtx44Zero( answer );

    for ( i=0; i<stop; ++i )
        for ( j=0; j<stop; ++j )
            for ( k=0; k<stop; ++k )
                answer[i*stop + j] += M[i*stop + k]*N[k*stop + j];
              //answer[i][j] += M[i][k]*N[k][j];
    memcpy(result, answer, sizeof(mtx44_t));
}

/// Deprecated Mtx33 functions; remove
#if(0)

void Mtx33Identity(Mtx33 *pResult)
{
	memset( pResult->m, 0, 9*sizeof( pResult->m[0][0] ) );
	pResult->m[0][0] = 1.f;
	pResult->m[1][1] = 1.f;
	pResult->m[2][2] = 1.f;
}

void Mtx33Transpose( Mtx33 *pResult, Mtx33 *pMtx )
{
	bool sameMtx = pResult == pMtx;
	if (sameMtx)
	{
		pMtx = new Mtx33(*pMtx);
	}
	pResult->m[0][0] = pMtx->m[0][0];
	pResult->m[0][1] = pMtx->m[1][0];
	pResult->m[0][2] = pMtx->m[2][0];
	pResult->m[1][0] = pMtx->m[0][1];
	pResult->m[1][1] = pMtx->m[1][1];
	pResult->m[1][2] = pMtx->m[2][1];
	pResult->m[2][0] = pMtx->m[0][2];
	pResult->m[2][1] = pMtx->m[1][2];
	pResult->m[2][2] = pMtx->m[2][2];

	if (sameMtx)
	{
		delete pMtx;
	}
}

void Mtx33Concat( Mtx33 *pResult, Mtx33 *pMtx0, Mtx33 *pMtx1 )
{
    Mtx33 pAnswer;
	memset( pAnswer.m, 0, 9*sizeof( pAnswer.m[0][0] ) );
	int stop = 3;

	for (int i=0; i<stop; ++i)
		for (int j=0; j<stop; ++j)
			for (int k=0; k<stop; ++k)
				pAnswer.m[i][j] += pMtx0->m[i][k]*pMtx1->m[k][j];
	memcpy( pResult->m, pAnswer.m, 9*sizeof( pAnswer.m[0][0] ) );
}

void Mtx33Trans( Mtx33 *pResult, float x, float y )
{
	Mtx33Identity(pResult);
	pResult->m[0][2] = x;
	pResult->m[1][2] = y;
}

void Mtx33Scale( Mtx33 *pResult, float x, float y )
{
	Mtx33Identity(pResult);
	pResult->m[0][0] = x;
	pResult->m[1][1] = y;
}

void Mtx33RotDeg( Mtx33 *pResult, float angle )
{
	Mtx33RotRad( pResult, (angle*PI)/180.f );
}

void Mtx33RotRad( Mtx33 *pResult, float angle )
{
	Mtx33Identity( pResult );
	pResult->m[0][0] = cosf(angle);
	pResult->m[0][1] = -1.f*sinf(angle);
	pResult->m[1][0] = sinf(angle);
	pResult->m[1][1] = cosf(angle);
}

void Mtx33MultVec( Vec2 *pResult, const Mtx33 *pMtx, const Vec2 *pVec )
{
	float x = pVec->x*pMtx->m[0][0] + pVec->y*pMtx->m[0][1] + pMtx->m[0][2];
	pResult->y = pVec->x*pMtx->m[1][0] + pVec->y*pMtx->m[1][1] + pMtx->m[1][2];
	pResult->x = x;
}


void Mtx33Print( Mtx33 *pMtx )
{
	int stop = 3;

	for (int i=0; i<stop; ++i)
	{
		printf("[ ");

		for (int j=0; j<stop; ++j)
		{
			printf(" %f ", pMtx->m[i][j]);
		}

		printf(" ]\n");
	}
}

#endif // 0




