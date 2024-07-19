#include "Vect_vM_SIMD.h"
#include "Matrix_vM_SIMD.h"

Vect_vM_SIMD::Vect_vM_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

//------------------------------
// For no proxy
//------------------------------

Vect_vM_SIMD Vect_vM_SIMD::operator * (const Matrix_vM_SIMD &ma) const
{
	__m128 vX = _mm_set_ps1(x);
	__m128 vY = _mm_set_ps1(y);
	__m128 vZ = _mm_set_ps1(z);
	__m128 vW = _mm_set_ps1(w);

	vX = _mm_mul_ps(vX, ma.v0._m);
	vY = _mm_mul_ps(vY, ma.v1._m);
	vZ = _mm_mul_ps(vZ, ma.v2._m);
	vW = _mm_mul_ps(vW, ma.v3._m);

	vX = _mm_add_ps(vX, vY);
	vX = _mm_add_ps(vX, vZ);
	vX = _mm_add_ps(vX, vW);

	Vect_vM_SIMD v;
	v._m = vX;

	return v;
};
