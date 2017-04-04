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
	Vec3 r(p_i->m_position.x - p_j->m_position.x, p_i->m_position.y - p_j->m_position.y, p_i->m_position.z - p_j->m_position.z);
	
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

void ParticleSystem::UpdateAcceleration()
{
	UpdateDensity();
	UpdatePressure();

	float acceleration = 0;
	for (size_t i = 0; i < m_particles.size(); i++)
	{
		for (size_t j = 0; j < m_particles.size(); j++)
		{
			if (i != j)
			{
				acceleration += m_particles.at(j).m_mass * ((m_particles.at(i).m_pressure / powf(m_particles.at(i).m_density, 2)) + (m_particles.at(j).m_pressure / powf(m_particles.at(j).m_density, 2))) * SmoothingKernel(&m_particles.at(i), &m_particles.at(j), kernelSmoothFactor) + gravity;
			}
		}
	}
}

void ParticleSystem::UpdateDensity()
{
	for (size_t i = 0; i < m_particles.size(); i++)
	{
		m_particles.at(i).m_density = 0;
		for (size_t j = 0; j < m_particles.size(); j++)
		{
			m_particles.at(i).m_density += m_particles.at(j).m_mass * SmoothingKernel(&m_particles.at(i), &m_particles.at(j), kernelSmoothFactor);
		}
	}
}

void ParticleSystem::UpdatePressure()
{
	for (size_t i = 0; i < m_particles.size(); i++)
	{
		m_particles.at(i).m_pressure = pressureConstant * powf(m_particles.at(i).m_density, 1 + (1 / polytropicIndex));
	}
}