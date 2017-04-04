#pragma once
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>

class Math
{
public:
	Math();
	~Math();
	
};

struct Vec3
{
	Vec3();
	Vec3(float x, float y, float z);

	union
	{
		float x;
		float r;
	};

	union
	{
		float y;
		float g;
	};

	union
	{
		float z;
		float b;
	};
};