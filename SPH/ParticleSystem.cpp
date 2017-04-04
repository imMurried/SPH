#include "ParticleSystem.h"
#include "Particle.h"



ParticleSystem::ParticleSystem()
{
}


ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::Update(float deltaTime)
{
}

float ParticleSystem::SmoothingKernel(Particle* p_i, Particle* p_j, float smoothingFactor)
{
	Vec3 r(p_i->GetPos().x - p_j->GetPos().x, p_i->GetPos().y - p_j->GetPos().y, p_i->GetPos().z - p_j->GetPos().z);
	
	float mod_r = sqrtf((r.x * r.x) + (r.y * r.y) + (r.z * r.z));

	float C = 1 / (4 * M_PI * smoothingFactor * smoothingFactor * smoothingFactor);

	float q = mod_r / smoothingFactor;

	if (q <= 0 && q < 1)
	{
		return C * (((2 - q) * (2 - q) * (2 - q)) - (4 * ((1 - q) * (1 - q) * (1 - q))));
	}
	else if (q <= 1 && q < 2)
	{
		return C * ((2 - q) * (2 - q) * (2 - q));
	}
	else return 0;
}
