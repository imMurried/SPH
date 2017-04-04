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
	void UpdateAcceleration();
	void UpdateDensity();
	void UpdatePressure();

	std::vector<Particle> m_particles;
	
	float kernelSmoothFactor = 1.0f;
	float polytropicIndex = 1.0f;
	float pressureConstant = 1.0f;
	float gravity = -9.8f;
};

