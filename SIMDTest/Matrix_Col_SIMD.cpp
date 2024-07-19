#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"

Matrix_Col_SIMD::Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
								 const Vect_Col_SIMD &tV1,
								 const Vect_Col_SIMD &tV2,
								 const Vect_Col_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

MMMMMV::operator Vect_Col_SIMD()
{
	Vect_Col_SIMD vec;

	// Multiply backwards to reduce the number of SIMD operations.
	// MMMMMV ---> VMMMMM

	// V * M5

	__m128 row0 = _mm_mul_ps(m5.v0._m, v._m);
	__m128 row1 = _mm_mul_ps(m5.v1._m, v._m);
	__m128 row2 = _mm_mul_ps(m5.v2._m, v._m);
	__m128 row3 = _mm_mul_ps(m5.v3._m, v._m);

	__m128 hadd1 = _mm_hadd_ps(row0, row1);
	__m128 hadd2 = _mm_hadd_ps(row2, row3);
	vec._m = _mm_hadd_ps(hadd1, hadd2);

	// (V * M5) * M4

	row0 = _mm_mul_ps(m4.v0._m, vec._m);
	row1 = _mm_mul_ps(m4.v1._m, vec._m);
	row2 = _mm_mul_ps(m4.v2._m, vec._m);
	row3 = _mm_mul_ps(m4.v3._m, vec._m);

	hadd1 = _mm_hadd_ps(row0, row1);
	hadd2 = _mm_hadd_ps(row2, row3);
	vec._m = _mm_hadd_ps(hadd1, hadd2);

	// (V * M5 * M4) * M3

	row0 = _mm_mul_ps(m3.v0._m, vec._m);
	row1 = _mm_mul_ps(m3.v1._m, vec._m);
	row2 = _mm_mul_ps(m3.v2._m, vec._m);
	row3 = _mm_mul_ps(m3.v3._m, vec._m);

	hadd1 = _mm_hadd_ps(row0, row1);
	hadd2 = _mm_hadd_ps(row2, row3);
	vec._m = _mm_hadd_ps(hadd1, hadd2);

	// (V * M5 * M4 * M3) * M2

	row0 = _mm_mul_ps(m2.v0._m, vec._m);
	row1 = _mm_mul_ps(m2.v1._m, vec._m);
	row2 = _mm_mul_ps(m2.v2._m, vec._m);
	row3 = _mm_mul_ps(m2.v3._m, vec._m);

	hadd1 = _mm_hadd_ps(row0, row1);
	hadd2 = _mm_hadd_ps(row2, row3);
	vec._m = _mm_hadd_ps(hadd1, hadd2);

	// (V * M5 * M4 * M3 * M2) * M1

	row0 = _mm_mul_ps(m1.v0._m, vec._m);
	row1 = _mm_mul_ps(m1.v1._m, vec._m);
	row2 = _mm_mul_ps(m1.v2._m, vec._m);
	row3 = _mm_mul_ps(m1.v3._m, vec._m);

	hadd1 = _mm_hadd_ps(row0, row1);
	hadd2 = _mm_hadd_ps(row2, row3);
	vec._m = _mm_hadd_ps(hadd1, hadd2);

	return vec;
}
