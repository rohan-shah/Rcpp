#ifndef EXTRA_MATH_FUNCTIONS_HEADER_GUARD
#define EXTRA_MATH_FUNCTIONS_HEADER_GUARD
#ifdef _MSC_VER
#if _MSC_VER < 1700
	float expm1(float arg);
	double expm1(double arg);

	float log1p(float arg);
	double log1p(double arg);
#endif
#endif
#endif