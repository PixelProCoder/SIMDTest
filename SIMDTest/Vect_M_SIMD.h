#ifndef Vect_M_SIMD_H
#define Vect_M_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  

class Matrix_M_SIMD;

class Vect_M_SIMD
{
public:
	Vect_M_SIMD() = default;
	Vect_M_SIMD(const Vect_M_SIMD &tmp) = default;
	Vect_M_SIMD &operator = (const Vect_M_SIMD &tmp) = default;
	~Vect_M_SIMD() = default;

	Vect_M_SIMD(const float tx, const float ty, const float tz, const float tw);

public:

	union
	{
		__m128	_m;

		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

#endif
