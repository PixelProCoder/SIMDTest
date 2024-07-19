#include "Vect_Mv_SIMD.h"
#include "Matrix_Mv_SIMD.h"

Matrix_Mv_SIMD::Matrix_Mv_SIMD(const Vect_Mv_SIMD &tV0,
							   const Vect_Mv_SIMD &tV1,
							   const Vect_Mv_SIMD &tV2,
							   const Vect_Mv_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Vect_Mv_SIMD Matrix_Mv_SIMD::operator * (const Vect_Mv_SIMD &v) const
{
	Vect_Mv_SIMD tmp;

	__m128 row0 = _mm_mul_ps(v0._m, v._m);
	__m128 row1 = _mm_mul_ps(v1._m, v._m);
	__m128 row2 = _mm_mul_ps(v2._m, v._m);
	__m128 row3 = _mm_mul_ps(v3._m, v._m);

	__m128 hadd1 = _mm_hadd_ps(row0, row1);
	__m128 hadd2 = _mm_hadd_ps(row2, row3);
	tmp._m = _mm_hadd_ps(hadd1, hadd2);

	return tmp;
}
