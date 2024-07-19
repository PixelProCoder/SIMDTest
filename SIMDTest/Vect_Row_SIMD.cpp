#include "Vect_Row_SIMD.h"
#include "Matrix_Row_SIMD.h"

Vect_Row_SIMD::Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

VMMMMM::operator Vect_Row_SIMD()
{
	Vect_Row_SIMD vec;

	__m128 vX = _mm_set_ps1(v.x);
	__m128 vY = _mm_set_ps1(v.y);
	__m128 vZ = _mm_set_ps1(v.z);
	__m128 vW = _mm_set_ps1(v.w);

	vX = _mm_mul_ps(vX, m1.v0._m);
	vY = _mm_mul_ps(vY, m1.v1._m);
	vZ = _mm_mul_ps(vZ, m1.v2._m);
	vW = _mm_mul_ps(vW, m1.v3._m);

	vX = _mm_add_ps(vX, vY);
	vX = _mm_add_ps(vX, vZ);
	vX = _mm_add_ps(vX, vW);

	vec._m = vX;

	vX = _mm_set_ps1(vec.x);
	vY = _mm_set_ps1(vec.y);
	vZ = _mm_set_ps1(vec.z);
	vW = _mm_set_ps1(vec.w);

	vX = _mm_mul_ps(vX, m2.v0._m);
	vY = _mm_mul_ps(vY, m2.v1._m);
	vZ = _mm_mul_ps(vZ, m2.v2._m);
	vW = _mm_mul_ps(vW, m2.v3._m);

	vX = _mm_add_ps(vX, vY);
	vX = _mm_add_ps(vX, vZ);
	vX = _mm_add_ps(vX, vW);

	vec._m = vX;

	vX = _mm_set_ps1(vec.x);
	vY = _mm_set_ps1(vec.y);
	vZ = _mm_set_ps1(vec.z);
	vW = _mm_set_ps1(vec.w);

	vX = _mm_mul_ps(vX, m3.v0._m);
	vY = _mm_mul_ps(vY, m3.v1._m);
	vZ = _mm_mul_ps(vZ, m3.v2._m);
	vW = _mm_mul_ps(vW, m3.v3._m);

	vX = _mm_add_ps(vX, vY);
	vX = _mm_add_ps(vX, vZ);
	vX = _mm_add_ps(vX, vW);

	vec._m = vX;

	vX = _mm_set_ps1(vec.x);
	vY = _mm_set_ps1(vec.y);
	vZ = _mm_set_ps1(vec.z);
	vW = _mm_set_ps1(vec.w);

	vX = _mm_mul_ps(vX, m4.v0._m);
	vY = _mm_mul_ps(vY, m4.v1._m);
	vZ = _mm_mul_ps(vZ, m4.v2._m);
	vW = _mm_mul_ps(vW, m4.v3._m);

	vX = _mm_add_ps(vX, vY);
	vX = _mm_add_ps(vX, vZ);
	vX = _mm_add_ps(vX, vW);

	vec._m = vX;

	vX = _mm_set_ps1(vec.x);
	vY = _mm_set_ps1(vec.y);
	vZ = _mm_set_ps1(vec.z);
	vW = _mm_set_ps1(vec.w);

	vX = _mm_mul_ps(vX, m5.v0._m);
	vY = _mm_mul_ps(vY, m5.v1._m);
	vZ = _mm_mul_ps(vZ, m5.v2._m);
	vW = _mm_mul_ps(vW, m5.v3._m);

	vX = _mm_add_ps(vX, vY);
	vX = _mm_add_ps(vX, vZ);
	vX = _mm_add_ps(vX, vW);

	vec._m = vX;

	return vec;
}
