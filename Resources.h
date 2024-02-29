#ifndef	RESOURCES_H
#define RESOURCES_H

#include "olcPixelGameEngine.h"

class Resources
{
	Resources();

public:
	static Resources& get()
	{
		static Resources res;
		return res;
	}

	Resources(Resources&&) = delete;
	Resources(const Resources&) = delete;
	Resources& operator=(const Resources&) = delete;
	Resources& operator=(Resources&&) = delete;

	olc::Renderable bronze_coin;
	olc::Renderable grenade;
};


#endif