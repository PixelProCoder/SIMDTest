#ifndef Matrix_Col_SIMD_H
#define Matrix_Col_SIMD_H

#include "Vect_Col_SIMD.h"
   
class Matrix_Col_SIMD
{
public:
	Matrix_Col_SIMD() = default;
	Matrix_Col_SIMD(const Matrix_Col_SIMD &tmp) = default;
	Matrix_Col_SIMD &operator=(const Matrix_Col_SIMD &tmp) = default;
	~Matrix_Col_SIMD() = default;

	Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
					const Vect_Col_SIMD &tV1,
					const Vect_Col_SIMD &tV2,
					const Vect_Col_SIMD &tV3);

	union
	{
		struct
		{
			Vect_Col_SIMD v0;
			Vect_Col_SIMD v1;
			Vect_Col_SIMD v2;
			Vect_Col_SIMD v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
};

/*
* Proxy implementation for fast computation.
*/

struct MM
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;

	MM(const Matrix_Col_SIMD& tm1, const Matrix_Col_SIMD& tm2)
		: m1(tm1), m2(tm2) {};
};

struct MMM
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;
	const Matrix_Col_SIMD& m3;

	MMM(const MM& tm1, const Matrix_Col_SIMD& tm2)
		: m1(tm1.m1), m2(tm1.m2), m3(tm2) {};
};

struct MMMM
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;
	const Matrix_Col_SIMD& m3;
	const Matrix_Col_SIMD& m4;

	MMMM(const MMM& tm1, const Matrix_Col_SIMD& tm2)
		: m1(tm1.m1), m2(tm1.m2), m3(tm1.m3), m4(tm2) {};
};

struct MMMMM
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;
	const Matrix_Col_SIMD& m3;
	const Matrix_Col_SIMD& m4;
	const Matrix_Col_SIMD& m5;

	MMMMM(const MMMM& tm1, const Matrix_Col_SIMD& tm2)
		: m1(tm1.m1), m2(tm1.m2), m3(tm1.m3), m4(tm1.m4), m5(tm2) {};
};

struct MMMMMV
{
	const Matrix_Col_SIMD& m1;
	const Matrix_Col_SIMD& m2;
	const Matrix_Col_SIMD& m3;
	const Matrix_Col_SIMD& m4;
	const Matrix_Col_SIMD& m5;
	const Vect_Col_SIMD& v;

	MMMMMV(const MMMMM& tm1, const Vect_Col_SIMD& tv)
		: m1(tm1.m1), m2(tm1.m2), m3(tm1.m3), m4(tm1.m4), m5(tm1.m5), v(tv) {};

	operator Vect_Col_SIMD();
};

inline MM operator*(const Matrix_Col_SIMD& m1, const Matrix_Col_SIMD& m2)
{
	return MM(m1, m2);
}

inline MMM operator*(const MM& m1, const Matrix_Col_SIMD& m2)
{
	return MMM(m1, m2);
}

inline MMMM operator*(const MMM& m1, const Matrix_Col_SIMD& m2)
{
	return MMMM(m1, m2);
}

inline MMMMM operator*(const MMMM& m1, const Matrix_Col_SIMD& m2)
{
	return MMMMM(m1, m2);
}

inline MMMMMV operator*(const MMMMM& m1, const Vect_Col_SIMD& m2)
{
	return MMMMMV(m1, m2);
}

#endif
