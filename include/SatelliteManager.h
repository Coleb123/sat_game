#pragma once

#include <vector>
#include "Satellite.h"

class SatelliteManager
{
public:
    void Initialize();
    void Update(float dt);

    const std::vector<Satellite>& GetSatellites() const;

private:
    std::vector<Satellite> m_satellites;
};