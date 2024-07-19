#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"

Matrix_M_SIMD::Matrix_M_SIMD(const Vect_M_SIMD &tV0,
							 const Vect_M_SIMD &tV1,
							 const Vect_M_SIMD &tV2,
							 const Vect_M_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Matrix_M_SIMD Matrix_M_SIMD::operator * (const Matrix_M_SIMD &mb) const
{
	Matrix_M_SIMD m;

	__m128 v0X = _mm_set_ps1(v0.x);
	__m128 v0Y = _mm_set_ps1(v0.y);
	__m128 v0Z = _mm_set_ps1(v0.z);
	__m128 v0W = _mm_set_ps1(v0.w);
	__m128 v1X = _mm_set_ps1(v1.x);
	__m128 v1Y = _mm_set_ps1(v1.y);
	__m128 v1Z = _mm_set_ps1(v1.z);
	__m128 v1W = _mm_set_ps1(v1.w);
	__m128 v2X = _mm_set_ps1(v2.x);
	__m128 v2Y = _mm_set_ps1(v2.y);
	__m128 v2Z = _mm_set_ps1(v2.z);
	__m128 v2W = _mm_set_ps1(v2.w);
	__m128 v3X = _mm_set_ps1(v3.x);
	__m128 v3Y = _mm_set_ps1(v3.y);
	__m128 v3Z = _mm_set_ps1(v3.z);
	__m128 v3W = _mm_set_ps1(v3.w);

	v0X = _mm_mul_ps(v0X, mb.v0._m);
	v0Y = _mm_mul_ps(v0Y, mb.v1._m);
	v0Z = _mm_mul_ps(v0Z, mb.v2._m);
	v0W = _mm_mul_ps(v0W, mb.v3._m);
	v1X = _mm_mul_ps(v1X, mb.v0._m);
	v1Y = _mm_mul_ps(v1Y, mb.v1._m);
	v1Z = _mm_mul_ps(v1Z, mb.v2._m);
	v1W = _mm_mul_ps(v1W, mb.v3._m);
	v2X = _mm_mul_ps(v2X, mb.v0._m);
	v2Y = _mm_mul_ps(v2Y, mb.v1._m);
	v2Z = _mm_mul_ps(v2Z, mb.v2._m);
	v2W = _mm_mul_ps(v2W, mb.v3._m);
	v3X = _mm_mul_ps(v3X, mb.v0._m);
	v3Y = _mm_mul_ps(v3Y, mb.v1._m);
	v3Z = _mm_mul_ps(v3Z, mb.v2._m);
	v3W = _mm_mul_ps(v3W, mb.v3._m);

	v0X = _mm_add_ps(v0X, v0Y);
	v0X = _mm_add_ps(v0X, v0Z);
	v0X = _mm_add_ps(v0X, v0W);
	v1X = _mm_add_ps(v1X, v1Y);
	v1X = _mm_add_ps(v1X, v1Z);
	v1X = _mm_add_ps(v1X, v1W);
	v2X = _mm_add_ps(v2X, v2Y);
	v2X = _mm_add_ps(v2X, v2Z);
	v2X = _mm_add_ps(v2X, v2W);
	v3X = _mm_add_ps(v3X, v3Y);
	v3X = _mm_add_ps(v3X, v3Z);
	v3X = _mm_add_ps(v3X, v3W);

	m.v0._m = v0X;
	m.v1._m = v1X;
	m.v2._m = v2X;
	m.v3._m = v3X;

	return m;
}
