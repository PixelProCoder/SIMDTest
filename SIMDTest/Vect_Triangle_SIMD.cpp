#include "Vect_TRIANGLE_SIMD.h"

Vect_TRIANGLE_SIMD::Vect_TRIANGLE_SIMD(const float tx, const float ty, const float tz, const float tw)
	:x(tx),y(ty),z(tz),w(tw)
{
}

Vect_TRIANGLE_SIMD Vect_TRIANGLE_SIMD::operator+(const Vect_TRIANGLE_SIMD& t) const
{
	Vect_TRIANGLE_SIMD vectTriangle;
	vectTriangle._m = _mm_add_ps(_m, t._m);

	return vectTriangle;	// NRVO
}

Vect_TRIANGLE_SIMD Vect_TRIANGLE_SIMD::operator-(const Vect_TRIANGLE_SIMD& t) const
{
	Vect_TRIANGLE_SIMD vectTriangle;
	vectTriangle._m = _mm_sub_ps(_m, t._m);

	return vectTriangle;	// NRVO
}

Vect_TRIANGLE_SIMD Vect_TRIANGLE_SIMD::operator*(const float s) const
{
	Vect_TRIANGLE_SIMD vectTriangle(s, s, s, s);
	vectTriangle._m = _mm_mul_ps(_m, vectTriangle._m);

	return vectTriangle;	// NRVO
}

float Vect_TRIANGLE_SIMD::Dot(const Vect_TRIANGLE_SIMD& B) const
{
	Vect_TRIANGLE_SIMD vectTriangle;
	vectTriangle._m = _mm_mul_ps(_m, B._m);
	vectTriangle._m = _mm_hadd_ps(vectTriangle._m, vectTriangle._m);
	vectTriangle._m = _mm_hadd_ps(vectTriangle._m, vectTriangle._m);

	return vectTriangle.x;
}

float Vect_TRIANGLE_SIMD::Length() const
{
	Vect_TRIANGLE_SIMD v;
	v._m = _mm_mul_ps(_m, _m);
	v._m = _mm_hadd_ps(v._m, v._m);
	v._m = _mm_hadd_ps(v._m, v._m);
	v._m = _mm_sqrt_ss(v._m);

	return v.x;
}

Vect_TRIANGLE_SIMD Vect_TRIANGLE_SIMD::Cross(const Vect_TRIANGLE_SIMD &R) const
{
	__m128 v1 = _mm_shuffle_ps(_m, _m, _MM_SHUFFLE(3, 0, 2, 1));
	__m128 v2 = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 1, 0, 2));
	__m128 v3 = _mm_shuffle_ps(_m, _m, _MM_SHUFFLE(3, 1, 0, 2));
	__m128 v4 = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 0, 2, 1));

	Vect_TRIANGLE_SIMD vectTriangle;
	vectTriangle._m = _mm_sub_ps(_mm_mul_ps(v1, v2), _mm_mul_ps(v3, v4));

 	return vectTriangle;
}

float Vect_TRIANGLE_SIMD::Area(const Vect_TRIANGLE_SIMD &T, const Vect_TRIANGLE_SIMD &R) 
{
	Vect_TRIANGLE_SIMD vectTriangle = T.Cross(R);

	return 0.5f * vectTriangle.Length();
}
