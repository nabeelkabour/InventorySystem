#include "Helper.h"
#include <algorithm>

#define PI 3.14159f

float Lerp(const float& start, const float& end, float timer)
{
	return (end * timer) + start * (1.0f - timer);
}

float Helpers::median_3(float a, float b, float c)
{
    return std::max(std::min(a, b), std::min(std::max(a, b), c));
}

//float Helpers::turn_towards_direction(float angle, float target, float rate)
//{
//    float ang = angle;
//    ang += median_3(-rate, rate, angle_difference(target, angle));
//
//    return ang;
//}
float Helpers::turn_towards_direction(float angle, float target, float rate)
{
    float ang = angle;

    float diff = angle_difference(angle, target);
    ang += median_3(-rate, rate, diff);

    float newAngleDiff = angle_difference(ang, target);

    if (diff > 0 && newAngleDiff < 0 ||
        diff < 0 && newAngleDiff>0)return fmod(target, 2 * PI); //We have crossed the angle difference threshold and can safely say we reached it.

    return ang;
}

float Helpers::angle_difference(float angle_1, float angle_2)
{
    angle_1 = fmod(angle_1, 2 * PI);
    angle_2 = fmod(angle_2, 2 * PI);
    float angle_diff = angle_1 - angle_2;

    if (angle_diff > PI)
        angle_diff -= 2 * PI;
    else if (angle_diff < -PI)
        angle_diff += 2 * PI;

    return -angle_diff;
}