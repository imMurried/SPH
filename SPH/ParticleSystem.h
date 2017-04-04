#pragma once
#include "Math.h"
class Particle;

class ParticleSystem
{
public:
	ParticleSystem();
	~ParticleSystem();

	void Update(float deltaTime);

private:
	float SmoothingKernel(Particle* p_i, Particle* p_j, float smoothingFactor);

	std::vector<Particle> m_particles;
};

