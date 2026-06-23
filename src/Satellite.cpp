#include "Satellite.h"
#include <algorithm>

Satellite::Satellite(float startAngle)
{
    m_angle = startAngle;
    m_speed = 30.0f;
    m_battery = 100.0f;
    m_inSunlight = true;
}

void Satellite::Update(float dt)
{
    m_angle += m_speed * dt;

    if (m_angle >= 360.0f)
        m_angle -= 360.0f;

    m_inSunlight = (m_angle < 180.0f);

    if (m_inSunlight)
        m_battery += 5.0f * dt;
    else
        m_battery -= 3.0f * dt;

    m_battery = std::clamp(m_battery, 0.0f, 100.0f);
}

float Satellite::GetAngle() const { return m_angle; }
float Satellite::GetBattery() const { return m_battery; }