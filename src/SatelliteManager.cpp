#include "SatelliteManager.h"

void SatelliteManager::Initialize()
{
    m_satellites.emplace_back(0.0f);
    m_satellites.emplace_back(90.0f);
    m_satellites.emplace_back(180.0f);
    m_satellites.emplace_back(270.0f);
}

void SatelliteManager::Update(float dt)
{
    for (auto& sat : m_satellites)
        sat.Update(dt);
}

const std::vector<Satellite>& SatelliteManager::GetSatellites() const
{
    return m_satellites;
}