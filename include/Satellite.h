#pragma once

class Satellite
{
public:
    Satellite(float startAngle);
    void Update(float dt);

    float GetAngle() const;
    float GetBattery() const;

private:
    float m_angle;
    float m_speed;
    float m_battery;
    bool m_inSunlight;
};