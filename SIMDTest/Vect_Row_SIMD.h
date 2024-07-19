#ifndef Vect_Row_SIMD_H
#define Vect_Row_SIMD_H

#include <xmmintrin.h>
#include <smmintrin.h>  

class Matrix_Row_SIMD;

class Vect_Row_SIMD
{
public:
	Vect_Row_SIMD() = default;
	Vect_Row_SIMD(const Vect_Row_SIMD &tmp) = default;
	Vect_Row_SIMD &operator = (const Vect_Row_SIMD &tmp) = default;
	~Vect_Row_SIMD() = default;

	Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw);

public:

	// anonymous union
	union
	{
		__m128	_m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};
};

/*
* Proxy implementation for fast computation.
*/

struct VM
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;

	VM(const Vect_Row_SIMD& tV, const Matrix_Row_SIMD& tM)
		: v(tV), m1(tM) {};
};

struct VMM
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;

	VMM(const VM& tVm, const Matrix_Row_SIMD& tM)
		: v(tVm.v), m1(tVm.m1), m2(tM) {};
};

struct VMMM
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;

	VMMM(const VMM& tVm, const Matrix_Row_SIMD& tM)
		: v(tVm.v), m1(tVm.m1), m2(tVm.m2), m3(tM) {};
};

struct VMMMM
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;
	const Matrix_Row_SIMD& m4;

	VMMMM(const VMMM& tVm, const Matrix_Row_SIMD& tM)
		: v(tVm.v), m1(tVm.m1), m2(tVm.m2), m3(tVm.m3), m4(tM) {};
};

struct VMMMMM
{
	const Vect_Row_SIMD& v;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;
	const Matrix_Row_SIMD& m4;
	const Matrix_Row_SIMD& m5;

	VMMMMM(const VMMMM& tVm, const Matrix_Row_SIMD& tM)
		: v(tVm.v), m1(tVm.m1), m2(tVm.m2), m3(tVm.m3), m4(tVm.m4), m5(tM) {};

	operator Vect_Row_SIMD();
};

inline VM operator*(const Vect_Row_SIMD& v, const Matrix_Row_SIMD& ma)
{
	return VM(v, ma);
}

inline VMM operator*(const VM& v, const Matrix_Row_SIMD& ma)
{
	return VMM(v, ma);
}

inline VMMM operator*(const VMM& v, const Matrix_Row_SIMD& ma)
{
	return VMMM(v, ma);
}

inline VMMMM operator*(const VMMM& v, const Matrix_Row_SIMD& ma)
{
	return VMMMM(v, ma);
}

inline VMMMMM operator*(const VMMMM& v, const Matrix_Row_SIMD& ma)
{
	return VMMMMM(v, ma);
}

#endif
