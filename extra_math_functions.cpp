#ifdef _MSC_VER
#if _MSC_VER < 1700
#include <math.h>
	float expm1(float arg)
	{
		return ::exp(arg)-1;
	}
	double expm1(double arg)
	{
		return ::exp(arg)-1;
	}

	float log1p(float arg)
	{
		return ::log(arg+1);
	}
	double log1p(double arg)
	{
		return ::log(arg+1);
	}
#endif
#endif