#pragma once
#include "Math.h"

class Particle
{
public:
	Particle();
	~Particle();

	Vec3 GetPos() { return m_position; };

private:
	float m_mass;
	float m_pressure;
	float m_density;

	Vec3 m_position;
	Vec3 m_velocity;
	Vec3 m_acceleration;
};

