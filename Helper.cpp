#include "Helper.h"

float Lerp(const float& start, const float& end, float timer)
{
	return (end * timer) + start * (1.0f - timer);
}