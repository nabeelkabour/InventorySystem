#ifndef HELPER_H
#define HELPER_H

#define PI 3.14159f

float Lerp(const float& start, const float& end, float timer);

namespace Helpers
{
	float turn_towards_direction(float, float, float);
	float median_3(float, float, float);
	float angle_difference(float, float);
}

#endif